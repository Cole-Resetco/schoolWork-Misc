/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y" /* yacc.c:339  */

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



#line 84 "mini_l.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mini_l.tab.h".  */
#ifndef YY_YY_MINI_L_TAB_H_INCLUDED
# define YY_YY_MINI_L_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENT = 259,
    FUNCTION = 260,
    BEGIN_PARAMS = 261,
    END_PARAMS = 262,
    BEGIN_LOCALS = 263,
    END_LOCALS = 264,
    BEGIN_BODY = 265,
    END_BODY = 266,
    INTEGER = 267,
    ARRAY = 268,
    OF = 269,
    IF = 270,
    THEN = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    FOREACH = 276,
    IN = 277,
    BEGINLOOP = 278,
    ENDLOOP = 279,
    CONTINUE = 280,
    READ = 281,
    WRITE = 282,
    AND = 283,
    OR = 284,
    TRUE = 285,
    FALSE = 286,
    RETURN = 287,
    SEMICOLON = 288,
    COLON = 289,
    COMMA = 290,
    SUB = 291,
    ADD = 292,
    MULT = 293,
    DIV = 294,
    MOD = 295,
    EQ = 296,
    NEQ = 297,
    LT = 298,
    GT = 299,
    LTE = 300,
    GTE = 301,
    L_PAREN = 302,
    R_PAREN = 303,
    L_SQUARE_BRACKET = 304,
    R_SQUARE_BRACKET = 305,
    NOT = 306,
    ASSIGN = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "mini_l.y" /* yacc.c:355  */

  int int_val;
  const char* ident_val;

