#include<stdio.h>

//Basic character stack DS
char stack[100],stackSize,top=-1;
void push(char openBrace);
char pop();
void show();

int main()
{
    char cEachChar;
    printf("Enter sequence \n");
    stackSize = 98;
    scanf("%c",&cEachChar);
    while (cEachChar != '\n') {
      if(cEachChar == '[' || cEachChar == '{' || cEachChar == '('|| cEachChar == '<')
      {
          push(cEachChar);
      }
      else
      {
      }
      scanf("%c",&cEachChar);
    }
    show();
    return 0;
}

//Stack functions
void push (char openBrace)
{
    if (top == stackSize )
    printf("\n Overflow");
    else
    {
        top = top +1;
        stack[top] = openBrace;
    }
}

char pop ()
{
    char brace;
    if(top == -1)
    printf("Underflow");
    else
    {
      brace = stack[top];
      top = top -1;
    }
    return brace;
}

void show()
{
    int i;
    for (i=top;i>=0;i--)
    {
        printf("%c\n",stack[i]);
    }
    if(top == -1)
    {
        printf("Stack is empty");
    }
}
