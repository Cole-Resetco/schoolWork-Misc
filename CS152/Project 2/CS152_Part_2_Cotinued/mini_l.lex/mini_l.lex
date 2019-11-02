   

%{
   #include "tok.h"
   int currLine = 1, currPos = 1;
   int numNumbers = 0;
   int numOperators = 0;
   int numSpecSym = 0;
   int numCompOps = 0;
   int reservedWords = 0;
%}

DIGIT    [0-9]
ULETTER  [A-Z]
LLETTER  [a-z]
   
%%

"function" 	{currPos += yyleng; reservedWords++; return FUNCTION;} 
"beginparams" 	{currPos += yyleng; reservedWords++; return BEGIN_PARAMS;}
"endparams" 	{currPos += yyleng; reservedWords++; return END_PARAMS;} 
"beginlocals" 	{currPos += yyleng; reservedWords++; return BEGIN_LOCALS;} 
"endbody" 	{currPos += yyleng; reservedWords++; return END_BODY;} 
"array" 	{currPos += yyleng; reservedWords++; return ARRAY;}
"integer" 	{currPos += yyleng; reservedWords++; return INTEGER;}
"of"	 	{currPos += yyleng; reservedWords++; return OF;} 
"if" 		{currPos += yyleng; reservedWords++; return IF;} 
"then" 		{currPos += yyleng; reservedWords++; return THEN;} 
"endif" 	{currPos += yyleng; reservedWords++; return ENDIF;}
"else" 		{currPos += yyleng; reservedWords++; return ELSE;} 
"while" 	{currPos += yyleng; reservedWords++; return WHILE;}
"do"	 	{currPos += yyleng; reservedWords++; return DO;}
"beginloop"	{currPos += yyleng; reservedWords++; return BEGINLOOP;}
"endloop" 	{currPos += yyleng; reservedWords++; return ENDLOOP;}
"continue" 	{currPos += yyleng; reservedWords++; return CONTINUE;}
"read" 		{currPos += yyleng; reservedWords++; return READ;}
"write" 	{currPos += yyleng; reservedWords++; return WRITE;}
"and"	 	{currPos += yyleng; reservedWords++; return AND;}
"or" 		{currPos += yyleng; reservedWords++; return OF;}
"not"	 	{currPos += yyleng; reservedWords++; return NOT;}
"true"	 	{currPos += yyleng; reservedWords++; return TRUE;}
"false" 	{currPos += yyleng; reservedWords++; return FALSE;}
"return" 	{currPos += yyleng; reservedWords++; return RETURN;}

"-"            {currPos += yyleng; numOperators++; return SUB;}
"+"            {currPos += yyleng; numOperators++; return ADD;}
"*"            {currPos += yyleng; numOperators++; return MULT;}
"/"            {currPos += yyleng; numOperators++; return DIV;}
"%"	       {currPos += yyleng; numOperators++; return MOD;}

"=="           {currPos += yyleng; numCompOps++; return EQ;}
"<>"           {currPos += yyleng; numCompOps++; return NEQ;}
"<"            {currPos += yyleng; numCompOps++; return LT;}
">"            {currPos += yyleng; numCompOps++; return GT;}
"<="           {currPos += yyleng; numCompOps++; return LTE;}
">="           {currPos += yyleng; numCompOps++; return GTE;}


"("            {currPos += yyleng; numSpecSym++; return L_PAREN;}
")"            {currPos += yyleng; numSpecSym++; return R_PAREN;}
";"            {currPos += yyleng; numSpecSym++; return SEMICOLON;}
":"            {currPos += yyleng; numSpecSym++; return COLON;}
","            {currPos += yyleng; numSpecSym++; return COMMA;}
"["            {currPos += yyleng; numSpecSym++; return L_SQUARE_BRACKET;}
"]"            {currPos += yyleng; numSpecSym++; return R_SQUARE_BRACKET;}
":="           {currPos += yyleng; numSpecSym++; return ASSIGN;}


("##")+(.)*	       								{currLine++; currPos = 1;}

(({ULETTER}|{LLETTER})*("_")+)							{printf("Error at line %d, column %d: Identifier \"%s\" Cannot end with an Underscore\n", currLine, currPos, yytext);}

(({DIGIT})+({LLETTER}|{ULETTER})+(.)+)						{printf("Error at line %d, column %d: Identifier \"%s\" Must begin with a Letter\n", currLine, currPos, yytext);}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?)   			{currPos += yyleng; numNumbers++; return NUMBER;}
	
(({ULETTER}|{LLETTER})+({DIGIT}|{ULETTER}|{LLETTER})*)  			{currPos += yyleng; return IDENT;}

(({ULETTER}|{LLETTER}|"_")+({DIGIT}|{ULETTER}|{LLETTER}|"_")*({DIGIT}|{ULETTER}|{LLETTER})+)  {currPos += yyleng; return IDENT;}

[ \t]+         									{/* ignore spaces */ currPos += yyleng;}

"\n"          								 	{currLine++; currPos = 1;}

.              									{printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext);}

%%
