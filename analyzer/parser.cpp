/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "analizador.y"
   
    #include "scanner.h"
    #include "../abstract/command.h" //CLASES Y STRUCTS A UTILIZAR
    #include "../estructures/queue.h"
    #include <iostream>
    #include <string.h>
    #include <string>
    #include <stdio.h>
    #include <stdlib.h>
    #include <vector>
    using namespace std;
    //FILE *yyin;
    int yyerror(const char* ver){
        std::cout<<"errorsin"<<std::endl;
        return 0;
    }

#line 88 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    mkdisk = 258,
    rmdisk = 259,
    fdisk = 260,
    mount = 261,
    unmount = 262,
    mkfs = 263,
    login = 264,
    logout = 265,
    exec = 266,
    pausa = 267,
    rep = 268,
    mkfile = 269,
    mkdir = 270,
    size = 271,
    adjustment = 272,
    unit = 273,
    path = 274,
    type = 275,
    deleteToken = 276,
    name = 277,
    add = 278,
    id = 279,
    fs = 280,
    ruta = 281,
    r = 282,
    cont = 283,
    p = 284,
    password = 285,
    usuario = 286,
    number = 287,
    CADENA = 288,
    caracter = 289,
    identificador = 290,
    equals = 291,
    slash = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "analizador.y"

    struct parameter *parametro;
    class command *command;
    class queue *queueT;

    char *TEXT;
    float flotante;
    int entero;

