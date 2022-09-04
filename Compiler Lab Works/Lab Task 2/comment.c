#include<stdio.h>
#include<conio.h>
int main()
{
    char str[25];
    int i = 2, a = 0;
    printf("Enter input : ");
    gets(str);
    if(str[0] == '/')
    {
        if(str[1] == '/') {
            printf("It is a Comment");
        }
        else if(str[1] == '*')
        {
            for(i = 2; i <= 25; i++)
            {
                if(str[i] == '*' && str[i + 1] == '/')
                {
                    printf("It is a Comment.");
                    a = 1;
                    break;
                }
                else {
                    continue;
                }
            }
            if(a == 0)
            {
                printf("It is Not a Comment.");
            }
            else
            {
                printf("It is Not a Comment.");
            }
        }
    }
    else
    {
        printf("It is Not a Comment.");
    }
    return 0;
}


