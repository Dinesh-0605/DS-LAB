#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
struct stack{
    int top;
    char data[SIZE];
} ;
typedef struct stack STACK;
void push(STACK *s,char item)
{
    s->data[++(s->top)]=item;
}
char pop(STACK *s)
{
    return(s->data[(s->top)--]);
}
int balparcheck(STACK *s,char expr[20])
{
    int i,flag=1;
    char temp,symbol;
    for(i=0;expr[i]!='\0';i++)
    {
        symbol=expr[i];
        if(symbol=='('||symbol=='['||symbol=='{')
            push(s,symbol);
        else
        {
            if(s->top==-1)
                flag=0;
            else
            {
                temp=pop(s);
                if(symbol==')'&&(temp=='['||temp=='{'))
                    flag=0;
                if(symbol==']'&&(temp=='('||temp=='{'))
                    flag=0;
                if(symbol=='}'&&(temp=='('||temp=='['))
                    flag=0;
            }
        }
    }
    if(s->top!=-1)
        flag=0;
    return flag;
}
int main()
{
    STACK s;
    s.top=-1;
    int n;
    char expr[20];
    printf("\nEnter the set of paranthesis:\n");
    scanf("%s",expr);
    n=balparcheck(&s,expr);
    if(n==1)
    {
        printf("\nParanthesis are equal\n");
        return 0;
    }
    printf("\nParanthesis are not equal\n");
    return 0;
}
