%{
	//Lex program to take input from file and remove multiple spaces, newline and tab and write output in a separate file//
	#include<stdio.h>
	int sp=0,n=0,t=0,s = 0, nl = 0;
%}
space " "
%%
\n {if (!nl) {
        fprintf(yyout, "\n");
        nl = 1;
    }
    else
        fprintf(yyout, ""); 
		n++;};
\t {fprintf(yyout, ""); t++;};
{space} {
    if (!s) {
        fprintf(yyout, " ");
        s = 1;
    }
    else
        fprintf(yyout, "");
        sp++;
};
. {fprintf(yyout, "%s", yytext);s=0;nl=0;};

%%
int main()
{
char file1[10];
char file2[10];
printf("Plese Enter your input file name  :- ");
scanf("%s",file1);
printf("Plese Enter your output file name  :- ");
scanf("%s",file2);
yyin=fopen(file1,"r");
yyout = fopen("output.txt", "w");
yylex();
fclose(yyin);

}
int yywrap(void)
{
    return 1;
}

