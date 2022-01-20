#include<stdio.h>

//Basic character stack DS
char stack[1000];
int stackSize,top=-1;
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

    bool mismatch = false;

    printf("Enter sequence \n");
    stackSize = 998;

    while(true)
    {
        printf(" new line\n");
        scanf("%c",&cEachChar);
        mismatch = false;
        top = -1;
        while (cEachChar != '\n') 
        {
            if(!mismatch)
            {
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
                            {
                                //printf("\nproperly closed\n");
                            }
                            else
                            {
                                printf("\nnot proper: ]\n");
                                totalCount += point_square;
                                mismatch = true;
                            }
                        }
                        break;
                        case '}':
                        {
                            if(closeBraceFromStack == '{')
                            {
                                //printf("\nproperly closed\n");
                            }
                            else
                            {
                                printf("\nnot proper: }\n");
                                totalCount += point_flower;
                                mismatch = true;
                            }
                        }
                        break;
                        case ')':
                        {
                            if(closeBraceFromStack == '(')
                            {
                                //printf("\nproperly closed\n");
                            }
                            else
                            {
                                printf("\nnot proper: )\n");
                                totalCount += point_curve;
                                mismatch = true;
                            }
                        }
                        break;
                        case '>':
                        {
                            if(closeBraceFromStack == '<')
                            {
                                //printf("\nproperly closed\n");
                            }
                            else
                            {
                                printf("\nnot proper: >\n");
                                totalCount += point_greater;
                                mismatch = true;
                            }
                        }
                        break;
                    }
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