#line 188 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   134,   140,   146,   150,   154,   158,   162,
     166,   170,   174,   178,   182,   186,   190,   194,   198,   202,
     206,   212,   218,   225,   230,   235,   240,   245,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   268,   269,   270,   271,   273,   274,
     275,   276,   277,   278,   280,   281,   282,   283,   284,   285,
     287,   288,   289,   290,   291,   292,   293,   294,   296,   297,
     298,   299,   301,   302,   304,   305,   306,   307,   308,   309,
     310,   311,   313,   314,   316,   323,   330,   337,   344,   351,
     357,   363,   369,   376,   378,   383,   388,   394,   400,   406,
     415,   423,   431,   436,   441,   446,   451,   457,   462,   463,
     464,   466,   467,   469,   474,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mkdisk", "rmdisk", "fdisk", "mount",
  "unmount", "mkfs", "login", "logout", "exec", "pausa", "rep", "mkfile",
  "mkdir", "size", "adjustment", "unit", "path", "type", "deleteToken",
  "name", "add", "id", "fs", "ruta", "r", "cont", "p", "password",
  "usuario", "number", "CADENA", "caracter", "identificador", "equals",
  "slash", "$accept", "START", "FDISKPAR", "MOUNTPAR", "MKFSPAR",
  "LOGINPAR", "MKFILEPAR", "MKDIRPAR", "UNMOUNTPAR", "REPPAR", "EXECPAR",
  "RMDISKPAR", "MKDISKPAR", "P", "ADJUSTMENT", "UNIT", "SIZE", "PATH",
  "RUTA", "DIRECTORY", "TYPE", "TYPEFORMAT", "DELETEP", "NAME", "ADD",
  "ID", "PASSWORD", "USUARIO", "FS", "R", "CONT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     159,   168,     3,   160,    31,     7,    24,    44,   -92,     3,
     -92,    35,    19,    14,   118,     9,    27,    34,    48,   168,
     -92,   -92,   -92,   -92,   -92,   -92,    52,    55,    57,    58,
     160,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,    31,
     -92,   -92,    62,     7,   -92,    66,    68,    24,   -92,   -92,
     -92,    72,    73,    44,   -92,   -92,   -92,     3,   -92,    78,
      35,   -92,   -92,   -92,   -92,   -92,    80,    19,   -92,   -92,
     -92,   -92,   -92,    14,   -92,   -92,   -92,   168,     3,   160,
      31,     7,    24,    44,   -92,     3,   -92,    35,    19,    14,
      85,    86,    33,    97,   -92,   -92,   -92,   -92,   102,   107,
     113,   121,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   115,   -92,   127,   140,   -92,   -92,   -92,    47,
      29,   -92,   -92,   -92,   -92,    97,   -92,   -92,   -92,   -92,
      97,   -92,   -92,   -92,   -92,   -92,   -92,   168,   -92,   160,
      31,     7,    24,    44,     3,    35,    19,    14,   -92,   -92,
     -92,   155,   152,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   152,   152,   -92,   157,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      89,    90,    91,    92,    21,    84,     0,     0,     0,     0,
      20,    39,    42,    43,    41,    40,    38,    37,    36,    23,
      47,    46,     0,    24,    73,     0,     0,    25,    52,    53,
      51,     0,     0,    16,    57,    58,    59,    26,    83,     0,
      27,    80,    78,    79,    81,   114,     0,    19,    66,    67,
      65,    64,    93,    18,    70,    71,     1,     0,     0,     0,
       0,     0,     0,     0,    14,     0,    12,     0,     0,     0,
       0,     0,     0,     0,    88,    87,    86,    85,     0,     0,
       0,     0,    32,    29,    28,    30,    31,    33,    34,    35,
      44,    45,     0,    72,     0,     0,    49,    48,    50,     0,
       0,    56,    55,    54,    82,     0,    74,    77,    75,    76,
       0,    62,    60,    61,    63,    69,    68,     2,     3,     4,
       5,     6,     7,    13,     8,     9,    10,    11,    96,    94,
      95,   101,    97,   102,   104,   105,   106,   107,   103,   113,
     110,   109,   108,   112,   111,    98,   115,   100,     0,    99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   112,   114,   110,   116,   105,   106,   117,   109,
     119,   122,   120,   -37,    10,    22,     2,    -2,   -34,   -91,
     -27,   -39,   -26,    12,   -24,    13,   -38,   -23,   -35,   -49,
     -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    30,    39,    47,    53,    67,    73,    43,    60,
      57,    24,    19,    74,    20,    21,    22,    23,    62,   152,
      35,    48,    36,    37,    38,    44,    55,    56,    50,    70,
      71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    34,    40,   106,   107,    33,   109,    58,   116,    61,
      69,    75,   118,    31,    68,   122,    41,    97,   133,    49,
      54,    96,    18,    63,    64,    32,   127,   134,   105,    94,
     123,    42,   104,    18,   165,    15,   135,   110,    18,   166,
     102,    95,   108,    72,    45,    90,    65,    66,    42,    46,
      18,   111,   103,    28,    18,   124,   113,    28,   126,    42,
     117,    59,   163,    91,   164,   132,   121,   150,    42,   131,
      92,   136,   128,   129,    51,    52,    25,    34,    40,   160,
     161,    33,   162,    58,    93,    61,    69,    75,    98,    31,
      68,    99,    41,   100,   101,    49,    54,   133,   112,    63,
      64,    32,   114,   116,   115,   122,   134,   118,   119,   120,
     135,   127,   106,   107,   125,   109,   130,   148,    76,   149,
     123,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   151,    97,   153,   105,   110,    96,
     154,   104,   124,   126,   132,   136,   155,    94,   131,   102,
     157,   108,   111,   156,   113,   117,   121,   128,   129,    95,
     158,   103,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   159,    15,    16,    17,    18,
      26,    27,    28,    29,    15,    16,    17,    18,   167,   168,
     169,   139,   142,   146,   140,   147,   145,   137,   141,   143,
     138,     0,     0,     0,   144
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,    30,    30,     3,    30,     9,    47,    11,
      12,    13,    47,     3,    12,    53,     4,    19,    67,     6,
       7,    19,    19,    11,    11,     3,    60,    67,    30,    19,
      53,    24,    30,    19,   125,    16,    73,    39,    19,   130,
      30,    19,    30,    29,    20,    36,    27,    28,    24,    25,
      19,    39,    30,    22,    19,    57,    43,    22,    60,    24,
      47,    26,    33,    36,    35,    67,    53,    34,    24,    67,
      36,    73,    60,    60,    30,    31,    78,    79,    80,    32,
      33,    79,    35,    85,    36,    87,    88,    89,    36,    79,
      88,    36,    80,    36,    36,    82,    83,   146,    36,    87,
      87,    79,    36,   142,    36,   143,   146,   142,    36,    36,
     147,   145,   139,   139,    36,   139,    36,    32,     0,    33,
     143,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    37,   137,    34,   139,   140,   137,
      33,   139,   144,   145,   146,   147,    33,   137,   146,   139,
      35,   139,   140,    32,   141,   142,   143,   145,   145,   137,
      33,   139,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    35,    16,    17,    18,    19,
      20,    21,    22,    23,    16,    17,    18,    19,    33,    37,
      33,    79,    82,    88,    80,    89,    87,    77,    81,    83,
      78,    -1,    -1,    -1,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    39,    16,    17,    18,    19,    50,
      52,    53,    54,    55,    49,    55,    20,    21,    22,    23,
      40,    52,    53,    54,    55,    58,    60,    61,    62,    41,
      55,    61,    24,    46,    63,    20,    25,    42,    59,    63,
      66,    30,    31,    43,    63,    64,    65,    48,    55,    26,
      47,    55,    56,    61,    63,    27,    28,    44,    54,    55,
      67,    68,    29,    45,    51,    55,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      36,    36,    36,    36,    52,    53,    54,    55,    36,    36,
      36,    36,    52,    53,    54,    55,    58,    60,    61,    62,
      55,    61,    36,    63,    36,    36,    59,    63,    66,    36,
      36,    63,    64,    65,    55,    36,    55,    56,    61,    63,
      36,    54,    55,    67,    68,    51,    55,    50,    49,    40,
      41,    46,    42,    43,    48,    47,    44,    45,    32,    33,
      34,    37,    57,    34,    33,    33,    32,    35,    33,    35,
      32,    33,    35,    33,    35,    57,    57,    33,    37,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    41,    41,    41,    41,    42,    42,
      42,    42,    42,    42,    43,    43,    43,    43,    43,    43,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    52,    53,    54,    55,    56,    57,
      57,    57,    58,    59,    60,    61,    62,    63,    64,    64,
      64,    65,    65,    66,    67,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     2,     1,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       2,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 128 "analizador.y"
      {
        mkdiskCmd *c = new mkdiskCmd(); 
        //ASIGNACION DE PARAMETROS
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1609 "parser.cpp"
    break;

  case 3:
#line 135 "analizador.y"
      {
        rmdiskCmd *c = new rmdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1619 "parser.cpp"
    break;

  case 4:
#line 141 "analizador.y"
      {
        fdiskCmd *c = new fdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1629 "parser.cpp"
    break;

  case 5:
#line 147 "analizador.y"
      {
        mountCmd *c = new mountCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1637 "parser.cpp"
    break;

  case 6:
#line 151 "analizador.y"
      {
        unmountCmd *c = new unmountCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1645 "parser.cpp"
    break;

  case 7:
#line 155 "analizador.y"
      {
        mkfsCmd *c = new mkfsCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1653 "parser.cpp"
    break;

  case 8:
#line 159 "analizador.y"
      {
        execCmd *c = new execCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1661 "parser.cpp"
    break;

  case 9:
#line 163 "analizador.y"
      {
        repCmd *c = new repCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1669 "parser.cpp"
    break;

  case 10:
#line 167 "analizador.y"
      {
        mkfileCmd *c = new mkfileCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1677 "parser.cpp"
    break;

  case 11:
#line 171 "analizador.y"
      {
        mkdirCmd *c = new mkdirCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1685 "parser.cpp"
    break;

  case 12:
#line 175 "analizador.y"
      {
        pauseCmd *c = new pauseCmd();c->execute();
      }
#line 1693 "parser.cpp"
    break;

  case 13:
#line 179 "analizador.y"
      {
        loginCmd *c = new loginCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1701 "parser.cpp"
    break;

  case 14:
#line 183 "analizador.y"
      {
        logoutCmd *c = new logoutCmd();c->execute();
      }
#line 1709 "parser.cpp"
    break;

  case 15:
#line 187 "analizador.y"
      {
        logoutCmd *c = new logoutCmd();c->execute();
      }
#line 1717 "parser.cpp"
    break;

  case 16:
#line 191 "analizador.y"
      {
        loginCmd *c = new loginCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1725 "parser.cpp"
    break;

  case 17:
#line 195 "analizador.y"
      {
        pauseCmd *c = new pauseCmd();c->execute();
      }
#line 1733 "parser.cpp"
    break;

  case 18:
#line 199 "analizador.y"
      {
        mkdirCmd *c = new mkdirCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1741 "parser.cpp"
    break;

  case 19:
#line 203 "analizador.y"
      {
        mkfileCmd *c = new mkfileCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1749 "parser.cpp"
    break;

  case 20:
#line 207 "analizador.y"
      {
        fdiskCmd *c = new fdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1759 "parser.cpp"
    break;

  case 21:
#line 213 "analizador.y"
      {
        rmdiskCmd *c = new rmdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1769 "parser.cpp"
    break;

  case 22:
#line 219 "analizador.y"
      {
        mkdiskCmd *c = new mkdiskCmd(); 
        //ASIGNACION DE PARAMETROS
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1780 "parser.cpp"
    break;

  case 23:
#line 226 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        mountCmd *c = new mountCmd();c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1789 "parser.cpp"
    break;

  case 24:
#line 231 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        unmountCmd *c = new unmountCmd();c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1798 "parser.cpp"
    break;

  case 25:
#line 236 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        mkfsCmd *c = new mkfsCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1807 "parser.cpp"
    break;

  case 26:
#line 241 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        execCmd *c = new execCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1816 "parser.cpp"
    break;

  case 27:
#line 246 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        repCmd *c = new repCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1825 "parser.cpp"
    break;

  case 28:
#line 251 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1831 "parser.cpp"
    break;

  case 29:
#line 252 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1837 "parser.cpp"
    break;

  case 30:
#line 253 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1843 "parser.cpp"
    break;

  case 31:
#line 254 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1849 "parser.cpp"
    break;

  case 32:
#line 255 "analizador.y"
                              {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1855 "parser.cpp"
    break;

  case 33:
#line 256 "analizador.y"
                            {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1861 "parser.cpp"
    break;

  case 34:
#line 257 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1867 "parser.cpp"
    break;

  case 35:
#line 258 "analizador.y"
                        {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1873 "parser.cpp"
    break;

  case 36:
#line 259 "analizador.y"
               {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1879 "parser.cpp"
    break;

  case 37:
#line 260 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1885 "parser.cpp"
    break;

  case 38:
#line 261 "analizador.y"
                   {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1891 "parser.cpp"
    break;

  case 39:
#line 262 "analizador.y"
                      {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1897 "parser.cpp"
    break;

  case 40:
#line 263 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1903 "parser.cpp"
    break;

  case 41:
#line 264 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1909 "parser.cpp"
    break;

  case 42:
#line 265 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1915 "parser.cpp"
    break;

  case 43:
#line 266 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1921 "parser.cpp"
    break;

  case 44:
#line 268 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1927 "parser.cpp"
    break;

  case 45:
#line 269 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1933 "parser.cpp"
    break;

  case 46:
#line 270 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1939 "parser.cpp"
    break;

  case 47:
#line 271 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1945 "parser.cpp"
    break;

  case 48:
#line 273 "analizador.y"
                     {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1951 "parser.cpp"
    break;

  case 49:
#line 274 "analizador.y"
                              {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1957 "parser.cpp"
    break;

  case 50:
#line 275 "analizador.y"
                      {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1963 "parser.cpp"
    break;

  case 51:
#line 276 "analizador.y"
              {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1969 "parser.cpp"
    break;

  case 52:
#line 277 "analizador.y"
                      {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1975 "parser.cpp"
    break;

  case 53:
#line 278 "analizador.y"
              {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1981 "parser.cpp"
    break;

  case 54:
#line 280 "analizador.y"
                            {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1987 "parser.cpp"
    break;

  case 55:
#line 281 "analizador.y"
                             {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1993 "parser.cpp"
    break;

  case 56:
#line 282 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1999 "parser.cpp"
    break;

  case 57:
#line 283 "analizador.y"
              {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2005 "parser.cpp"
    break;

  case 58:
#line 284 "analizador.y"
                    {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2011 "parser.cpp"
    break;

  case 59:
#line 285 "analizador.y"
                   {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2017 "parser.cpp"
    break;

  case 60:
#line 287 "analizador.y"
                          {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2023 "parser.cpp"
    break;

  case 61:
#line 288 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2029 "parser.cpp"
    break;

  case 62:
#line 289 "analizador.y"
                          {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2035 "parser.cpp"
    break;

  case 63:
#line 290 "analizador.y"
                          {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2041 "parser.cpp"
    break;

  case 64:
#line 291 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2047 "parser.cpp"
    break;

  case 65:
#line 292 "analizador.y"
             {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2053 "parser.cpp"
    break;

  case 66:
#line 293 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2059 "parser.cpp"
    break;

  case 67:
#line 294 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2065 "parser.cpp"
    break;

  case 68:
#line 296 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2071 "parser.cpp"
    break;

  case 69:
#line 297 "analizador.y"
                      {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2077 "parser.cpp"
    break;

  case 70:
#line 298 "analizador.y"
             {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2083 "parser.cpp"
    break;

  case 71:
#line 299 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2089 "parser.cpp"
    break;

  case 72:
#line 301 "analizador.y"
                           {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2095 "parser.cpp"
    break;

  case 73:
#line 302 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2101 "parser.cpp"
    break;

  case 74:
#line 304 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2107 "parser.cpp"
    break;

  case 75:
#line 305 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2113 "parser.cpp"
    break;

  case 76:
#line 306 "analizador.y"
                     {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2119 "parser.cpp"
    break;

  case 77:
#line 307 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2125 "parser.cpp"
    break;

  case 78:
#line 308 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2131 "parser.cpp"
    break;

  case 79:
#line 309 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2137 "parser.cpp"
    break;

  case 80:
#line 310 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2143 "parser.cpp"
    break;

  case 81:
#line 311 "analizador.y"
              {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2149 "parser.cpp"
    break;

  case 82:
#line 313 "analizador.y"
                        {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2155 "parser.cpp"
    break;

  case 83:
#line 314 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2161 "parser.cpp"
    break;

  case 84:
#line 317 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2171 "parser.cpp"
    break;

  case 85:
#line 324 "analizador.y"
          { 
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2182 "parser.cpp"
    break;

  case 86:
#line 331 "analizador.y"
          {
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2193 "parser.cpp"
    break;

  case 87:
#line 338 "analizador.y"
          {
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2204 "parser.cpp"
    break;

  case 88:
#line 345 "analizador.y"
          {
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2215 "parser.cpp"
    break;

  case 89:
#line 352 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2225 "parser.cpp"
    break;

  case 90:
#line 358 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2235 "parser.cpp"
    break;

  case 91:
#line 364 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2245 "parser.cpp"
    break;

  case 92:
#line 370 "analizador.y"
          { 
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2255 "parser.cpp"
    break;

  case 93:
#line 376 "analizador.y"
     {  (yyval.parametro) = make_parameter((yyvsp[0].TEXT),(yyvsp[0].TEXT),0); }
#line 2261 "parser.cpp"
    break;

  case 94:
#line 379 "analizador.y"
           {
            (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
           }
#line 2269 "parser.cpp"
    break;

  case 95:
#line 384 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2277 "parser.cpp"
    break;

  case 96:
#line 389 "analizador.y"
     {
        float res=std::stof((yyvsp[0].TEXT));
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(char*)"",res);
     }
#line 2286 "parser.cpp"
    break;

  case 97:
#line 395 "analizador.y"
    {   
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
        strcpy( (yyvsp[0].TEXT), "" );
    }
#line 2295 "parser.cpp"
    break;

  case 98:
#line 401 "analizador.y"
    {   
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
        strcpy( (yyvsp[0].TEXT), "" );
    }
#line 2304 "parser.cpp"
    break;

  case 99:
#line 407 "analizador.y"
          {
            char res[100];
            strcat(res,(yyvsp[-1].TEXT));
            strcat(res,(yyvsp[0].TEXT));
            (yyvsp[-2].TEXT) = res; 
            (yyval.TEXT) = (yyvsp[-2].TEXT);
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }
#line 2317 "parser.cpp"
    break;

  case 100:
#line 416 "analizador.y"
          {
            char res[100];
            strcat(res,(yyvsp[-1].TEXT));
            strcat(res,(yyvsp[0].TEXT));
            (yyval.TEXT) = res;
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }
#line 2329 "parser.cpp"
    break;

  case 101:
#line 424 "analizador.y"
          {
            char res[100];
            strcat(res,(yyvsp[0].TEXT));
            (yyval.TEXT) = res;
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }
#line 2340 "parser.cpp"
    break;

  case 102:
#line 432 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2348 "parser.cpp"
    break;

  case 103:
#line 437 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2356 "parser.cpp"
    break;

  case 104:
#line 442 "analizador.y"
       {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
       }
#line 2364 "parser.cpp"
    break;

  case 105:
#line 447 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2372 "parser.cpp"
    break;

  case 106:
#line 452 "analizador.y"
    {   
        float res=std::stof((yyvsp[0].TEXT));
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(char*)"",res);
    }
#line 2381 "parser.cpp"
    break;

  case 107:
#line 458 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2389 "parser.cpp"
    break;

  case 108:
#line 462 "analizador.y"
                                        {(yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);}
#line 2395 "parser.cpp"
    break;

  case 109:
#line 463 "analizador.y"
                                 {(yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);}
#line 2401 "parser.cpp"
    break;

  case 110:
#line 464 "analizador.y"
                                 {(yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);}
#line 2407 "parser.cpp"
    break;

  case 111:
#line 466 "analizador.y"
                                       {(yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);}
#line 2413 "parser.cpp"
    break;

  case 112:
#line 467 "analizador.y"
                                {(yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);}
#line 2419 "parser.cpp"
    break;

  case 113:
#line 470 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2427 "parser.cpp"
    break;

  case 114:
#line 474 "analizador.y"
     {  (yyval.parametro) = make_parameter((yyvsp[0].TEXT),(yyvsp[0].TEXT),0); }
#line 2433 "parser.cpp"
    break;

  case 115:
#line 477 "analizador.y"
    {   
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
        strcpy( (yyvsp[0].TEXT), "" );
    }
#line 2442 "parser.cpp"
    break;


#line 2446 "parser.cpp"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 482 "analizador.y"



void ver(string a){
    YY_BUFFER_STATE buffer = yy_scan_string(a.c_str());
    yyparse();
}

void parse(FILE *file){
    yyin = file;
    yyparse();
    fclose(yyin);
}
