%{
  #include "heading.h"
  #include <stdlib.h>
  #include <cstdlib>
  int yylex(void);
  int yyerror(char* s);


  fstream fout;
  void openFile();
  int open = 0;
  int paramCount = 0;
  int labelCount = 0;
  int tempCount = 0;


%}

%union{
  int int_val;
  const char* ident_val;
}

%start program

%token <ident_val> NUMBER
%token <ident_val> IDENT
%token <ident_val> FUNCTION
%token <ident_val> BEGIN_PARAMS
%token <ident_val> END_PARAMS
%token <ident_val> BEGIN_LOCALS
%token <ident_val> END_LOCALS
%token <ident_val> BEGIN_BODY
%token <ident_val> END_BODY
%token <ident_val> INTEGER
%token <ident_val> ARRAY
%token <ident_val> OF
%token <ident_val> IF
%token <ident_val> THEN
%token <ident_val> ENDIF
%token <ident_val> ELSE
%token <ident_val> WHILE
%token <ident_val> DO
%token <ident_val> FOREACH
%token <ident_val> IN
%token <ident_val> BEGINLOOP
%token <ident_val> ENDLOOP
%token <ident_val> CONTINUE
%token <ident_val> READ
%token <ident_val> WRITE
%token <ident_val> AND
%token <ident_val> OR
%token <ident_val> TRUE
%token <ident_val> FALSE
%token <ident_val> RETURN
%token <ident_val> SEMICOLON
%token <ident_val> COLON
%token <ident_val> COMMA

%left <ident_val> SUB
%left <ident_val> ADD
%left <ident_val> MULT
%left <ident_val> DIV
%left <ident_val> MOD

%left <ident_val> EQ
%left <ident_val> NEQ
%left <ident_val> LT
%left <ident_val> GT
%left <ident_val> LTE
%left <ident_val> GTE
%left <ident_val> L_PAREN
%left <ident_val> R_PAREN
%left <ident_val> L_SQUARE_BRACKET
%left <ident_val> R_SQUARE_BRACKET

%right <ident_val> NOT
%right <ident_val> ASSIGN

%type <ident_val> comp var bool-expr statement relation-and-expr relation-expr relation-rhs expr_arith term multterms termA termB term_param expression multiplicative-expr 

