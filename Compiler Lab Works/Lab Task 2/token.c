#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}


bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}


bool validIdentifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}


bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
)
        return (true);
    return (false);
}


bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}




char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
                  sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}


void detectToken(char* data)
{
    int left = 0, right = 0;
    int len = strlen(data);

    while (right <= len && left <= right) {
        if (isDelimiter(data[right]) == false)
            right++;

        if (isDelimiter(data[right]) == true && left == right)
            {
            if (isOperator(data[right]) == true)
                printf("'%c' IS AN OPERATOR\n", data[right]);
            right++;
            left = right;
            }
        else if (isDelimiter(data[right]) == true && left != right || (right == len && left != right))

        {
            char* subStr = subString(data, left, right - 1);

            if (isKeyword(subStr) == true)
            printf("'%s' IS A KEYWORD\n", subStr);

            else if (isInteger(subStr) == true)
            printf("'%s' IS AN INTEGER\n", subStr);


            else if (validIdentifier(subStr) == true && isDelimiter(data[right - 1]) == false)
            printf("'%s' IS A VALID IDENTIFIER\n", subStr);

            else if (validIdentifier(subStr) == false && isDelimiter(data[right - 1]) == false)
            printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }

}


int main()
{

    char data[100];
    FILE *fp;
    printf("Opening the file\n");
    fp = fopen( "token.txt", "r" ) ;
    if ( fp == NULL )
      {
        printf( "Could not open file token.txt\n" ) ;
        return 1;
    }
    printf( "Reading the file token.txt\n" ) ;
    while( fgets ( data, 100, fp ) != NULL )
    printf( "%s \n" , data) ;
    detectToken(data);
    fclose(fp) ;

    return (0);
}