#line 182 "mini_l.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_L_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "mini_l.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    88,    94,    97,    99,    97,   104,   110,
     114,   120,   124,   124,   129,   129,   134,   139,   144,   155,
     155,   160,   160,   167,   172,   177,   182,   182,   187,   187,
     192,   197,   202,   207,   212,   217,   222,   227,   232,   237,
     242,   247,   247,   252,   252,   260,   264,   264,   269,   269,
     278,   282,   282,   287,   292,   292,   299,   299,   304,   304,
     309,   309,   314,   314,   319,   319,   324,   324,   329,   329,
     334,   334,   339,   339,   344,   349,   350,   349,   356,   357,
     356,   364,   368,   368,   373,   373,   379,   379,   385,   385,
     392,   396,   396,   401,   401,   406,   406,   411,   411,   416,
     416,   421,   421,   426,   426,   434,   439,   445,   449,   449,
     454,   454
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "FOREACH", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE",
  "READ", "WRITE", "AND", "OR", "TRUE", "FALSE", "RETURN", "SEMICOLON",
  "COLON", "COMMA", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT",
  "GT", "LTE", "GTE", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "NOT", "ASSIGN", "$accept", "program",
  "begin_program", "function", "$@1", "$@2", "declaration_call",
  "statement_call", "declaration", "$@3", "ident_call", "$@4", "ident_rhs",
  "statement", "$@5", "@6", "$@7", "$@8", "if_loop", "ifelse_loop",
  "statement_loop", "var_call", "bool-expr", "@9", "more-bool", "@10",
  "relation-and-expr", "@11", "more-expr", "@12", "relation-expr", "@13",
  "relation-rhs", "@14", "@15", "@16", "@17", "comp", "@18", "@19", "@20",
  "@21", "@22", "@23", "expression", "expr_arith", "@24", "@25", "@26",
  "@27", "multiplicative-expr", "@28", "multterms", "@29", "@30", "@31",
  "term", "@32", "@33", "@34", "termA", "@35", "@36", "@37", "termB",
  "@38", "term_param", "var", "@39", "@40", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -156

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-156)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    36,    54,  -156,    12,    16,  -156,  -156,  -156,    51,
      64,    17,    66,    42,    58,    86,  -156,    84,    64,  -156,
      65,  -156,    17,  -156,    64,  -156,   100,  -156,   102,    70,
    -156,   106,   108,   148,   117,    82,     8,     8,   110,   130,
    -156,   132,   132,    20,   134,   113,    89,  -156,    20,  -156,
    -156,   -29,  -156,  -156,     1,     8,    11,  -156,  -156,  -156,
    -156,    19,    49,   -13,  -156,  -156,  -156,   120,   148,   125,
    -156,   114,  -156,    20,  -156,  -156,   148,    20,   101,  -156,
      20,  -156,  -156,  -156,   105,   -12,  -156,   138,   126,   128,
    -156,  -156,  -156,  -156,  -156,  -156,    20,    20,    20,  -156,
      20,    20,    20,  -156,  -156,  -156,  -156,   148,   124,   158,
    -156,   132,  -156,   122,  -156,  -156,  -156,  -156,   136,   129,
    -156,  -156,  -156,  -156,   148,     8,  -156,     8,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,   -13,   -13,
     -13,  -156,   139,    80,   142,  -156,  -156,  -156,    20,  -156,
    -156,  -156,   143,  -156,  -156,  -156,    49,    49,  -156,  -156,
    -156,    80,  -156,   145,   160,    80,  -156,  -156,    62,   126,
     128,  -156,  -156,  -156,  -156,  -156,  -156,    80,     8,  -156,
    -156,   148,   149,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
     150,    62,    98,  -156,  -156,   151,  -156,    98,  -156
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     1,     3,     5,     0,
       9,     0,     0,     0,     0,     0,    12,     0,     9,    17,
       0,    16,     0,    13,     9,     8,     0,    14,     0,     0,
      15,     0,     0,    11,     0,   108,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,    18,     0,   109,
      99,   108,    56,    58,     0,     0,     0,    21,    41,    46,
      53,     0,    81,    90,    93,    95,    97,     0,     0,     0,
      26,    39,    28,     0,    31,     6,    11,     0,     0,   100,
     107,    57,    59,    91,     0,     0,    51,     0,    45,    50,
      62,    64,    66,    68,    70,    72,     0,     0,     0,    74,
       0,     0,     0,    82,    94,    96,    98,     0,     0,     0,
      27,     0,    29,     0,     7,    10,    19,   110,   105,     0,
      92,    60,   101,    52,     0,     0,    42,     0,    47,    63,
      65,    67,    69,    71,    73,    54,    78,    75,    90,    90,
      90,    83,     0,     0,     0,    40,    20,   111,   107,   103,
      61,   102,     0,    43,    48,    55,    81,    81,    84,    86,
      88,     0,    37,     0,     0,     0,   106,   104,     0,    45,
      50,    79,    76,    85,    87,    89,    23,     0,     0,    25,
      32,     0,     0,    22,    44,    49,    80,    77,    38,    24,
       0,     0,     0,    33,    35,     0,    34,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,   177,  -156,  -156,  -156,   -11,   109,  -156,  -156,
     164,  -156,  -156,   -31,  -156,  -156,  -156,  -156,    -4,    -9,
    -155,   -39,   -36,  -156,    21,  -156,    67,  -156,    23,  -156,
      68,  -156,   133,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,   -27,   -48,  -156,  -156,  -156,  -156,
      29,  -156,   -42,  -156,  -156,  -156,    38,  -156,  -156,  -156,
     137,  -156,  -156,  -156,  -156,  -156,    46,   -33,  -156,  -156
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,   114,    12,    44,    13,    23,
      16,    30,    21,   163,   146,    87,   110,   112,   183,   196,
     164,    70,    57,    88,   126,   169,    58,    89,   128,   170,
      59,   123,    60,   155,    81,    82,   150,    96,   129,   130,
     131,   132,   133,   134,    61,    99,   157,   187,   156,   186,
      62,   141,   103,   173,   174,   175,    63,   120,   104,   105,
      64,   106,    79,   151,    65,   167,   119,    66,    49,   147
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    67,    45,    72,    50,    35,   176,    25,    71,    71,
     179,    50,    51,    28,    50,    51,    74,     1,    80,    84,
      48,    78,   188,    50,    51,   100,   101,   102,    85,    90,
      91,    92,    93,    94,    95,    46,   122,   108,    52,    53,
       5,    52,    53,    46,    54,    45,   113,    54,    73,     8,
     116,    14,    15,   118,     6,    55,    54,    10,    55,    56,
      90,    91,    92,    93,    94,    95,    35,    73,    11,   135,
      19,    20,   145,    17,    46,    18,   142,    36,    71,   180,
     181,    37,    38,    39,    35,    97,    98,    40,    41,    42,
      22,    46,    24,   152,    43,    36,   158,   159,   160,    37,
      38,    39,    35,    29,   162,    40,    41,    42,   171,   172,
      46,    31,    43,    36,    26,   194,    33,    37,    38,    39,
      32,   118,    34,    40,    41,    42,   136,   137,    46,    47,
      43,    48,    46,    68,    69,    46,    35,   182,   138,   139,
     140,    77,   189,   107,    46,    75,    76,   109,    46,   111,
     190,   117,    35,   121,   124,   125,   127,   143,    46,    46,
     182,   195,   144,    36,    46,   165,   195,    37,    38,    39,
     122,   148,   161,    40,    41,    42,   168,   149,   177,   178,
      43,     7,   191,   192,   197,   115,    27,   193,   198,    86,
     184,    83,   153,   185,   166,   154
};

