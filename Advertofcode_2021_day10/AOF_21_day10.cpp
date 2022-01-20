#include<stdio.h>

//Basic character stack DS
char stack[1000];
int stackSize,top=-1;
int push(char openBrace);
char pop();
void show();

int main()
{
    char cEachChar;
    char closeBraceFromStack;
    char openBraceFromStack;

    int lineCount = 0;
    int totalCount = 0;
    int totalOpenCount = 0;
    int point_curve = 3, point_square = 57, point_flower = 1197, point_greater = 25137;
    int point_curve_2 = 1, point_square_2 = 2, point_flower_2 = 3, point_greater_2 = 4;

    int pointArray[100];

    bool mismatch = false;

    printf("Enter sequence \n");
    stackSize = 998;

    do
    {
        printf(" new line\n");
        scanf("%c",&cEachChar);
        if(cEachChar == '#')
        {
            break;
        }
        mismatch = false;
        lineCount = 0;
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
        //printf("total points till now: %d\n", totalCount);
        if(!mismatch)
        {
            printf("\n it is incomplete\n");
            totalOpenCount = 0;
            openBraceFromStack = pop();
            while(openBraceFromStack != '\0')
            {
                totalOpenCount *= 5;
                switch(openBraceFromStack)
                {
                    case '[':
                    {
                        //printf("\nnot proper: ]\n");
                        totalOpenCount += point_square_2;
                    }
                    break;
                    case '{':
                    {
                        //printf("\nnot proper: }\n");
                        totalOpenCount += point_flower_2;
                    
                    }
                    break;
                    case '(':
                    {
                        //printf("\nnot proper: )\n");
                        totalOpenCount += point_curve_2;
                    
                    }
                    break;
                    case '<':
                    {
                        //printf("\nnot proper: >\n");
                        totalOpenCount += point_greater_2;
                        
                    }
                    break;
                }
                openBraceFromStack = pop();
            }
            printf("total: %d", totalOpenCount);
            pointArray[lineCount] = totalOpenCount;
            lineCount++;
        }
    }while(true);
    //show();
    
    return 0;
}

//Stack functions
int push (char openBrace)
{
    if (top == stackSize )
    {
        return -1;
    }
    else
    {
        top = top +1;
        stack[top] = openBrace;
    }
    return 0;
}

char pop ()
{
    char brace;
    if(top == -1)
    return '\0';
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
