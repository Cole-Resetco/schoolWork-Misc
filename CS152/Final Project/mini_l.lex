   

%{
   #include "tok.h"
   int currLine = 1, currPos = 1;
   int numNumbers = 0;
   int numOperators = 0;
   int numSpecSym = 0;
   int numCompOps = 0;
   int reservedWords = 0;
%}

%option noyywrap

DIGIT    [0-9]
ULETTER  [A-Z]
LLETTER  [a-z]
   
%%

"function" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return FUNCTION;} 
"beginparams" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return BEGIN_PARAMS;}
"endparams" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return END_PARAMS;} 
"beginlocals" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return BEGIN_LOCALS;} 
"endlocals"	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return END_LOCALS;}
"beginbody"	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return BEGIN_BODY;}
"endbody" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return END_BODY;} 
"array" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return ARRAY;}
"integer" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return INTEGER;}
"of"	 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return OF;} 
"if" 		{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return IF;} 
"then" 		{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return THEN;} 
"endif" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return ENDIF;}
"else" 		{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return ELSE;} 
"while" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return WHILE;}
"do"	 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return DO;}
"beginloop"	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return BEGINLOOP;}
"in"		{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return IN;}
"foreach"	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return FOREACH;}
"endloop" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return ENDLOOP;}
"continue" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return CONTINUE;}
"read" 		{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return READ;}
"write" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return WRITE;}
"and"	 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return AND;}
"or" 		{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return OR;}
"not"	 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return NOT;}
"true"	 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return TRUE;}
"false" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return FALSE;}
"return" 	{currPos += yyleng; reservedWords++; yylval.ident_val = yytext; return RETURN;}

"-"            {currPos += yyleng; numOperators++; yylval.ident_val = yytext; return SUB;}
"+"            {currPos += yyleng; numOperators++; yylval.ident_val = yytext; return ADD;}
"*"            {currPos += yyleng; numOperators++; yylval.ident_val = yytext; return MULT;}
"/"            {currPos += yyleng; numOperators++; yylval.ident_val = yytext; return DIV;}
"%"	       {currPos += yyleng; numOperators++; yylval.ident_val = yytext; return MOD;}

"=="           {currPos += yyleng; numCompOps++; return EQ;}
"<>"           {currPos += yyleng; numCompOps++; return NEQ;}
"<"            {currPos += yyleng; numCompOps++; return LT;}
">"            {currPos += yyleng; numCompOps++; return GT;}
"<="           {currPos += yyleng; numCompOps++; return LTE;}
">="           {currPos += yyleng; numCompOps++; return GTE;}


"("            {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return L_PAREN;}
")"            {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return R_PAREN;}
";"            {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return SEMICOLON;}
":"            {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return COLON;}
","            {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return COMMA;}
"["            {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return L_SQUARE_BRACKET;}
"]"            {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return R_SQUARE_BRACKET;}
":="           {currPos += yyleng; numSpecSym++; yylval.ident_val = yytext; return ASSIGN;}

[ \t]+         									{/* ignore spaces */ currPos += yyleng;}

"\n"          								 	{currLine++; currPos = 1;}

("##")+(.)*	       								{currLine++; currPos = 1;}



{DIGIT}+																				{currPos += yyleng; yylval.ident_val = yytext; return NUMBER;}
{DIGIT}+({ULETTER}|{LLETTER}|{DIGIT}|"_")*												{printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); exit(1);}
"_"+({ULETTER}|{LLETTER}|{DIGIT}|"_")*													{printf("Error at line %d, column %d: identifier \"%s\" cannot begin with an underscore\n", currLine, currPos, yytext); exit(1);}
({ULETTER}|{LLETTER}|{DIGIT}|"_")*"_"+													{printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos, yytext); exit(1);}
({ULETTER}|{LLETTER})+({ULETTER}|{LLETTER}|{DIGIT}|"_")*({ULETTER}|{LLETTER}|{DIGIT})*	{currPos += yyleng; yylval.ident_val = strdup(yytext); printf(yytext); printf("              "); return IDENT;}		



.              									{printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext);}

%%
/*

(({ULETTER}|{LLETTER})*("_")+)							{printf("Error at line %d, column %d: Identifier \"%s\" Cannot end with an Underscore\n", currLine, currPos, yytext);}

(({DIGIT})+({LLETTER}|{ULETTER})+(.)+)						{printf("Error at line %d, column %d: Identifier \"%s\" Must begin with a Letter\n", currLine, currPos, yytext);}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?)   			{currPos += yyleng; numNumbers++; return NUMBER;}
	
(({ULETTER}|{LLETTER})+({DIGIT}|{ULETTER}|{LLETTER}|"_")*({DIGIT}|{ULETTER}|{LLETTER})*)  			{currPos += yyleng; return IDENT;}

(({ULETTER}|{LLETTER}|"_")+({DIGIT}|{ULETTER}|{LLETTER}|"_")*({DIGIT}|{ULETTER}|{LLETTER})+)  {currPos += yyleng; return IDENT;}
		{currPos += yyleng; yylval
		

*/