static const yytype_uint8 yycheck[] =
{
      33,    37,    33,    42,     3,     4,   161,    18,    41,    42,
     165,     3,     4,    24,     3,     4,    43,     5,    47,    55,
      49,    48,   177,     3,     4,    38,    39,    40,    55,    41,
      42,    43,    44,    45,    46,    68,    48,    68,    30,    31,
       4,    30,    31,    76,    36,    76,    73,    36,    47,    33,
      77,    34,    35,    80,     0,    47,    36,     6,    47,    51,
      41,    42,    43,    44,    45,    46,     4,    47,     4,    96,
      12,    13,   111,     7,   107,    33,   107,    15,   111,    17,
      18,    19,    20,    21,     4,    36,    37,    25,    26,    27,
       4,   124,     8,   124,    32,    15,   138,   139,   140,    19,
      20,    21,     4,     3,    24,    25,    26,    27,   156,   157,
     143,     9,    32,    15,    49,    17,    10,    19,    20,    21,
      50,   148,    14,    25,    26,    27,    97,    98,   161,    12,
      32,    49,   165,    23,     4,   168,     4,   168,   100,   101,
     102,    52,   178,    23,   177,    11,    33,    22,   181,    35,
     181,    50,     4,    48,    16,    29,    28,    33,   191,   192,
     191,   192,     4,    15,   197,    23,   197,    19,    20,    21,
      48,    35,    33,    25,    26,    27,    33,    48,    33,    19,
      32,     4,    33,    33,    33,    76,    22,   191,   197,    56,
     169,    54,   125,   170,   148,   127
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    54,    55,    56,     4,     0,    55,    33,    57,
       6,     4,    59,    61,    34,    35,    63,     7,    33,    12,
      13,    65,     4,    62,     8,    59,    49,    63,    59,     3,
      64,     9,    50,    10,    14,     4,    15,    19,    20,    21,
      25,    26,    27,    32,    60,    66,   120,    12,    49,   121,
       3,     4,    30,    31,    36,    47,    51,    75,    79,    83,
      85,    97,   103,   109,   113,   117,   120,    75,    23,     4,
      74,   120,    74,    47,    97,    11,    33,    52,    97,   115,
      47,    87,    88,   113,    75,    97,    85,    68,    76,    80,
      41,    42,    43,    44,    45,    46,    90,    36,    37,    98,
      38,    39,    40,   105,   111,   112,   114,    23,    66,    22,
      69,    35,    70,    97,    58,    60,    97,    50,    97,   119,
     110,    48,    48,    84,    16,    29,    77,    28,    81,    91,
      92,    93,    94,    95,    96,    97,   103,   103,   109,   109,
     109,   104,    66,    33,     4,    74,    67,   122,    35,    48,
      89,   116,    66,    79,    83,    86,   101,    99,   105,   105,
     105,    33,    24,    66,    73,    23,   119,   118,    33,    78,
      82,    98,    98,   106,   107,   108,    73,    33,    19,    73,
      17,    18,    66,    71,    77,    81,   102,   100,    73,    75,
      66,    33,    33,    71,    17,    66,    72,    33,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    57,    58,    56,    59,    59,
      60,    60,    62,    61,    64,    63,    63,    65,    65,    67,
      66,    68,    66,    66,    66,    66,    69,    66,    70,    66,
      66,    66,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    76,    75,    78,    77,    77,    80,    79,    82,    81,
      81,    84,    83,    83,    86,    85,    87,    85,    88,    85,
      89,    85,    91,    90,    92,    90,    93,    90,    94,    90,
      95,    90,    96,    90,    97,    99,   100,    98,   101,   102,
      98,    98,   104,   103,   106,   105,   107,   105,   108,   105,
     105,   110,   109,   111,   109,   112,   109,   114,   113,   115,
     113,   116,   113,   118,   117,   119,   119,   119,   121,   120,
     122,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     0,    14,     3,     0,
       3,     0,     0,     3,     0,     4,     2,     1,     6,     0,
       4,     0,     7,     6,     7,     6,     0,     3,     0,     3,
       1,     2,     1,     3,     4,     1,     3,     1,     3,     1,
       3,     0,     3,     0,     4,     0,     0,     3,     0,     4,
       0,     0,     3,     1,     0,     4,     0,     2,     0,     2,
       0,     4,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     2,     0,     0,     5,     0,     0,
       5,     0,     0,     3,     0,     4,     0,     4,     0,     4,
       0,     0,     3,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     4,     0,     5,     1,     3,     0,     0,     2,
       0,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 84 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "program -> begin_program" << endl;
						}
