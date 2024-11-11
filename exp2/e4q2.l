%{
#include <stdio.h>
%}

%%
[A-Z] printf("Capital letter: %s\\n", yytext);
[a-z] printf("Lowercase letter\\n");
. printf("Invalid character\\n");
%%

int main() {
    yylex();
    return 0;
}
