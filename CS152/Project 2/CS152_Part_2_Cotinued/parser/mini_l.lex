
/* Variables */
%{
	#include "heading.h"
	#include "tok.h"

	int currLine = 1;
	int currPos = 1;
%}

/* Definitions */
DIGIT	[0-9]
ALPHA	[a-zA-Z]
UNDSC	[_]
COMME	[##]

/* Rules */
%%
"function"	{currPos += yyleng; return FUNCTION;}
"beginparams"	{currPos += yyleng; return BEGIN_PARAMS;}
"endparams"	{currPos += yyleng; return END_PARAMS;}
"beginlocals"	{currPos += yyleng; return BEGIN_LOCALS;}
"endlocals"	{currPos += yyleng; return END_LOCALS;}
"beginbody"	{currPos += yyleng; return BEGIN_BODY;}
"endbody"	{currPos += yyleng; return END_BODY;}
"integer"	{currPos += yyleng; return INTEGER;}
"array"		{currPos += yyleng; return ARRAY;}
"of"		{currPos += yyleng; return OF;}
"if"		{currPos += yyleng; return IF;}
"then"		{currPos += yyleng; return THEN;}
"endif"		{currPos += yyleng; return ENDIF;}
"else"		{currPos += yyleng; return ELSE;}
"while"		{currPos += yyleng; return WHILE;}
"do"		{currPos += yyleng; return DO;}
"foreach"	{currPos += yyleng; return FOREACH;}
"in"		{currPos += yyleng; return IN;}
"beginloop"	{currPos += yyleng; return BEGINLOOP;}
"endloop"	{currPos += yyleng; return ENDLOOP;}
"continue"	{currPos += yyleng; return CONTINUE;}
"read"		{currPos += yyleng; return READ;}
"write"		{currPos += yyleng; return WRITE;}
"and"		{currPos += yyleng; return AND;}
"or"		{currPos += yyleng; return OR;}
"not"		{currPos += yyleng; return NOT;}
"true"		{currPos += yyleng; return TRUE;}
"false"		{currPos += yyleng; return FALSE;}
"return"	{currPos += yyleng; return RETURN;}

"-"		{currPos += yyleng; return SUB;}
"+"		{currPos += yyleng; return ADD;}
"*"		{currPos += yyleng; return MULT;}
"/"		{currPos += yyleng; return DIV;}
"%"		{currPos += yyleng; return MOD;}

"=="		{currPos += yyleng; return EQ;}
"<>"		{currPos += yyleng; return NEQ;}
"<"		{currPos += yyleng; return LT;}
">"		{currPos += yyleng; return GT;}
"<="		{currPos += yyleng; return LTE;}
">="		{currPos += yyleng; return GTE;}

";"		{currPos += yyleng; return SEMICOLON;}
":"		{currPos += yyleng; return COLON;}
","		{currPos += yyleng; return COMMA;}
"("		{currPos += yyleng; return L_PAREN;}
")"		{currPos += yyleng; return R_PAREN;}
"["		{currPos += yyleng; return L_SQUARE_BRACKET;}
"]"		{currPos += yyleng; return R_SQUARE_BRACKET;}
":="		{currPos += yyleng; return ASSIGN;}

[ \t]+		{currPos += yyleng;}
"\n"		{currLine++; currPos = 1;}

{DIGIT}+						{currPos += yyleng; yylval.int_val = atoi(yytext); return NUMBER;}
{DIGIT}+({ALPHA}|{DIGIT}|{UNDSC})*			{printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); exit(1);}
{UNDSC}+({ALPHA}|{DIGIT}|{UNDSC})*			{printf("Error at line %d, column %d: identifier \"%s\" cannot begin with an underscore\n", currLine, currPos, yytext); exit(1);}
({ALPHA}|{DIGIT}|{UNDSC})*{UNDSC}+			{printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos, yytext); exit(1);}
{ALPHA}+({ALPHA}|{DIGIT}|{UNDSC})*({ALPHA}|{DIGIT})*	{currPos += yyleng; yylval.ident_val = yytext; return IDENT;}
{COMME}(.)*						{currLine++; currPos = 1;}
.							{printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(2);}
%%