#line 1432 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "begin_program -> function begin_program" << endl;
						}
#line 1440 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "begin_program -> EMPTY" << endl;
						}
#line 1448 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "mini_l.y" /* yacc.c:1646  */
    {openFile(); fout << "func " << ((yyvsp[-1].ident_val)) << endl; paramCount = 0; }
#line 1454 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "mini_l.y" /* yacc.c:1646  */
    {fout << "endfunc" << endl;}
#line 1460 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "function -> FUNCTION IDENT " << *((yyvsp[-12].ident_val)) << " SEMICOLON BEGIN_PARAMS " << "declaration_call END_LOCALS BEGIN_BODY statement_call END_BODY" << endl;
						}
#line 1468 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "declaration_call -> declaration SEMICOLON declaration_call" << endl;
						}
#line 1476 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "declaration_call -> EMPTY" << endl;
						}
#line 1484 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement_call -> statement SEMICOLON statement_call" << endl;
						}
#line 1492 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 120 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement_call -> EMPTY" << endl;
						}
#line 1500 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "mini_l.y" /* yacc.c:1646  */
    {fout << ". " << *((yyvsp[-1].ident_val)) << endl; fout << "= " << *((yyvsp[-1].ident_val)) << ", $" << paramCount++ << endl; }
#line 1506 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 125 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "declaration -> IDENT " << *((yyvsp[-2].ident_val)) << " ident_call" << endl;
						}
#line 1514 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "mini_l.y" /* yacc.c:1646  */
    {fout << ". " << *((yyvsp[-1].ident_val)) << endl; fout << "= " << *((yyvsp[-1].ident_val)) << ", $" << paramCount++ << endl;}
#line 1520 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "ident_call -> COMMA IDENT " << *((yyvsp[-2].ident_val)) << " ident_call" << endl;
						}
#line 1528 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 135 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "ident_call -> COLON ident_rhs" << endl;
						}
#line 1536 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 140 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "ident_rhs -> INTEGER" << endl;
						}
#line 1544 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 145 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "ident_rhs -> ARRAY L_SQUARE_BRACKET NUMBER " << (yyvsp[-3].ident_val) << " R_SQUARE_BRACKET OF INTEGER" << endl; {fout << ".[] " << *((yyvsp[-5].ident_val)) << ", " << ((yyvsp[-3].ident_val)) << endl;
							for (int i = 0; i < atoi((yyvsp[-3].ident_val)); i++)
							{
								fout << "[]= " << *((yyvsp[-5].ident_val)) << ", $" << paramCount << endl;
								paramCount++;
							}
							}
						}
