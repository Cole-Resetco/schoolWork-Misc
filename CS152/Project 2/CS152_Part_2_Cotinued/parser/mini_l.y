/* CS152 Project Phase 2: Parser Generation
   Alan Carabes : acara003@ucr.edu
   Jason Liaw	: jliaw001@ucr.edu
   mini_l.y
*/

// C Declarations
%{
  #include "heading.h"
  int yylex(void);
  int yyerror(char* s);
%}

// Bison Declarations
%union{
  int int_val;
  char* ident_val;
}

%start program

%token <int_val> NUMBER
%token <ident_val> IDENT
%token FUNCTION
%token BEGIN_PARAMS
%token END_PARAMS
%token BEGIN_LOCALS
%token END_LOCALS
%token BEGIN_BODY
%token END_BODY
%token INTEGER
%token ARRAY
%token OF
%token IF
%token THEN
%token ENDIF
%token ELSE
%token WHILE
%token DO
%token FOREACH
%token IN
%token BEGINLOOP
%token ENDLOOP
%token CONTINUE
%token READ
%token WRITE
%token AND
%token OR
%token TRUE
%token FALSE
%token RETURN
%token SEMICOLON
%token COLON
%token COMMA

%left SUB
%left ADD
%left MULT
%left DIV
%left MOD

%left EQ
%left NEQ
%left LT
%left GT
%left LTE
%left GTE

%left L_PAREN
%left R_PAREN
%left L_SQUARE_BRACKET
%left R_SQUARE_BRACKET

%right NOT
%right ASSIGN

