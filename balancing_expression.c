//Balancing expression
#include<stdio.h>
char stack[100];
int top=-1;
void push(char x)
{
  stack[++top]=x;
}
void main()
{
  char exp[80],x;
  int i;
  printf("\nEnter any expression");
  scanf("%s",exp);
  for(i=0;exp[i]!='\0';i++)
  {
    x=exp[i];
    if(x>='A' && x<='Z'||x>='a' && x<='z'||x>='0' && x<='9' ||x=='+' ||x=='-'||x=='*'||x=='/'||x=='%')
    continue;
    else if(x=='(' ||x=='['||x=='{')
    push(x);
    else if(x==')' && stack[top]=='('||x=='}' && stack[top]=='{' ||x==']' && stack[top]=='[')
    top--;
    else
    {
      printf("\nInvalid");
    }
  }
  if(top==-1)
  printf("\nValid");
}
