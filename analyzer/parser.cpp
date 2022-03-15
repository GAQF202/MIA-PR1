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
    exec = 265,
    rep = 266,
    mkfile = 267,
    mkdir = 268,
    size = 269,
    adjustment = 270,
    unit = 271,
    path = 272,
    type = 273,
    deleteToken = 274,
    name = 275,
    add = 276,
    id = 277,
    fs = 278,
    ruta = 279,
    r = 280,
    cont = 281,
    p = 282,
    number = 283,
    CADENA = 284,
    caracter = 285,
    identificador = 286,
    equals = 287,
    slash = 288
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

#line 184 "parser.cpp"

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   127,   133,   139,   143,   147,   151,   155,
     159,   163,   167,   171,   175,   181,   187,   194,   199,   204,
     209,   214,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   237,   238,
     239,   240,   242,   243,   244,   245,   246,   247,   249,   250,
     251,   252,   253,   254,   255,   256,   258,   259,   260,   261,
     263,   264,   266,   267,   268,   269,   270,   271,   272,   273,
     275,   276,   278,   285,   292,   299,   306,   313,   319,   325,
     331,   338,   340,   345,   350,   356,   362,   368,   377,   385,
     393,   398,   403,   408,   413,   419,   424,   429,   431
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mkdisk", "rmdisk", "fdisk", "mount",
  "unmount", "mkfs", "login", "exec", "rep", "mkfile", "mkdir", "size",
  "adjustment", "unit", "path", "type", "deleteToken", "name", "add", "id",
  "fs", "ruta", "r", "cont", "p", "number", "CADENA", "caracter",
  "identificador", "equals", "slash", "$accept", "START", "FDISKPAR",
  "MOUNTPAR", "MKFSPAR", "MKFILEPAR", "MKDIRPAR", "UNMOUNTPAR", "REPPAR",
  "EXECPAR", "RMDISKPAR", "MKDISKPAR", "P", "ADJUSTMENT", "UNIT", "SIZE",
  "PATH", "RUTA", "DIRECTORY", "TYPE", "TYPEFORMAT", "DELETEP", "NAME",
  "ADD", "ID", "FS", "R", "CONT", YY_NULLPTR
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
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     145,    44,    20,   146,     9,    16,    32,    20,   151,    19,
      15,   102,    11,    33,    38,    39,    44,   -91,   -91,   -91,
     -91,   -91,   -91,    45,    47,    48,    49,   146,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,     9,   -91,   -91,    50,
      16,   -91,    58,    65,    32,   -91,   -91,   -91,    20,   -91,
      68,   151,   -91,   -91,   -91,   -91,   -91,    69,    19,   -91,
     -91,   -91,   -91,   -91,    15,   -91,   -91,   -91,    44,    20,
     146,     9,    16,    32,    20,   151,    19,    15,     2,    18,
      46,    70,   -91,   -91,   -91,   -91,    81,    87,    88,    91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
      92,   -91,    93,    98,   -91,   -91,   -91,   -91,    70,   -91,
     -91,   -91,   -91,    70,   -91,   -91,   -91,   -91,   -91,   -91,
      44,   -91,   146,     9,    16,    32,    20,   151,    19,    15,
     -91,   -91,   -91,   103,   100,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   100,   100,   -91,   112,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    77,    78,    79,
      80,    15,    72,     0,     0,     0,     0,    14,    33,    36,
      37,    35,    34,    32,    31,    30,    17,    41,    40,     0,
      18,    61,     0,     0,    19,    46,    47,    45,    20,    71,
       0,    21,    68,    66,    67,    69,    97,     0,    13,    54,
      55,    53,    52,    81,    12,    58,    59,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    75,    74,    73,     0,     0,     0,     0,
      26,    23,    22,    24,    25,    27,    28,    29,    38,    39,
       0,    60,     0,     0,    43,    42,    44,    70,     0,    62,
      65,    63,    64,     0,    50,    48,    49,    51,    57,    56,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      84,    82,    83,    89,    85,    90,    92,    93,    94,    95,
      91,    96,    86,    98,    88,     0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,    61,    71,    86,    67,    77,    97,    95,   104,
     105,   108,   -33,    24,    25,     8,    -2,   -38,   -90,   -24,
     -34,   -23,    12,   -18,    13,   -32,   -43,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    27,    36,    44,    58,    64,    40,    51,    48,
      21,    16,    65,    17,    18,    19,    20,    53,   134,    32,
      45,    33,    34,    35,    41,    47,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    31,    37,    94,    95,    49,    52,    60,    66,    97,
     104,    30,   106,   110,    85,   116,    38,    59,   142,    46,
      54,    55,   117,   143,    84,    93,    15,    28,    29,    25,
     130,   118,    15,    12,    98,    92,    15,    15,    39,    96,
      82,    83,    63,    78,    56,    57,   107,   131,    99,   109,
      42,    90,    91,   101,    39,    43,   115,   105,    12,    13,
      14,    15,   119,   111,   112,    79,   114,    22,    31,    37,
      80,    81,    49,    52,    60,    66,   132,    86,    30,    87,
      88,    89,   100,    38,    59,   116,    46,    54,    55,   110,
     102,   104,   117,   106,    28,    29,   118,   103,    94,    95,
     108,   113,    67,   133,    97,    68,    69,    70,    71,    72,
      73,   135,    74,    75,    76,    77,   136,   137,    85,   138,
      93,    98,   140,   139,   107,   109,   115,   119,    84,   141,
      92,   122,   144,   145,    96,    99,   114,   101,   105,   111,
     112,   146,   123,   128,    82,    83,    90,    91,     1,     2,
       3,     4,     5,     6,   129,     7,     8,     9,    10,   125,
      12,    13,    14,    15,    23,    24,    25,    26,    15,   124,
     127,    25,     0,    39,   121,    50,   120,     0,   126
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,    27,    27,     7,     8,     9,    10,    27,
      44,     3,    44,    51,    16,    58,     4,     9,   108,     6,
       8,     8,    58,   113,    16,    27,    17,     3,     3,    20,
      28,    64,    17,    14,    36,    27,    17,    17,    22,    27,
      16,    16,    27,    32,    25,    26,    48,    29,    36,    51,
      18,    27,    27,    40,    22,    23,    58,    44,    14,    15,
      16,    17,    64,    51,    51,    32,    58,    69,    70,    71,
      32,    32,    74,    75,    76,    77,    30,    32,    70,    32,
      32,    32,    32,    71,    76,   128,    73,    75,    75,   127,
      32,   125,   128,   125,    70,    70,   129,    32,   122,   122,
      32,    32,     0,    33,   122,     3,     4,     5,     6,     7,
       8,    30,    10,    11,    12,    13,    29,    29,   120,    28,
     122,   123,    29,    31,   126,   127,   128,   129,   120,    31,
     122,    70,    29,    33,   122,   123,   128,   124,   125,   127,
     127,    29,    71,    76,   120,   120,   122,   122,     3,     4,
       5,     6,     7,     8,    77,    10,    11,    12,    13,    73,
      14,    15,    16,    17,    18,    19,    20,    21,    17,    72,
      75,    20,    -1,    22,    69,    24,    68,    -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    12,
      13,    35,    14,    15,    16,    17,    45,    47,    48,    49,
      50,    44,    50,    18,    19,    20,    21,    36,    47,    48,
      49,    50,    53,    55,    56,    57,    37,    50,    56,    22,
      41,    58,    18,    23,    38,    54,    58,    59,    43,    50,
      24,    42,    50,    51,    56,    58,    25,    26,    39,    49,
      50,    60,    61,    27,    40,    46,    50,     0,     3,     4,
       5,     6,     7,     8,    10,    11,    12,    13,    32,    32,
      32,    32,    47,    48,    49,    50,    32,    32,    32,    32,
      47,    48,    49,    50,    53,    55,    56,    57,    50,    56,
      32,    58,    32,    32,    54,    58,    59,    50,    32,    50,
      51,    56,    58,    32,    49,    50,    60,    61,    46,    50,
      45,    44,    36,    37,    41,    38,    43,    42,    39,    40,
      28,    29,    30,    33,    52,    30,    29,    29,    28,    31,
      29,    31,    52,    52,    29,    33,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    37,    37,
      37,    37,    38,    38,    38,    38,    38,    38,    39,    39,
      39,    39,    39,    39,    39,    39,    40,    40,    40,    40,
      41,    41,    42,    42,    42,    42,    42,    42,    42,    42,
      43,    43,    44,    45,    45,    45,    45,    45,    45,    45,
      45,    46,    47,    48,    49,    50,    51,    52,    52,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     2,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     3
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
#line 121 "analizador.y"
      {
        mkdiskCmd *c = new mkdiskCmd(); 
        //ASIGNACION DE PARAMETROS
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1583 "parser.cpp"
    break;

  case 3:
#line 128 "analizador.y"
      {
        rmdiskCmd *c = new rmdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1593 "parser.cpp"
    break;

  case 4:
#line 134 "analizador.y"
      {
        fdiskCmd *c = new fdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1603 "parser.cpp"
    break;

  case 5:
#line 140 "analizador.y"
      {
        mountCmd *c = new mountCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1611 "parser.cpp"
    break;

  case 6:
#line 144 "analizador.y"
      {
        unmountCmd *c = new unmountCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1619 "parser.cpp"
    break;

  case 7:
#line 148 "analizador.y"
      {
        mkfsCmd *c = new mkfsCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1627 "parser.cpp"
    break;

  case 8:
#line 152 "analizador.y"
      {
        execCmd *c = new execCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1635 "parser.cpp"
    break;

  case 9:
#line 156 "analizador.y"
      {
        repCmd *c = new repCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1643 "parser.cpp"
    break;

  case 10:
#line 160 "analizador.y"
      {
        mkfileCmd *c = new mkfileCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1651 "parser.cpp"
    break;

  case 11:
#line 164 "analizador.y"
      {
        mkdirCmd *c = new mkdirCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1659 "parser.cpp"
    break;

  case 12:
#line 168 "analizador.y"
      {
        mkdirCmd *c = new mkdirCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1667 "parser.cpp"
    break;

  case 13:
#line 172 "analizador.y"
      {
        mkfileCmd *c = new mkfileCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1675 "parser.cpp"
    break;

  case 14:
#line 176 "analizador.y"
      {
        fdiskCmd *c = new fdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1685 "parser.cpp"
    break;

  case 15:
#line 182 "analizador.y"
      {
        rmdiskCmd *c = new rmdiskCmd();
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1695 "parser.cpp"
    break;

  case 16:
#line 188 "analizador.y"
      {
        mkdiskCmd *c = new mkdiskCmd(); 
        //ASIGNACION DE PARAMETROS
        c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);
        c->execute();
      }
#line 1706 "parser.cpp"
    break;

  case 17:
#line 195 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        mountCmd *c = new mountCmd();c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1715 "parser.cpp"
    break;

  case 18:
#line 200 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        unmountCmd *c = new unmountCmd();c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1724 "parser.cpp"
    break;

  case 19:
#line 205 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        mkfsCmd *c = new mkfsCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1733 "parser.cpp"
    break;

  case 20:
#line 210 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        execCmd *c = new execCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1742 "parser.cpp"
    break;

  case 21:
#line 215 "analizador.y"
      {
        //ASIGNACION DE PARAMETROS
        repCmd *c = new repCmd(); c->assignParameters((yyvsp[0].queueT)->cola,(yyvsp[0].queueT)->size);c->execute();
      }
#line 1751 "parser.cpp"
    break;

  case 22:
#line 220 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1757 "parser.cpp"
    break;

  case 23:
#line 221 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1763 "parser.cpp"
    break;

  case 24:
#line 222 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1769 "parser.cpp"
    break;

  case 25:
#line 223 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1775 "parser.cpp"
    break;

  case 26:
#line 224 "analizador.y"
                              {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1781 "parser.cpp"
    break;

  case 27:
#line 225 "analizador.y"
                            {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1787 "parser.cpp"
    break;

  case 28:
#line 226 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1793 "parser.cpp"
    break;

  case 29:
#line 227 "analizador.y"
                        {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1799 "parser.cpp"
    break;

  case 30:
#line 228 "analizador.y"
               {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1805 "parser.cpp"
    break;

  case 31:
#line 229 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1811 "parser.cpp"
    break;

  case 32:
#line 230 "analizador.y"
                   {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1817 "parser.cpp"
    break;

  case 33:
#line 231 "analizador.y"
                      {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1823 "parser.cpp"
    break;

  case 34:
#line 232 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1829 "parser.cpp"
    break;

  case 35:
#line 233 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1835 "parser.cpp"
    break;

  case 36:
#line 234 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1841 "parser.cpp"
    break;

  case 37:
#line 235 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1847 "parser.cpp"
    break;

  case 38:
#line 237 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1853 "parser.cpp"
    break;

  case 39:
#line 238 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1859 "parser.cpp"
    break;

  case 40:
#line 239 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1865 "parser.cpp"
    break;

  case 41:
#line 240 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1871 "parser.cpp"
    break;

  case 42:
#line 242 "analizador.y"
                     {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1877 "parser.cpp"
    break;

  case 43:
#line 243 "analizador.y"
                              {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1883 "parser.cpp"
    break;

  case 44:
#line 244 "analizador.y"
                      {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1889 "parser.cpp"
    break;

  case 45:
#line 245 "analizador.y"
              {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1895 "parser.cpp"
    break;

  case 46:
#line 246 "analizador.y"
                      {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1901 "parser.cpp"
    break;

  case 47:
#line 247 "analizador.y"
              {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1907 "parser.cpp"
    break;

  case 48:
#line 249 "analizador.y"
                          {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1913 "parser.cpp"
    break;

  case 49:
#line 250 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1919 "parser.cpp"
    break;

  case 50:
#line 251 "analizador.y"
                          {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1925 "parser.cpp"
    break;

  case 51:
#line 252 "analizador.y"
                          {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1931 "parser.cpp"
    break;

  case 52:
#line 253 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1937 "parser.cpp"
    break;

  case 53:
#line 254 "analizador.y"
             {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1943 "parser.cpp"
    break;

  case 54:
#line 255 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1949 "parser.cpp"
    break;

  case 55:
#line 256 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1955 "parser.cpp"
    break;

  case 56:
#line 258 "analizador.y"
                         {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1961 "parser.cpp"
    break;

  case 57:
#line 259 "analizador.y"
                      {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1967 "parser.cpp"
    break;

  case 58:
#line 260 "analizador.y"
             {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1973 "parser.cpp"
    break;

  case 59:
#line 261 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1979 "parser.cpp"
    break;

  case 60:
#line 263 "analizador.y"
                           {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1985 "parser.cpp"
    break;

  case 61:
#line 264 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 1991 "parser.cpp"
    break;

  case 62:
#line 266 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 1997 "parser.cpp"
    break;

  case 63:
#line 267 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2003 "parser.cpp"
    break;

  case 64:
#line 268 "analizador.y"
                     {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2009 "parser.cpp"
    break;

  case 65:
#line 269 "analizador.y"
                       {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2015 "parser.cpp"
    break;

  case 66:
#line 270 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2021 "parser.cpp"
    break;

  case 67:
#line 271 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2027 "parser.cpp"
    break;

  case 68:
#line 272 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2033 "parser.cpp"
    break;

  case 69:
#line 273 "analizador.y"
              {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2039 "parser.cpp"
    break;

  case 70:
#line 275 "analizador.y"
                        {queue *res = new queue();(yyvsp[-1].queueT)->push((yyvsp[0].parametro));res->append((yyvsp[-1].queueT));(yyval.queueT) = res;}
#line 2045 "parser.cpp"
    break;

  case 71:
#line 276 "analizador.y"
                {queue *res = new queue();res->push((yyvsp[0].parametro));(yyval.queueT) = res;}
#line 2051 "parser.cpp"
    break;

  case 72:
#line 279 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2061 "parser.cpp"
    break;

  case 73:
#line 286 "analizador.y"
          { 
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2072 "parser.cpp"
    break;

  case 74:
#line 293 "analizador.y"
          {
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2083 "parser.cpp"
    break;

  case 75:
#line 300 "analizador.y"
          {
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2094 "parser.cpp"
    break;

  case 76:
#line 307 "analizador.y"
          {
            queue *res = new queue();
            (yyvsp[-1].queueT)->push((yyvsp[0].parametro));
            res->append((yyvsp[-1].queueT));
            (yyval.queueT) = res;
          }
#line 2105 "parser.cpp"
    break;

  case 77:
#line 314 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2115 "parser.cpp"
    break;

  case 78:
#line 320 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2125 "parser.cpp"
    break;

  case 79:
#line 326 "analizador.y"
          {
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2135 "parser.cpp"
    break;

  case 80:
#line 332 "analizador.y"
          { 
            queue *res = new queue();
            res->push((yyvsp[0].parametro));
            (yyval.queueT) = res;
          }
#line 2145 "parser.cpp"
    break;

  case 81:
#line 338 "analizador.y"
     {  (yyval.parametro) = make_parameter((yyvsp[0].TEXT),(yyvsp[0].TEXT),0); }
#line 2151 "parser.cpp"
    break;

  case 82:
#line 341 "analizador.y"
           {
            (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
           }
#line 2159 "parser.cpp"
    break;

  case 83:
#line 346 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2167 "parser.cpp"
    break;

  case 84:
#line 351 "analizador.y"
     {
        float res=std::stof((yyvsp[0].TEXT));
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(char*)"",res);
     }
#line 2176 "parser.cpp"
    break;

  case 85:
#line 357 "analizador.y"
    {   
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
        strcpy( (yyvsp[0].TEXT), "" );
    }
#line 2185 "parser.cpp"
    break;

  case 86:
#line 363 "analizador.y"
    {   
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
        strcpy( (yyvsp[0].TEXT), "" );
    }
#line 2194 "parser.cpp"
    break;

  case 87:
#line 369 "analizador.y"
          {
            char res[100];
            strcat(res,(yyvsp[-1].TEXT));
            strcat(res,(yyvsp[0].TEXT));
            (yyvsp[-2].TEXT) = res; 
            (yyval.TEXT) = (yyvsp[-2].TEXT);
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }
#line 2207 "parser.cpp"
    break;

  case 88:
#line 378 "analizador.y"
          {
            char res[100];
            strcat(res,(yyvsp[-1].TEXT));
            strcat(res,(yyvsp[0].TEXT));
            (yyval.TEXT) = res;
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }
#line 2219 "parser.cpp"
    break;

  case 89:
#line 386 "analizador.y"
          {
            char res[100];
            strcat(res,(yyvsp[0].TEXT));
            (yyval.TEXT) = res;
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }
#line 2230 "parser.cpp"
    break;

  case 90:
#line 394 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2238 "parser.cpp"
    break;

  case 91:
#line 399 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2246 "parser.cpp"
    break;

  case 92:
#line 404 "analizador.y"
       {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
       }
#line 2254 "parser.cpp"
    break;

  case 93:
#line 409 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2262 "parser.cpp"
    break;

  case 94:
#line 414 "analizador.y"
    {   
        float res=std::stof((yyvsp[0].TEXT));
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(char*)"",res);
    }
#line 2271 "parser.cpp"
    break;

  case 95:
#line 420 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2279 "parser.cpp"
    break;

  case 96:
#line 425 "analizador.y"
     {  
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0); 
     }
#line 2287 "parser.cpp"
    break;

  case 97:
#line 429 "analizador.y"
     {  (yyval.parametro) = make_parameter((yyvsp[0].TEXT),(yyvsp[0].TEXT),0); }
#line 2293 "parser.cpp"
    break;

  case 98:
#line 432 "analizador.y"
    {   
        (yyval.parametro) = make_parameter((yyvsp[-2].TEXT),(yyvsp[0].TEXT),0);
        strcpy( (yyvsp[0].TEXT), "" );
    }
#line 2302 "parser.cpp"
    break;


#line 2306 "parser.cpp"

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
#line 437 "analizador.y"



void ver(string a){
    YY_BUFFER_STATE buffer = yy_scan_string(a.c_str());
    yyparse();
}

void parse(FILE *file){
    yyin = file;
    yyparse();
    fclose(yyin);
}
