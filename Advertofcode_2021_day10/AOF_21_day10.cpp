#include<stdio.h>

//Basic character stack DS
char stack[100],stactSize,top=-1;
void push(char openBrace);
char pop();
void show();

int main()
{
    return 0;
}

//Stack functions
void push (char openBrace)
{
    if (top == stactSize )
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
