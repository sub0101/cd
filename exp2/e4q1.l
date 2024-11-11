%{
#include <stdio.h>
%}

%%
[aeiouAEIOU] printf("Vowel\\n");
[a-zA-Z] printf("Not a vowel\\n");
. printf("Invalid input\\n");
%%

int main() {
    yylex();
    return 0;
}