#line 1558 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "mini_l.y" /* yacc.c:1646  */
    {fout <<  "= " << *((yyvsp[-2].ident_val)) << ", " << *((yyvsp[0].ident_val)) << endl;}
#line 1564 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 156 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> var ASSIGN expression" << endl;
						}
#line 1572 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 160 "mini_l.y" /* yacc.c:1646  */
    {cout << "peepee" << endl;fout << "?:=__label__" << labelCount << ", " << *((yyvsp[0].ident_val)) << endl; cout << "peepee2" << endl;
									  fout << ":=__label__" << labelCount + 1 << endl;
									  fout << ":__label__" << labelCount << endl;(yyval.int_val) = labelCount + 1; labelCount += 2;}
#line 1580 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 163 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> IF bool-expr THEN statement SEMICOLON if_loop" << endl;
						}
#line 1588 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 168 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> WHILE bool-expr BEGINLOOP statement SEMICOLON statement_loop" << endl;
						}
#line 1596 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 173 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> DO BEGINLOOP statement SEMICOLON statement_loop WHILE bool-expr" << endl;
						}
#line 1604 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 178 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> FOREACH IDENT " << *((yyvsp[-4].ident_val)) << " IN IDENT " << *((yyvsp[-2].ident_val)) << " BEGINLOOP statement_loop" << endl;
						}
#line 1612 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 182 "mini_l.y" /* yacc.c:1646  */
    {fout << ".< " << *(yyvsp[-1].ident_val) << endl;}
#line 1618 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 183 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> READ var_call" << endl;
						}
#line 1626 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "mini_l.y" /* yacc.c:1646  */
    {fout << ".> " << *(yyvsp[-1].ident_val) << endl;}
#line 1632 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> WRITE var_call" << endl;
						}
#line 1640 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 193 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> CONTINUE" << endl;
						}
#line 1648 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 198 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement -> RETURN expression" << endl;
						}
#line 1656 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 203 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "if_loop -> ENDIF" << endl;
						}
#line 1664 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 208 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "if_loop -> statement SEMICOLON if_loop" << endl;
						}
#line 1672 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 213 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "if_loop -> ELSE statement SEMICOLON ifelse_loop" << endl;
						}
#line 1680 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 218 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "ifelse_loop -> ENDIF" << endl;
						}
#line 1688 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 223 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "ifelse_loop -> statement SEMICOLON ifelse_loop" << endl;
						}
#line 1696 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 228 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement_loop -> ENDLOOP" << endl;
						}
#line 1704 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 233 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "statement_loop -> statement SEMICOLON statement_loop" << endl;
						}
#line 1712 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 238 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "var_call -> var" << endl;
						}
#line 1720 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 243 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "var_call -> var COMMA var_call" << endl;
						}
#line 1728 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 247 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = (yyvsp[0].ident_val); }
#line 1734 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 248 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "bool-expr -> relation-and-expr more-bool" << endl;
						}
#line 1742 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 252 "mini_l.y" /* yacc.c:1646  */
    { fout << ". __temp__" << tempCount << endl; 
											   fout << "|| " << " __temp__" << tempCount <<  ", " << *((yyvsp[-1].ident_val)) <<  ", " << *((yyvsp[0].ident_val)) << endl;
											   tempCount++; (yyval.ident_val) = "__temp__" + (tempCount - 1);}
#line 1750 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 255 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "more-bool -> OR relation-and-expr more-bool" << endl;
						}
#line 1758 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 260 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "more-bool -> EMPTY" << endl;
						}
#line 1766 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 264 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = (yyvsp[0].ident_val);}
#line 1772 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 265 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "relation-and-expr -> relation-expr more-expr" << endl;
						}
#line 1780 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 269 "mini_l.y" /* yacc.c:1646  */
    { fout << ". __temp__" << tempCount << endl; 
											fout << "&& " << " __temp__" << tempCount <<  ", " << *((yyvsp[-1].ident_val)) <<  ", " << *((yyvsp[0].ident_val)) << endl;
											tempCount++; (yyval.ident_val) = "__temp__" + (tempCount-1);}
