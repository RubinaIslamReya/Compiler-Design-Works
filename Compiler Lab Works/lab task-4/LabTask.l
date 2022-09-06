%{ 
int n = 0 ;
int i=0;
int o=0; 
int in=0;
int line_no= 0;

%}

%%
"int" {n++;printf("\n keywords : %s", yytext);} 
"this" {n++;printf("\n keywords : %s", yytext);} 
"<="|"=="|"="|"++"|"-"|"*"|"+"|"."|";" {o++;printf("\n operator : %s", yytext);}
[0-9][a-zA-Z_][_a-zA-Z0-9_]* {in++;printf("\n invaild : %s", yytext);}
[a-zA-Z_][_a-zA-Z0-9]* {i++;printf("\n identifier : %s", yytext);}
[a-zA-Z"!"|"@"|"#"|"%"|"&"]["!"|"@"|"#"|"%"|"&"a-zA-Z0-9]* {in++;printf("\n invalid : %s", yytext);}

\n  ++line_no;


. ;
%%
int yywrap()
{
return 1;
}
int main()
{
FILE *fp; 
char filename[50]; 
printf("Enter the filename: \n"); 
scanf("%s",filename); 
fp = fopen(filename,"r"); 

yyin = fp; 
 yylex();
 printf("\n");
 printf("\n Line number = %d\n", line_no);
 printf("\n Number of identifire/word  = %d\n", i);

 return 0;
}