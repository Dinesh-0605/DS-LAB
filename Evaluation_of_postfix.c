#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack  STACK;
void push(STACK *s,char item)
{
    s->data[++(s->top)]=item;

}
char pop(STACK *s)
{
    return(s->data[(s->top)--]);
}
float compute(float opr1,char symbol,float opr2)
{
    switch(symbol){
    case '+':return opr1+opr2;
    case '-':return opr1-opr2;
    case '*':return opr1*opr2;
    case '/':return opr1/opr2;
    case '^':return pow(opr1,opr2);
    }
}
float evaluatepostfix(STACK *s,char postfix[20])
{
    int i;
    char symbol;
    float opr1,opr2,res;
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            push(s,(symbol-'0'));
        else{
            opr2=pop(s);
            opr1=pop(s);
            res=compute(opr1,symbol,opr2);
            push(s,res);
        }
    }
    return(pop(s));
}
int main()
{
    char postfix[20];
    STACK s;
    float ans;
    s.top=-1;
    printf("\nRead Postfix Expression:\n");
    scanf("%s",postfix);
    ans=evaluatepostfix(&s,postfix);
    printf("\nThe final result is:%f\n",ans);
    return 0;
}