#line 1788 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 273 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "more-expr -> AND relation-expr more-expr" << endl;
						}
#line 1796 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 278 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "more-expr -> EMPTY" << endl;
						}
#line 1804 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 282 "mini_l.y" /* yacc.c:1646  */
    { fout << "! " << *((yyvsp[0].ident_val)) << *((yyvsp[0].ident_val)) << endl; (yyval.ident_val) = (yyvsp[0].ident_val);  }
#line 1810 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 283 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "relation-expr -> NOT relation-rhs" << endl;
						}
#line 1818 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 288 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "relation-expr -> relation-rhs" << endl;
						}
#line 1826 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 292 "mini_l.y" /* yacc.c:1646  */
    { fout << ". __temp__" << tempCount << endl;
												 fout << *((yyvsp[-1].ident_val)) << " __temp__" << tempCount <<  ", " << *((yyvsp[-2].ident_val)) <<  ", " << *((yyvsp[0].ident_val)) << endl;
												 tempCount++; (yyval.ident_val) = "__temp__" + (tempCount-1);}
#line 1834 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 295 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "relation-rhs -> expression comp expression" << endl;
						}
#line 1842 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 299 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = "1";}
#line 1848 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 300 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "relation-rhs -> TRUE" << endl;
						}
#line 1856 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 304 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = "0";}
#line 1862 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 305 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "relation-rhs -> FALSE" << endl;
						}
#line 1870 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 309 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[-1].ident_val);}
#line 1876 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 310 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "relation-rhs -> L_PAREN bool-expr R_PAREN" << endl;
						}
#line 1884 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 314 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = "==";}
#line 1890 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 315 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "comp -> EQ" << endl;
						}
#line 1898 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 319 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = "!=";}
#line 1904 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 320 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "comp -> NEQ" << endl;
						}
#line 1912 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 324 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = "<";}
#line 1918 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 325 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "comp -> LT" << endl;
						}
#line 1926 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 329 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = ">";}
#line 1932 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 330 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "comp -> GT" << endl;
						}
#line 1940 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 334 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = "<="; fout << "found LTE" << endl;}
#line 1946 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 335 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "comp -> LTE" << endl;
						}
#line 1954 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 339 "mini_l.y" /* yacc.c:1646  */
    { (yyval.ident_val) = ">=";}
#line 1960 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 340 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "comp -> GTE" << endl;
						}
#line 1968 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 345 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "expression -> multiplicative-expr expr_arith" << endl;
						}
#line 1976 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 349 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[-1].ident_val); cout << *((yyvsp[-1].ident_val)) << endl;}
#line 1982 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 350 "mini_l.y" /* yacc.c:1646  */
    {fout << ". __temp__" << tempCount << endl; fout << "+ "<< "__temp__" << tempCount <<  ", " << *((yyvsp[-3].ident_val)) <<  ", " << *((yyvsp[-2].ident_val)) << endl;
									tempCount++; (yyval.ident_val) = "__temp__" + (tempCount-1); }
#line 1989 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 352 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "expr_arith -> ADD multiplicative-expr expr_arith" << endl;
						}
#line 1997 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 356 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[-1].ident_val);}
#line 2003 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 357 "mini_l.y" /* yacc.c:1646  */
    {fout << ". __temp__" << tempCount << endl; fout << "- "<< "__temp__" << tempCount <<  ", " << *((yyvsp[-3].ident_val)) <<  ", " << *((yyvsp[-2].ident_val)) << endl;
									tempCount++; (yyval.ident_val)= "__temp__" + (tempCount - 1); }
#line 2010 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 359 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "expr_arith -> SUB multiplicative-expr expr_arith" << endl;
						}
#line 2018 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 364 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "expr_arith -> EMPTY" << endl;
						}
#line 2026 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 368 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[-1].ident_val);}
#line 2032 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 369 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "multiplciative-expr -> term multterms" << endl;
						}
#line 2040 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 373 "mini_l.y" /* yacc.c:1646  */
    {fout << ". __temp__" << tempCount << endl; fout << "* "<< "__temp__" << tempCount <<  ", " << *((yyvsp[0].ident_val)) <<  ", " << *((yyvsp[-1].ident_val)) << endl;
							  tempCount++; (yyval.ident_val) = "__temp__" + (tempCount - 1); }
