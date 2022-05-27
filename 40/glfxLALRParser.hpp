#ifndef YY_GLFX_GLFXLALRPARSER_HPP_INCLUDED
# define YY_GLFX_GLFXLALRPARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int glfxdebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SHADER = 258,
     PROGRAM = 259,
     INTERFACE = 260,
     IDENTIFIER = 261,
     STORAGEQ = 262,
     GL_FRAGDEPTH = 263,
     STORAGET = 264,
     SHADER_TYPE = 265,
     LP = 266,
     RP = 267,
     LB = 268,
     RB = 269,
     SC = 270,
     COMMA = 271,
     COLON = 272,
     EQUALS = 273,
     NUM = 274,
     INCLUDE = 275,
     SAMPLER = 276,
     FLOAT = 277,
     EMPTY_ARRAY_BRACKETS = 278
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE glfxlval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int glfxparse (void *YYPARSE_PARAM);
#else
int glfxparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int glfxparse (void);
#else
int glfxparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_GLFX_GLFXLALRPARSER_HPP_INCLUDED  */
