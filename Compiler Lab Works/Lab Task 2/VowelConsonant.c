#include <stdio.h>

int main()
{
  	char str[100];
  	int i, vowels, consonants;
  	vowels = consonants = 0;

  	printf("Please Enter String :  ");
  	gets(str);

  	for(i = 0; str[i] != '\0'; i++)
  	{
  		if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )
		{
			switch(str[i])
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					vowels++;
					break;
				default:
					consonants++;
    		}
    	}
	}
    printf(" Number of Vowels in String = %d", vowels);
	printf("\n Number of Consonants in String = %d", consonants);

  	return 0;
}