#line 2047 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 375 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "multterms -> MULT term multterms" << endl;
						}
#line 2055 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 379 "mini_l.y" /* yacc.c:1646  */
    {fout << ". __temp__" << tempCount << endl; fout << "/ "<< "__temp__" << tempCount <<  ", " << *((yyvsp[0].ident_val)) <<  ", " << *((yyvsp[-1].ident_val)) << endl;
							  tempCount++; (yyval.ident_val) = "__temp__" + (tempCount - 1); }
#line 2062 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 381 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "multterms -> DIV term multterms" << endl;
						}
#line 2070 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 385 "mini_l.y" /* yacc.c:1646  */
    {fout << ". __temp__" << tempCount << endl; fout << "% "<< "__temp__" << tempCount <<  ", " << *((yyvsp[0].ident_val)) <<  ", " << *((yyvsp[-1].ident_val)) << endl;
							  tempCount++; (yyval.ident_val) = "__temp__" + (tempCount - 1); }
#line 2077 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 387 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "multterms -> MOD term multterms" << endl;
						}
#line 2085 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 392 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "multterms -> EMPTY" << endl;
						}
#line 2093 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 396 "mini_l.y" /* yacc.c:1646  */
    { fout << "* " << *((yyvsp[0].ident_val)) << *((yyvsp[0].ident_val)) << -1 << endl; (yyval.ident_val) = (yyvsp[0].ident_val);}
#line 2099 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 397 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "term -> SUB termA" << endl;
						}
#line 2107 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 401 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[0].ident_val);}
#line 2113 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 402 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "term -> termA" << endl;
						}
#line 2121 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 406 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[0].ident_val);}
#line 2127 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 407 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "term -> termB" << endl;
						}
#line 2135 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 411 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[0].ident_val);}
#line 2141 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 412 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "termA -> var" << endl;
						}
#line 2149 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 416 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[0].ident_val);}
#line 2155 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 417 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "termA -> NUMBER " << (yyvsp[-1].ident_val) << endl;
						}
#line 2163 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 421 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[-1].ident_val);}
#line 2169 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 422 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "termA -> L_PAREN expression R_PAREN" << endl;
						}
#line 2177 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 426 "mini_l.y" /* yacc.c:1646  */
    { fout << ". __temp__" << tempCount << endl;
														   fout << "call " << ((yyvsp[-3].ident_val)) << ", " << "__temp__" << tempCount << endl; 
														   tempCount++; (yyval.ident_val)= "__temp__" + (tempCount - 1);}
#line 2185 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 430 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "termB -> IDENT " << *((yyvsp[-4].ident_val)) << " L_PAREN term_param R_PAREN" << endl;
						}
#line 2193 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 435 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "term_param -> expression" << endl;
						}
#line 2201 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 440 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "term_param -> expression COMMA term_param" << endl;
						}
#line 2209 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 445 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "term_param -> EMPTY" << endl;
						}
#line 2217 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 449 "mini_l.y" /* yacc.c:1646  */
    {(yyval.ident_val) = (yyvsp[0].ident_val);}
#line 2223 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 450 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "var -> IDENT " << *((yyvsp[-1].ident_val)) << endl;
						}
#line 2231 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 454 "mini_l.y" /* yacc.c:1646  */
    { fout << ". __temp__" << tempCount << endl;
																			 fout << "=[] __temp__" << tempCount << ", " << *((yyvsp[-3].ident_val)) << ", " << *((yyvsp[-1].ident_val)) << endl;
																			 tempCount++; (yyval.ident_val) = "__temp__" + (tempCount - 1); }
#line 2239 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 457 "mini_l.y" /* yacc.c:1646  */
    {
							cout << "var -> IDENT " << *((yyvsp[-4].ident_val)) << " L_SQUARE_BRACKET expression R_SQUARE_BRACKET" << endl;
						}
#line 2247 "mini_l.tab.c" /* yacc.c:1646  */
    break;


#line 2251 "mini_l.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 460 "mini_l.y" /* yacc.c:1906  */


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