%%
  program:				begin_program 
						{
							cout << "program -> begin_program" << endl;
						}
  
  begin_program: 		function begin_program
						{
							cout << "begin_program -> function begin_program" << endl;
						} 
						| 
						/* EMPTY */ 
						{
							cout << "begin_program -> EMPTY" << endl;
						}
  function:				FUNCTION IDENT SEMICOLON {openFile(); fout << "func " << ($2) << endl; paramCount = 0; } BEGIN_PARAMS declaration_call 
						END_PARAMS BEGIN_LOCALS declaration_call 
						END_LOCALS BEGIN_BODY statement_call END_BODY {fout << "endfunc" << endl;}
						{
							cout << "function -> FUNCTION IDENT " << *($2) << " SEMICOLON BEGIN_PARAMS " << "declaration_call END_LOCALS BEGIN_BODY statement_call END_BODY" << endl;
						}
  
  declaration_call: 	declaration SEMICOLON declaration_call 
						{
							cout << "declaration_call -> declaration SEMICOLON declaration_call" << endl;
						}
						| 
						/* EMPTY */
						{
							cout << "declaration_call -> EMPTY" << endl;
						}
  
  statement_call:		statement SEMICOLON statement_call
						{
							cout << "statement_call -> statement SEMICOLON statement_call" << endl;
						}
						| 
						/* EMPTY */
						{
							cout << "statement_call -> EMPTY" << endl;
						}
  
  declaration:			IDENT ident_call {fout << ". " << *($1) << endl; fout << "= " << *($1) << ", $" << paramCount++ << endl; }
						{
							cout << "declaration -> IDENT " << *($1) << " ident_call" << endl;
						}
					
  ident_call:			COMMA IDENT ident_call {fout << ". " << *($2) << endl; fout << "= " << *($2) << ", $" << paramCount++ << endl;}
						{
							cout << "ident_call -> COMMA IDENT " << *($2) << " ident_call" << endl;
						}
						|
						COLON ident_rhs
						{
							cout << "ident_call -> COLON ident_rhs" << endl;
						}
					
  ident_rhs:			INTEGER 
						{
							cout << "ident_rhs -> INTEGER" << endl;
						}
						|
						ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
						{
							cout << "ident_rhs -> ARRAY L_SQUARE_BRACKET NUMBER " << $3 << " R_SQUARE_BRACKET OF INTEGER" << endl; {fout << ".[] " << *($1) << ", " << ($3) << endl;
							for (int i = 0; i < atoi($3); i++)
							{
								fout << "[]= " << *($1) << ", $" << paramCount << endl;
								paramCount++;
							}
							}
						}
  
  statement:			var ASSIGN expression {fout <<  "= " << *($1) << ", " << *($3) << endl;}
						{
							cout << "statement -> var ASSIGN expression" << endl;
						}
						|
						IF bool-expr {cout << "peepee" << endl;fout << "?:=__label__" << labelCount << ", " << *($2) << endl; cout << "peepee2" << endl;
									  fout << ":=__label__" << labelCount + 1 << endl;
									  fout << ":__label__" << labelCount << endl;$<int_val>$ = labelCount + 1; labelCount += 2;} THEN statement SEMICOLON if_loop
						{
							cout << "statement -> IF bool-expr THEN statement SEMICOLON if_loop" << endl;
						}
						|
						WHILE bool-expr BEGINLOOP statement SEMICOLON statement_loop
						{
							cout << "statement -> WHILE bool-expr BEGINLOOP statement SEMICOLON statement_loop" << endl;
						}
						|
						DO BEGINLOOP statement SEMICOLON statement_loop WHILE bool-expr
						{
							cout << "statement -> DO BEGINLOOP statement SEMICOLON statement_loop WHILE bool-expr" << endl;
						}
						|
						FOREACH IDENT IN IDENT BEGINLOOP statement_loop
						{
							cout << "statement -> FOREACH IDENT " << *($2) << " IN IDENT " << *($4) << " BEGINLOOP statement_loop" << endl;
						}
						|
						READ var_call {fout << ".< " << *$1 << endl;}
						{
							cout << "statement -> READ var_call" << endl;
						}
						|
						WRITE var_call {fout << ".> " << *$1 << endl;}
						{
							cout << "statement -> WRITE var_call" << endl;
						}
						|
						CONTINUE
						{
							cout << "statement -> CONTINUE" << endl;
						}
						|
						RETURN expression
						{
							cout << "statement -> RETURN expression" << endl;
						}
					
  if_loop:				ENDIF
						{
							cout << "if_loop -> ENDIF" << endl;
						}
						|
						statement SEMICOLON if_loop
						{
							cout << "if_loop -> statement SEMICOLON if_loop" << endl;
						}
						|
						ELSE statement SEMICOLON ifelse_loop
						{
							cout << "if_loop -> ELSE statement SEMICOLON ifelse_loop" << endl;
						}
  
  ifelse_loop:			ENDIF
						{
							cout << "ifelse_loop -> ENDIF" << endl;
						}
						|
						statement SEMICOLON ifelse_loop
						{
							cout << "ifelse_loop -> statement SEMICOLON ifelse_loop" << endl;
						}
  
  statement_loop:		ENDLOOP
						{
							cout << "statement_loop -> ENDLOOP" << endl;
						}
						|
						statement SEMICOLON statement_loop
						{
							cout << "statement_loop -> statement SEMICOLON statement_loop" << endl;
						}

  var_call:				var
						{
							cout << "var_call -> var" << endl;
						}
						|
						var COMMA var_call
						{
							cout << "var_call -> var COMMA var_call" << endl;
						}
  
  bool-expr:			relation-and-expr { $<ident_val>$ = $1; } more-bool 
						{
							cout << "bool-expr -> relation-and-expr more-bool" << endl;
						}
  
  more-bool:			OR relation-and-expr { fout << ". __temp__" << tempCount << endl; 
											   fout << "|| " << " __temp__" << tempCount <<  ", " << *($1) <<  ", " << *($2) << endl;
											   tempCount++; $<ident_val>$ = "__temp__" + (tempCount - 1);}  more-bool
						{
							cout << "more-bool -> OR relation-and-expr more-bool" << endl;
						}
						|
						/* EMPTY */
						{
							cout << "more-bool -> EMPTY" << endl;
						}
  
  relation-and-expr:	relation-expr { $<ident_val>$ = $1;} more-expr
						{
							cout << "relation-and-expr -> relation-expr more-expr" << endl;
						}
  
  more-expr:			AND relation-expr { fout << ". __temp__" << tempCount << endl; 
											fout << "&& " << " __temp__" << tempCount <<  ", " << *($1) <<  ", " << *($2) << endl;
											tempCount++; $<ident_val>$ = "__temp__" + (tempCount-1);} 
						more-expr
						{
							cout << "more-expr -> AND relation-expr more-expr" << endl;
						}
						|
						/* EMPTY */
						{
							cout << "more-expr -> EMPTY" << endl;
						}
  
  relation-expr:		NOT relation-rhs { fout << "! " << *($2) << *($2) << endl; $<ident_val>$ = $2;  }
						{
							cout << "relation-expr -> NOT relation-rhs" << endl;
						}
						|
						relation-rhs
						{
							cout << "relation-expr -> relation-rhs" << endl;
						}
  
  relation-rhs:		expression comp expression { fout << ". __temp__" << tempCount << endl;
												 fout << *($2) << " __temp__" << tempCount <<  ", " << *($1) <<  ", " << *($3) << endl;
												 tempCount++; $<ident_val>$ = "__temp__" + (tempCount-1);}
						{
							cout << "relation-rhs -> expression comp expression" << endl;
						}
						|
						TRUE {$<ident_val>$ = "1";}
						{
							cout << "relation-rhs -> TRUE" << endl;
						}
						|
						FALSE {$<ident_val>$ = "0";}
						{
							cout << "relation-rhs -> FALSE" << endl;
						}
						|
						L_PAREN bool-expr R_PAREN {$<ident_val>$ = $2;}
						{
							cout << "relation-rhs -> L_PAREN bool-expr R_PAREN" << endl;
						}
  
  comp:					EQ { $<ident_val>$ = "==";}
						{
							cout << "comp -> EQ" << endl;
						}
						|
						NEQ { $<ident_val>$ = "!=";}
						{
							cout << "comp -> NEQ" << endl;
						}
						|
						LT { $<ident_val>$ = "<";}
						{
							cout << "comp -> LT" << endl;
						}
						|
						GT { $<ident_val>$ = ">";}
						{
							cout << "comp -> GT" << endl;
						}
						|
						LTE { $<ident_val>$ = "<="; fout << "found LTE" << endl;} 
						{
							cout << "comp -> LTE" << endl;
						}
						|
						GTE { $<ident_val>$ = ">=";}	
						{
							cout << "comp -> GTE" << endl;
						}
  
  expression:			multiplicative-expr expr_arith /*{fout << "1" << endl; fout << "seg fault1" << endl; fout << "param " + *($1) << endl; cout << "seg fault2" << endl;}*/
						{
							cout << "expression -> multiplicative-expr expr_arith" << endl;
						}
  
  expr_arith:			ADD multiplicative-expr {$<ident_val>$ = $1; cout << *($1) << endl;}
						expr_arith {fout << ". __temp__" << tempCount << endl; fout << "+ "<< "__temp__" << tempCount <<  ", " << *($1) <<  ", " << *($2) << endl;
									tempCount++; $<ident_val>$ = "__temp__" + (tempCount-1); }
						{
							cout << "expr_arith -> ADD multiplicative-expr expr_arith" << endl;
						}
						|
						SUB multiplicative-expr {$<ident_val>$ = $1;}
						expr_arith {fout << ". __temp__" << tempCount << endl; fout << "- "<< "__temp__" << tempCount <<  ", " << *($1) <<  ", " << *($2) << endl;
									tempCount++; $<ident_val>$= "__temp__" + (tempCount - 1); }
						{
							cout << "expr_arith -> SUB multiplicative-expr expr_arith" << endl;
						}
						|
						/* EMPTY */
						{
							cout << "expr_arith -> EMPTY" << endl;
						}
  
  multiplicative-expr:	term multterms {$<ident_val>$ = $1;}
						{
							cout << "multiplciative-expr -> term multterms" << endl;
						}
  
  multterms:			MULT term multterms {fout << ". __temp__" << tempCount << endl; fout << "* "<< "__temp__" << tempCount <<  ", " << *($3) <<  ", " << *($2) << endl;
							  tempCount++; $<ident_val>$ = "__temp__" + (tempCount - 1); }
						{
							cout << "multterms -> MULT term multterms" << endl;
						}
						|
						DIV term multterms {fout << ". __temp__" << tempCount << endl; fout << "/ "<< "__temp__" << tempCount <<  ", " << *($3) <<  ", " << *($2) << endl;
							  tempCount++; $<ident_val>$ = "__temp__" + (tempCount - 1); }
						{
							cout << "multterms -> DIV term multterms" << endl;
						}
						|
						MOD term multterms {fout << ". __temp__" << tempCount << endl; fout << "% "<< "__temp__" << tempCount <<  ", " << *($3) <<  ", " << *($2) << endl;
							  tempCount++; $<ident_val>$ = "__temp__" + (tempCount - 1); }
						{
							cout << "multterms -> MOD term multterms" << endl;
						}
						|
						/* EMPTY */
						{
							cout << "multterms -> EMPTY" << endl;
						}
  
  term:					SUB termA { fout << "* " << *($2) << *($2) << -1 << endl; $<ident_val>$ = $2;}
						{
							cout << "term -> SUB termA" << endl;
						}
						|
						termA {$<ident_val>$ = $1;}
						{
							cout << "term -> termA" << endl;
						}
						|
						termB {$<ident_val>$ = $1;}
						{
							cout << "term -> termB" << endl;
						}
  
  termA:				var  {$<ident_val>$ = $1;}
						{
							cout << "termA -> var" << endl;
						}
						|
						NUMBER {$<ident_val>$ = $1;}
						{
							cout << "termA -> NUMBER " << $1 << endl;
						}
						|
						L_PAREN expression R_PAREN {$<ident_val>$ = $2;}
						{
							cout << "termA -> L_PAREN expression R_PAREN" << endl;
						}
  
  termB:				IDENT L_PAREN term_param R_PAREN { fout << ". __temp__" << tempCount << endl;
														   fout << "call " << ($1) << ", " << "__temp__" << tempCount << endl; 
														   tempCount++; $<ident_val>$= "__temp__" + (tempCount - 1);}
		
						{
							cout << "termB -> IDENT " << *($1) << " L_PAREN term_param R_PAREN" << endl;
						}
  
  term_param:			expression
						{
							cout << "term_param -> expression" << endl;
						}
						|
						expression COMMA term_param
						{
							cout << "term_param -> expression COMMA term_param" << endl;
						}
						|
						/* EMPTY */
						{
							cout << "term_param -> EMPTY" << endl;
						}
  
  var:					IDENT {$<ident_val>$ = $1;}
						{
							cout << "var -> IDENT " << *($1) << endl;
						}
						|
						IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET { fout << ". __temp__" << tempCount << endl;
																			 fout << "=[] __temp__" << tempCount << ", " << *($1) << ", " << *($3) << endl;
																			 tempCount++; $<ident_val>$ = "__temp__" + (tempCount - 1); }
						{
							cout << "var -> IDENT " << *($1) << " L_SQUARE_BRACKET expression R_SQUARE_BRACKET" << endl;
						}
%%

int yyerror(string s)
{
  extern int currLine;
  extern char *yytext;
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << currLine << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}

void openFile() 
{
	if(!open) {fout.open("myCode.mil", fstream::out); 
	open=1; }
}
