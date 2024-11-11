%{
#include "y.tab.h" // Include Yacc header for token definitions
%}
%%
[ \t]      { /* skip blanks and tabs */ } 
\n|.       { return yytext[0]; }
%%

