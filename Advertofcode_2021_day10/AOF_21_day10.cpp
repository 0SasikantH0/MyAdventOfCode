#include<stdio.h>

//Basic character stack DS
char stack[100],stackSize,top=-1;
void push(char openBrace);
char pop();
void show();

int main()
{
    char cEachChar;
    char closeBraceFromStack;

    int lineCount = 0;
    int totalCount = 0;
    int point_curve = 3, point_square = 57, point_flower = 1197, point_greater = 25137;

    printf("Enter sequence \n");
    stackSize = 98;

    while(true)
    {
        printf("\n");
        scanf("%c",&cEachChar);
        while (cEachChar != '\n') {
        if(cEachChar == '[' || cEachChar == '{' || cEachChar == '('|| cEachChar == '<')
        {
            push(cEachChar);
        }
        else
        {
            closeBraceFromStack = pop();
            switch(cEachChar)
            {
                case ']':
                {
                if(closeBraceFromStack == '[')
                    printf("properly closed\n");
                else
                {
                    printf("not proper: ]\n");
                    totalCount += point_square;
                }
                }
                break;
                case '}':
                {
                if(closeBraceFromStack == '{')
                    printf("properly closed\n");
                else
                {
                    printf("not proper: }\n");
                    totalCount += point_flower;
                }
                }
                break;
                case ')':
                {
                if(closeBraceFromStack == '(')
                    printf("properly closed\n");
                else
                {
                    printf("not proper: )\n");
                    totalCount += point_curve;
                }
                }
                break;
                case '>':
                {
                if(closeBraceFromStack == '<')
                    printf("properly closed\n");
                else
                {
                    printf("not proper: >\n");
                    totalCount += point_greater;
                }
                }
                break;
            }
        }
        scanf("%c",&cEachChar);
        }
        printf("total points till now: %d\n", totalCount);
    }
 
    //show();
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