// Grammar Declarations
%%
  program:				begin_program 
						{cout << "program -> begin_program" << endl;}
  
  begin_program: 		function begin_program
						{cout << "begin_program -> function begin_program" << endl;} 
						| 
						/* Epsilon */ 
						{cout << "begin_program -> epsilon" << endl;}
					
  function:				FUNCTION IDENT SEMICOLON BEGIN_PARAMS declaration_list 
						END_PARAMS BEGIN_LOCALS declaration_list 
						END_LOCALS BEGIN_BODY statement_list END_BODY
						{
						cout << "function -> FUNCTION IDENT " << *($2) << " SEMICOLON BEGIN_PARAMS " << 
									"declaration_list END_LOCALS BEGIN_BODY statement_list END_BODY" << endl;
						}
  
  declaration_list: 	declaration SEMICOLON declaration_list 
						{cout << "declaration_list -> declaration SEMICOLON declaration_list" << endl;}
						| 
						/* Epsilon */
						{cout << "declaration_list -> epsilon" << endl;}
  
  statement_list:		statement SEMICOLON statement_list
						{cout << "statement_list -> statement SEMICOLON statement_list" << endl;}
						| 
						/* Epsilon */
						{cout << "statement_list -> epsilon" << endl;}
  
  declaration:			IDENT ident_list
						{cout << "declaration -> IDENT " << *($1) << " ident_list" << endl;}
					
  ident_list:			COMMA IDENT ident_list
						{cout << "ident_list -> COMMA IDENT " << *($2) << " ident_list" << endl;}
						|
						COLON ident_rhs
						{cout << "ident_list -> COLON ident_rhs" << endl;}
					
  ident_rhs:			INTEGER
						{cout << "ident_rhs -> INTEGER" << endl;}
						|
						ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
						{cout << "ident_rhs -> ARRAY L_SQUARE_BRACKET NUMBER " << $3 << " R_SQUARE_BRACKET OF INTEGER" << endl;}
  
  statement:			var ASSIGN expression
						{cout << "statement -> var ASSIGN expression" << endl;}
						|
						IF bool-expr THEN statement SEMICOLON if_loop
						{cout << "statement -> IF bool-expr THEN statement SEMICOLON if_loop" << endl;}
						|
						WHILE bool-expr BEGINLOOP statement SEMICOLON statement_loop
						{cout << "statement -> WHILE bool-expr BEGINLOOP statement SEMICOLON statement_loop" << endl;}
						|
						DO BEGINLOOP statement SEMICOLON statement_loop WHILE bool-expr
						{cout << "statement -> DO BEGINLOOP statement SEMICOLON statement_loop WHILE bool-expr" << endl;}
						|
						FOREACH IDENT IN IDENT BEGINLOOP statement_loop
						{cout << "statement -> FOREACH IDENT " << *($2) << " IN IDENT " << *($4) << " BEGINLOOP statement_loop" << endl;}
						|
						READ var_list
						{cout << "statement -> READ var_list" << endl;}
						|
						WRITE var_list
						{cout << "statement -> WRITE var_list" << endl;}
						|
						CONTINUE
						{cout << "statement -> CONTINUE" << endl;}
						|
						RETURN expression
						{cout << "statement -> RETURN expression" << endl;}
					
  if_loop:				ENDIF
						{cout << "if_loop -> ENDIF" << endl;}
						|
						statement SEMICOLON if_loop
						{cout << "if_loop -> statement SEMICOLON if_loop" << endl;}
						|
						ELSE statement SEMICOLON ifelse_loop
						{cout << "if_loop -> ELSE statement SEMICOLON ifelse_loop" << endl;}
  
  ifelse_loop:			ENDIF
						{cout << "ifelse_loop -> ENDIF" << endl;}
						|
						statement SEMICOLON ifelse_loop
						{cout << "ifelse_loop -> statement SEMICOLON ifelse_loop" << endl;}
  
  statement_loop:		ENDLOOP
						{cout << "statement_loop -> ENDLOOP" << endl;}
						|
						statement SEMICOLON statement_loop
						{cout << "statement_loop -> statement SEMICOLON statement_loop" << endl;}

  var_list:				var
						{cout << "var_list -> var" << endl;}
						|
						var COMMA var_list
						{cout << "var_list -> var COMMA var_list" << endl;}
  
  bool-expr:			relation-and-expr more-bool
						{cout << "bool-expr -> relation-and-expr more-bool" << endl;}
  
  more-bool:			OR relation-and-expr more-bool
						{cout << "more-bool -> OR relation-and-expr more-bool" << endl;}
						|
						/* Epsilon */
						{cout << "more-bool -> epsilon" << endl;}
  
  relation-and-expr:	relation-expr more-expr
						{cout << "relation-and-expr -> relation-expr more-expr" << endl;}
  
  more-expr:			AND relation-expr more-expr
						{cout << "more-expr -> AND relation-expr more-expr" << endl;}
						|
						/* Epsilon */
						{cout << "more-expr -> epsilon" << endl;}
  
  relation-expr:		NOT relation-cont
						{cout << "relation-expr -> NOT relation-cont" << endl;}
						|
						relation-cont
						{cout << "relation-expr -> relation-cont" << endl;}
  
  relation-cont:		expression comp expression
						{cout << "relation-cont -> expression comp expression" << endl;}
						|
						TRUE
						{cout << "relation-cont -> TRUE" << endl;}
						|
						FALSE
						{cout << "relation-cont -> FALSE" << endl;}
						|
						L_PAREN bool-expr R_PAREN
						{cout << "relation-cont -> L_PAREN bool-expr R_PAREN" << endl;}
  
  comp:					EQ
						{cout << "comp -> EQ" << endl;}
						|
						NEQ
						{cout << "comp -> NEQ" << endl;}
						|
						LT
						{cout << "comp -> LT" << endl;}
						|
						GT
						{cout << "comp -> GT" << endl;}
						|
						LTE
						{cout << "comp -> LTE" << endl;}
						|
						GTE
						{cout << "comp -> GTE" << endl;}
  
  expression:			multiplicative-expr expr_arith
						{cout << "expression -> multiplicative-expr expr_arith" << endl;}
  
  expr_arith:			ADD multiplicative-expr expr_arith
						{cout << "expr_arith -> ADD multiplicative-expr expr_arith" << endl;}
						|
						SUB multiplicative-expr expr_arith
						{cout << "expr_arith -> SUB multiplicative-expr expr_arith" << endl;}
						|
						/* Epsilon */
						{cout << "expr_arith -> epsilon" << endl;}
  
  multiplicative-expr:	term multterms
						{cout << "multiplciative-expr -> term multterms" << endl;}
  
  multterms:			MULT term multterms
						{cout << "multterms -> MULT term multterms" << endl;}
						|
						DIV term multterms
						{cout << "multterms -> DIV term multterms" << endl;}
						|
						MOD term multterms
						{cout << "multterms -> MOD term multterms" << endl;}
						|
						/* Epsilon */
						{cout << "multterms -> epsilon" << endl;}
  
  term:					SUB termA
						{cout << "term -> SUB termA" << endl;}
						|
						termA
						{cout << "term -> termA" << endl;}
						|
						termB
						{cout << "term -> termB" << endl;}
  
  termA:				var
						{cout << "termA -> var" << endl;}
						|
						NUMBER
						{cout << "termA -> NUMBER " << $1 << endl;}
						|
						L_PAREN expression R_PAREN
						{cout << "termA -> L_PAREN expression R_PAREN" << endl;}
  
  termB:				IDENT L_PAREN term_param R_PAREN
						{cout << "termB -> IDENT " << *($1) << " L_PAREN term_param R_PAREN" << endl;}
  
  term_param:			expression
						{cout << "term_param -> expression" << endl;}
						|
						expression COMMA term_param
						{cout << "term_param -> expression COMMA term_param" << endl;}
						|
						/* Epsilon */
						{cout << "term_param -> epsilon" << endl;}
  
  var:					IDENT
						{cout << "var -> IDENT " << *($1) << endl;}
						|
						IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
						{cout << "var -> IDENT " << *($1) << " L_SQUARE_BRACKET expression R_SQUARE_BRACKET" << endl;}
%%

// Additional C Code
int yyerror(string s)
{
  extern int currLine;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << currLine << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}
