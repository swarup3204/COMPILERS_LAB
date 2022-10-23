/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ass4_20CS30062_20CS30043.y"

    #include <string.h>
    #include <stdio.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(char *);

#line 79 "y.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT_CONSTANT = 259,            /* INT_CONSTANT  */
    FLOAT_CONSTANT = 260,          /* FLOAT_CONSTANT  */
    CHAR_CONSTANT = 261,           /* CHAR_CONSTANT  */
    LEFT_ROUND_BRACKET = 262,      /* LEFT_ROUND_BRACKET  */
    RIGHT_ROUND_BRACKET = 263,     /* RIGHT_ROUND_BRACKET  */
    STRING_LITERAL = 264,          /* STRING_LITERAL  */
    LEFT_SQUARE_BRACKET = 265,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 266,    /* RIGHT_SQUARE_BRACKET  */
    DOT = 267,                     /* DOT  */
    ARROW = 268,                   /* ARROW  */
    UNARY_INCREMENT = 269,         /* UNARY_INCREMENT  */
    UNARY_DECREMENT = 270,         /* UNARY_DECREMENT  */
    COMMA = 271,                   /* COMMA  */
    SIZEOF = 272,                  /* SIZEOF  */
    AMPERSAND = 273,               /* AMPERSAND  */
    ASTERISK = 274,                /* ASTERISK  */
    PLUS = 275,                    /* PLUS  */
    MINUS = 276,                   /* MINUS  */
    TILDE = 277,                   /* TILDE  */
    EXCLAMATION = 278,             /* EXCLAMATION  */
    DIVIDE = 279,                  /* DIVIDE  */
    PERCENT = 280,                 /* PERCENT  */
    LEFT_SHIFT = 281,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 282,             /* RIGHT_SHIFT  */
    LESS_THAN = 283,               /* LESS_THAN  */
    GREATER_THAN = 284,            /* GREATER_THAN  */
    LESS_THAN_EQUAL = 285,         /* LESS_THAN_EQUAL  */
    GREATER_THAN_EQUAL = 286,      /* GREATER_THAN_EQUAL  */
    DOUBLE_EQUAL = 287,            /* DOUBLE_EQUAL  */
    NOT_EQUAL = 288,               /* NOT_EQUAL  */
    PIPE = 289,                    /* PIPE  */
    CARET = 290,                   /* CARET  */
    LOGICAL_AND = 291,             /* LOGICAL_AND  */
    LOGICAL_OR = 292,              /* LOGICAL_OR  */
    QUESTION = 293,                /* QUESTION  */
    COLON = 294,                   /* COLON  */
    EQUAL = 295,                   /* EQUAL  */
    ASTERISK_EQUAL = 296,          /* ASTERISK_EQUAL  */
    DIVIDE_EQUAL = 297,            /* DIVIDE_EQUAL  */
    PERCENT_EQUAL = 298,           /* PERCENT_EQUAL  */
    PLUS_EQUAL = 299,              /* PLUS_EQUAL  */
    MINUS_EQUAL = 300,             /* MINUS_EQUAL  */
    LEFT_SHIFT_EQUAL = 301,        /* LEFT_SHIFT_EQUAL  */
    RIGHT_SHIFT_EQUAL = 302,       /* RIGHT_SHIFT_EQUAL  */
    AMPERSAND_EQUAL = 303,         /* AMPERSAND_EQUAL  */
    CARET_EQUAL = 304,             /* CARET_EQUAL  */
    PIPE_EQUAL = 305,              /* PIPE_EQUAL  */
    SEMI_COLON = 306,              /* SEMI_COLON  */
    EXTERN = 307,                  /* EXTERN  */
    STATIC = 308,                  /* STATIC  */
    AUTO = 309,                    /* AUTO  */
    REGISTER = 310,                /* REGISTER  */
    VOID = 311,                    /* VOID  */
    CHAR = 312,                    /* CHAR  */
    SHORT = 313,                   /* SHORT  */
    INT = 314,                     /* INT  */
    LONG = 315,                    /* LONG  */
    FLOAT = 316,                   /* FLOAT  */
    DOUBLE = 317,                  /* DOUBLE  */
    SIGNED = 318,                  /* SIGNED  */
    UNSIGNED = 319,                /* UNSIGNED  */
    BOOL = 320,                    /* BOOL  */
    COMPLEX = 321,                 /* COMPLEX  */
    IMAGINARY = 322,               /* IMAGINARY  */
    ENUM = 323,                    /* ENUM  */
    CONST = 324,                   /* CONST  */
    RESTRICT = 325,                /* RESTRICT  */
    VOLATILE = 326,                /* VOLATILE  */
    INLINE = 327,                  /* INLINE  */
    ELLIPSIS = 328,                /* ELLIPSIS  */
    CASE = 329,                    /* CASE  */
    DEFAULT = 330,                 /* DEFAULT  */
    LEFT_CURLY_BRACKET = 331,      /* LEFT_CURLY_BRACKET  */
    RIGHT_CURLY_BRACKET = 332,     /* RIGHT_CURLY_BRACKET  */
    IF = 333,                      /* IF  */
    ELSE = 334,                    /* ELSE  */
    SWITCH = 335,                  /* SWITCH  */
    WHILE = 336,                   /* WHILE  */
    DO = 337,                      /* DO  */
    FOR = 338,                     /* FOR  */
    GOTO = 339,                    /* GOTO  */
    CONTINUE = 340,                /* CONTINUE  */
    BREAK = 341,                   /* BREAK  */
    RETURN = 342,                  /* RETURN  */
    UNKNOWN = 343                  /* UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INT_CONSTANT 259
#define FLOAT_CONSTANT 260
#define CHAR_CONSTANT 261
#define LEFT_ROUND_BRACKET 262
#define RIGHT_ROUND_BRACKET 263
#define STRING_LITERAL 264
#define LEFT_SQUARE_BRACKET 265
#define RIGHT_SQUARE_BRACKET 266
#define DOT 267
#define ARROW 268
#define UNARY_INCREMENT 269
#define UNARY_DECREMENT 270
#define COMMA 271
#define SIZEOF 272
#define AMPERSAND 273
#define ASTERISK 274
#define PLUS 275
#define MINUS 276
#define TILDE 277
#define EXCLAMATION 278
#define DIVIDE 279
#define PERCENT 280
#define LEFT_SHIFT 281
#define RIGHT_SHIFT 282
#define LESS_THAN 283
#define GREATER_THAN 284
#define LESS_THAN_EQUAL 285
#define GREATER_THAN_EQUAL 286
#define DOUBLE_EQUAL 287
#define NOT_EQUAL 288
#define PIPE 289
#define CARET 290
#define LOGICAL_AND 291
#define LOGICAL_OR 292
#define QUESTION 293
#define COLON 294
#define EQUAL 295
#define ASTERISK_EQUAL 296
#define DIVIDE_EQUAL 297
#define PERCENT_EQUAL 298
#define PLUS_EQUAL 299
#define MINUS_EQUAL 300
#define LEFT_SHIFT_EQUAL 301
#define RIGHT_SHIFT_EQUAL 302
#define AMPERSAND_EQUAL 303
#define CARET_EQUAL 304
#define PIPE_EQUAL 305
#define SEMI_COLON 306
#define EXTERN 307
#define STATIC 308
#define AUTO 309
#define REGISTER 310
#define VOID 311
#define CHAR 312
#define SHORT 313
#define INT 314
#define LONG 315
#define FLOAT 316
#define DOUBLE 317
#define SIGNED 318
#define UNSIGNED 319
#define BOOL 320
#define COMPLEX 321
#define IMAGINARY 322
#define ENUM 323
#define CONST 324
#define RESTRICT 325
#define VOLATILE 326
#define INLINE 327
#define ELLIPSIS 328
#define CASE 329
#define DEFAULT 330
#define LEFT_CURLY_BRACKET 331
#define RIGHT_CURLY_BRACKET 332
#define IF 333
#define ELSE 334
#define SWITCH 335
#define WHILE 336
#define DO 337
#define FOR 338
#define GOTO 339
#define CONTINUE 340
#define BREAK 341
#define RETURN 342
#define UNKNOWN 343

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "ass4_20CS30062_20CS30043.y"

    int intval;
    double doubleval;
    char charval;
    char* stringval;    

#line 312 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT_CONSTANT = 4,               /* INT_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 5,             /* FLOAT_CONSTANT  */
  YYSYMBOL_CHAR_CONSTANT = 6,              /* CHAR_CONSTANT  */
  YYSYMBOL_LEFT_ROUND_BRACKET = 7,         /* LEFT_ROUND_BRACKET  */
  YYSYMBOL_RIGHT_ROUND_BRACKET = 8,        /* RIGHT_ROUND_BRACKET  */
  YYSYMBOL_STRING_LITERAL = 9,             /* STRING_LITERAL  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 10,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 11,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_DOT = 12,                       /* DOT  */
  YYSYMBOL_ARROW = 13,                     /* ARROW  */
  YYSYMBOL_UNARY_INCREMENT = 14,           /* UNARY_INCREMENT  */
  YYSYMBOL_UNARY_DECREMENT = 15,           /* UNARY_DECREMENT  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_SIZEOF = 17,                    /* SIZEOF  */
  YYSYMBOL_AMPERSAND = 18,                 /* AMPERSAND  */
  YYSYMBOL_ASTERISK = 19,                  /* ASTERISK  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_TILDE = 22,                     /* TILDE  */
  YYSYMBOL_EXCLAMATION = 23,               /* EXCLAMATION  */
  YYSYMBOL_DIVIDE = 24,                    /* DIVIDE  */
  YYSYMBOL_PERCENT = 25,                   /* PERCENT  */
  YYSYMBOL_LEFT_SHIFT = 26,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 27,               /* RIGHT_SHIFT  */
  YYSYMBOL_LESS_THAN = 28,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 29,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL = 30,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 31,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_DOUBLE_EQUAL = 32,              /* DOUBLE_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 33,                 /* NOT_EQUAL  */
  YYSYMBOL_PIPE = 34,                      /* PIPE  */
  YYSYMBOL_CARET = 35,                     /* CARET  */
  YYSYMBOL_LOGICAL_AND = 36,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 37,                /* LOGICAL_OR  */
  YYSYMBOL_QUESTION = 38,                  /* QUESTION  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_EQUAL = 40,                     /* EQUAL  */
  YYSYMBOL_ASTERISK_EQUAL = 41,            /* ASTERISK_EQUAL  */
  YYSYMBOL_DIVIDE_EQUAL = 42,              /* DIVIDE_EQUAL  */
  YYSYMBOL_PERCENT_EQUAL = 43,             /* PERCENT_EQUAL  */
  YYSYMBOL_PLUS_EQUAL = 44,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 45,               /* MINUS_EQUAL  */
  YYSYMBOL_LEFT_SHIFT_EQUAL = 46,          /* LEFT_SHIFT_EQUAL  */
  YYSYMBOL_RIGHT_SHIFT_EQUAL = 47,         /* RIGHT_SHIFT_EQUAL  */
  YYSYMBOL_AMPERSAND_EQUAL = 48,           /* AMPERSAND_EQUAL  */
  YYSYMBOL_CARET_EQUAL = 49,               /* CARET_EQUAL  */
  YYSYMBOL_PIPE_EQUAL = 50,                /* PIPE_EQUAL  */
  YYSYMBOL_SEMI_COLON = 51,                /* SEMI_COLON  */
  YYSYMBOL_EXTERN = 52,                    /* EXTERN  */
  YYSYMBOL_STATIC = 53,                    /* STATIC  */
  YYSYMBOL_AUTO = 54,                      /* AUTO  */
  YYSYMBOL_REGISTER = 55,                  /* REGISTER  */
  YYSYMBOL_VOID = 56,                      /* VOID  */
  YYSYMBOL_CHAR = 57,                      /* CHAR  */
  YYSYMBOL_SHORT = 58,                     /* SHORT  */
  YYSYMBOL_INT = 59,                       /* INT  */
  YYSYMBOL_LONG = 60,                      /* LONG  */
  YYSYMBOL_FLOAT = 61,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 62,                    /* DOUBLE  */
  YYSYMBOL_SIGNED = 63,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 64,                  /* UNSIGNED  */
  YYSYMBOL_BOOL = 65,                      /* BOOL  */
  YYSYMBOL_COMPLEX = 66,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 67,                 /* IMAGINARY  */
  YYSYMBOL_ENUM = 68,                      /* ENUM  */
  YYSYMBOL_CONST = 69,                     /* CONST  */
  YYSYMBOL_RESTRICT = 70,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 71,                  /* VOLATILE  */
  YYSYMBOL_INLINE = 72,                    /* INLINE  */
  YYSYMBOL_ELLIPSIS = 73,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 74,                      /* CASE  */
  YYSYMBOL_DEFAULT = 75,                   /* DEFAULT  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 76,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 77,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_IF = 78,                        /* IF  */
  YYSYMBOL_ELSE = 79,                      /* ELSE  */
  YYSYMBOL_SWITCH = 80,                    /* SWITCH  */
  YYSYMBOL_WHILE = 81,                     /* WHILE  */
  YYSYMBOL_DO = 82,                        /* DO  */
  YYSYMBOL_FOR = 83,                       /* FOR  */
  YYSYMBOL_GOTO = 84,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 85,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 86,                     /* BREAK  */
  YYSYMBOL_RETURN = 87,                    /* RETURN  */
  YYSYMBOL_UNKNOWN = 88,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 89,                  /* $accept  */
  YYSYMBOL_90_primary_expression = 90,     /* primary-expression  */
  YYSYMBOL_constant = 91,                  /* constant  */
  YYSYMBOL_92_postfix_expression = 92,     /* postfix-expression  */
  YYSYMBOL_93_argument_expression_list_opt = 93, /* argument-expression-list-opt  */
  YYSYMBOL_94_argument_expression_list = 94, /* argument-expression-list  */
  YYSYMBOL_95_unary_expression = 95,       /* unary-expression  */
  YYSYMBOL_96_unary_operator = 96,         /* unary-operator  */
  YYSYMBOL_97_cast_expression = 97,        /* cast-expression  */
  YYSYMBOL_98_multiplicative_expression = 98, /* multiplicative-expression  */
  YYSYMBOL_99_additive_expression = 99,    /* additive-expression  */
  YYSYMBOL_100_shift_expression = 100,     /* shift-expression  */
  YYSYMBOL_101_relational_expression = 101, /* relational-expression  */
  YYSYMBOL_102_equality_expression = 102,  /* equality-expression  */
  YYSYMBOL_103_AND_expression = 103,       /* AND-expression  */
  YYSYMBOL_104_exclusive_OR_expression = 104, /* exclusive-OR-expression  */
  YYSYMBOL_105_inclusive_OR_expression = 105, /* inclusive-OR-expression  */
  YYSYMBOL_106_logical_OR_expression = 106, /* logical-OR-expression  */
  YYSYMBOL_107_logical_AND_expression = 107, /* logical-AND-expression  */
  YYSYMBOL_108_conditional_expression = 108, /* conditional-expression  */
  YYSYMBOL_109_assignment_expression = 109, /* assignment-expression  */
  YYSYMBOL_110_assignment_expression_opt = 110, /* assignment-expression-opt  */
  YYSYMBOL_111_assignment_operator = 111,  /* assignment-operator  */
  YYSYMBOL_112_expression_opt = 112,       /* expression-opt  */
  YYSYMBOL_expression = 113,               /* expression  */
  YYSYMBOL_114_constant_expression = 114,  /* constant-expression  */
  YYSYMBOL_declaration = 115,              /* declaration  */
  YYSYMBOL_116_init_declarator_list_opt = 116, /* init-declarator-list-opt  */
  YYSYMBOL_117_declaration_specifiers_opt = 117, /* declaration-specifiers-opt  */
  YYSYMBOL_118_declaration_specifiers = 118, /* declaration-specifiers  */
  YYSYMBOL_119_init_declarator_list = 119, /* init-declarator-list  */
  YYSYMBOL_120_init_declarator = 120,      /* init-declarator  */
  YYSYMBOL_121_storage_class_specifier = 121, /* storage-class-specifier  */
  YYSYMBOL_122_type_specifier = 122,       /* type-specifier  */
  YYSYMBOL_123_specifier_qualifier_list = 123, /* specifier-qualifier-list  */
  YYSYMBOL_124_specifier_qualifier_list_opt = 124, /* specifier-qualifier-list-opt  */
  YYSYMBOL_125_enum_specifier = 125,       /* enum-specifier  */
  YYSYMBOL_126_identifier_opt = 126,       /* identifier-opt  */
  YYSYMBOL_127_enumerator_list = 127,      /* enumerator-list  */
  YYSYMBOL_enumerator = 128,               /* enumerator  */
  YYSYMBOL_129_type_qualifier = 129,       /* type-qualifier  */
  YYSYMBOL_130_function_specifier = 130,   /* function-specifier  */
  YYSYMBOL_declarator = 131,               /* declarator  */
  YYSYMBOL_132_pointer_opt = 132,          /* pointer-opt  */
  YYSYMBOL_133_direct_declarator = 133,    /* direct-declarator  */
  YYSYMBOL_134_identifier_list_opt = 134,  /* identifier-list-opt  */
  YYSYMBOL_pointer = 135,                  /* pointer  */
  YYSYMBOL_136_type_qualifier_list_opt = 136, /* type-qualifier-list-opt  */
  YYSYMBOL_137_type_qualifier_list = 137,  /* type-qualifier-list  */
  YYSYMBOL_138_parameter_type_list = 138,  /* parameter-type-list  */
  YYSYMBOL_139_parameter_list = 139,       /* parameter-list  */
  YYSYMBOL_140_parameter_declaration = 140, /* parameter-declaration  */
  YYSYMBOL_141_identifier_list = 141,      /* identifier-list  */
  YYSYMBOL_142_type_name = 142,            /* type-name  */
  YYSYMBOL_initializer = 143,              /* initializer  */
  YYSYMBOL_144_initializer_list = 144,     /* initializer-list  */
  YYSYMBOL_145_designation_opt = 145,      /* designation-opt  */
  YYSYMBOL_designation = 146,              /* designation  */
  YYSYMBOL_147_designator_list = 147,      /* designator-list  */
  YYSYMBOL_designator = 148,               /* designator  */
  YYSYMBOL_statement = 149,                /* statement  */
  YYSYMBOL_150_labeled_statement = 150,    /* labeled-statement  */
  YYSYMBOL_151_compound_statement = 151,   /* compound-statement  */
  YYSYMBOL_152_block_item_list_opt = 152,  /* block-item-list-opt  */
  YYSYMBOL_153_block_item_list = 153,      /* block-item-list  */
  YYSYMBOL_154_block_item = 154,           /* block-item  */
  YYSYMBOL_155_expression_statement = 155, /* expression-statement  */
  YYSYMBOL_156_selection_statement = 156,  /* selection-statement  */
  YYSYMBOL_157_iteration_statement = 157,  /* iteration-statement  */
  YYSYMBOL_158_jump_statement = 158,       /* jump-statement  */
  YYSYMBOL_159_translation_unit = 159,     /* translation-unit  */
  YYSYMBOL_160_external_declaration = 160, /* external-declaration  */
  YYSYMBOL_161_function_definition = 161,  /* function-definition  */
  YYSYMBOL_162_declaration_list_opt = 162, /* declaration-list-opt  */
  YYSYMBOL_163_declaration_list = 163      /* declaration-list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int16 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   752

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   343


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   113,   115,   117,   122,   124,   126,   130,
     132,   134,   136,   138,   140,   142,   144,   146,   150,   153,
     155,   157,   161,   163,   165,   167,   169,   171,   174,   176,
     178,   180,   182,   184,   188,   190,   194,   196,   198,   200,
     204,   206,   208,   211,   213,   215,   218,   220,   222,   224,
     226,   229,   231,   233,   236,   238,   241,   243,   246,   248,
     251,   253,   256,   258,   261,   263,   266,   268,   271,   274,
     276,   278,   280,   282,   284,   286,   288,   290,   292,   294,
     296,   299,   302,   305,   307,   310,   314,   318,   321,   323,
     326,   328,   330,   332,   334,   337,   339,   342,   344,   348,
     350,   352,   354,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   386,   388,   391,   394,
     396,   398,   400,   403,   406,   408,   410,   414,   416,   420,
     422,   424,   428,   431,   434,   437,   439,   441,   443,   445,
     447,   449,   451,   453,   456,   459,   461,   463,   466,   469,
     471,   473,   476,   478,   481,   483,   486,   488,   492,   494,
     498,   501,   503,   505,   508,   510,   513,   516,   518,   521,
     523,   526,   528,   533,   535,   537,   539,   541,   543,   546,
     548,   550,   553,   556,   559,   561,   563,   566,   568,   571,
     574,   576,   578,   581,   583,   585,   587,   590,   592,   594,
     596,   600,   602,   605,   607,   610,   613,   616,   618,   620
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_CONSTANT", "FLOAT_CONSTANT", "CHAR_CONSTANT", "LEFT_ROUND_BRACKET",
  "RIGHT_ROUND_BRACKET", "STRING_LITERAL", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "DOT", "ARROW", "UNARY_INCREMENT",
  "UNARY_DECREMENT", "COMMA", "SIZEOF", "AMPERSAND", "ASTERISK", "PLUS",
  "MINUS", "TILDE", "EXCLAMATION", "DIVIDE", "PERCENT", "LEFT_SHIFT",
  "RIGHT_SHIFT", "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUAL",
  "GREATER_THAN_EQUAL", "DOUBLE_EQUAL", "NOT_EQUAL", "PIPE", "CARET",
  "LOGICAL_AND", "LOGICAL_OR", "QUESTION", "COLON", "EQUAL",
  "ASTERISK_EQUAL", "DIVIDE_EQUAL", "PERCENT_EQUAL", "PLUS_EQUAL",
  "MINUS_EQUAL", "LEFT_SHIFT_EQUAL", "RIGHT_SHIFT_EQUAL",
  "AMPERSAND_EQUAL", "CARET_EQUAL", "PIPE_EQUAL", "SEMI_COLON", "EXTERN",
  "STATIC", "AUTO", "REGISTER", "VOID", "CHAR", "SHORT", "INT", "LONG",
  "FLOAT", "DOUBLE", "SIGNED", "UNSIGNED", "BOOL", "COMPLEX", "IMAGINARY",
  "ENUM", "CONST", "RESTRICT", "VOLATILE", "INLINE", "ELLIPSIS", "CASE",
  "DEFAULT", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "UNKNOWN", "$accept", "primary-expression", "constant",
  "postfix-expression", "argument-expression-list-opt",
  "argument-expression-list", "unary-expression", "unary-operator",
  "cast-expression", "multiplicative-expression", "additive-expression",
  "shift-expression", "relational-expression", "equality-expression",
  "AND-expression", "exclusive-OR-expression", "inclusive-OR-expression",
  "logical-OR-expression", "logical-AND-expression",
  "conditional-expression", "assignment-expression",
  "assignment-expression-opt", "assignment-operator", "expression-opt",
  "expression", "constant-expression", "declaration",
  "init-declarator-list-opt", "declaration-specifiers-opt",
  "declaration-specifiers", "init-declarator-list", "init-declarator",
  "storage-class-specifier", "type-specifier", "specifier-qualifier-list",
  "specifier-qualifier-list-opt", "enum-specifier", "identifier-opt",
  "enumerator-list", "enumerator", "type-qualifier", "function-specifier",
  "declarator", "pointer-opt", "direct-declarator", "identifier-list-opt",
  "pointer", "type-qualifier-list-opt", "type-qualifier-list",
  "parameter-type-list", "parameter-list", "parameter-declaration",
  "identifier-list", "type-name", "initializer", "initializer-list",
  "designation-opt", "designation", "designator-list", "designator",
  "statement", "labeled-statement", "compound-statement",
  "block-item-list-opt", "block-item-list", "block-item",
  "expression-statement", "selection-statement", "iteration-statement",
  "jump-statement", "translation-unit", "external-declaration",
  "function-definition", "declaration-list-opt", "declaration-list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-208)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     601,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,    84,  -214,  -214,
    -214,  -214,  -214,     4,   601,   601,  -214,   601,   601,   398,
    -214,  -214,    15,    31,   106,    54,   111,  -214,   531,    61,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   131,  -214,
     117,   106,  -214,   117,   256,  -214,     4,    62,   601,  -214,
     117,   149,   118,    -7,  -214,  -214,  -214,  -214,   123,  -214,
    -214,  -214,  -214,   559,  -214,   490,   490,   671,  -214,  -214,
    -214,  -214,  -214,  -214,    91,  -214,  -214,   133,   154,   692,
    -214,   125,    22,    39,   142,   148,   147,   172,   134,   152,
     177,  -214,  -214,  -214,   234,  -214,  -214,   206,   489,   -31,
     692,     7,  -214,  -214,    36,   681,  -214,   681,   209,   559,
    -214,  -214,   559,  -214,   692,   215,    -4,   256,  -214,    21,
    -214,   692,   692,   216,   218,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   692,  -214,
    -214,   692,   692,   692,   692,   692,   692,   692,   692,   692,
     692,   692,   692,   692,   692,   692,   692,   692,   692,   692,
     183,   692,   188,   221,   222,   223,   340,   224,   230,   184,
     185,   692,   193,   229,  -214,  -214,  -214,  -214,   170,   319,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,    43,   242,   250,
     248,  -214,   251,   106,   713,    29,  -214,  -214,  -214,  -214,
    -214,   692,  -214,  -214,  -214,   425,   258,   260,   261,  -214,
       8,  -214,  -214,  -214,  -214,   272,   265,  -214,    93,  -214,
    -214,  -214,  -214,  -214,  -214,   125,   125,    22,    22,    39,
      39,    39,    39,   142,   142,   148,   147,   172,   177,    -2,
     134,   340,   243,   340,   692,   692,   692,   202,   468,   233,
    -214,  -214,   262,  -214,  -214,  -214,  -214,  -214,  -214,   579,
     282,   692,   296,  -214,   316,   692,  -214,    91,  -214,   253,
     253,  -214,  -214,   256,  -214,   692,  -214,   692,  -214,   340,
    -214,    37,    41,    59,   323,   280,   692,  -214,  -214,  -214,
    -214,  -214,   324,  -214,  -214,   337,    -3,  -214,  -214,  -214,
    -214,   340,   340,   340,   692,   692,   299,  -214,  -214,     9,
    -214,   273,  -214,  -214,    73,   300,   692,  -214,   340,   302,
     692,   348,  -214,  -214,   356,   340,   340,  -214,  -214
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   124,   129,   130,
     131,   132,   204,   135,    90,    90,   115,    90,    90,     0,
     201,   203,   122,     0,   149,     0,    87,    95,    97,     0,
     134,    91,    89,    92,    93,    94,     1,   202,     0,   150,
     146,   148,    86,   135,     0,   208,   135,     0,   206,   136,
     135,   133,   127,     0,   125,   147,   151,    96,    97,     2,
       6,     7,     8,     0,     4,     0,     0,     0,    28,    29,
      30,    31,    32,    33,   167,     9,     3,    22,    34,     0,
      36,    40,    43,    46,    51,    54,    56,    58,    62,    64,
      60,    66,   161,    98,    82,   205,   209,     0,   145,   149,
       0,     0,   120,    83,     0,   119,   160,   119,     0,     0,
      23,    24,     0,    26,     0,     0,     0,     0,   166,     0,
     169,    19,     0,     0,     0,    14,    15,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    34,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,    82,     0,    81,   187,   188,   173,   174,     0,    82,
     185,   175,   176,   177,   178,   137,   158,   135,     0,     0,
     152,   154,   144,   149,    69,   148,    85,   128,   121,   126,
       5,     0,   118,   116,   117,     0,     0,     0,     0,   172,
     167,   162,   164,   168,   170,     0,    18,    20,     0,    12,
      13,    67,    37,    38,    39,    41,    42,    44,    45,    47,
      48,    49,    50,    52,    53,    55,    57,    59,    61,     0,
      63,    82,     0,    82,     0,     0,     0,     0,    82,     0,
     198,   199,     0,   189,   182,   186,   156,   143,   142,     0,
       0,     0,    29,    68,     0,     0,    84,   167,    35,     0,
      27,   171,   163,     0,    11,     0,    10,     0,   179,    82,
     181,     0,     0,     0,     0,     0,    82,   197,   200,   153,
     155,   159,     0,   141,   138,     0,     0,   165,    21,    65,
     180,    82,    82,    82,     0,    82,     0,   139,   140,   167,
      16,   190,   192,   193,     0,     0,    82,    17,    82,     0,
      82,     0,   191,   194,     0,    82,    82,   196,   195
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,  -214,  -214,  -214,   -41,  -214,   -74,    51,
      53,    27,    49,   201,   203,   200,   198,  -214,   225,  -108,
     -51,  -214,  -214,  -164,   -72,  -113,   -32,  -214,   127,     0,
    -214,   317,  -214,   -27,   -85,   252,  -214,  -214,  -214,   297,
      20,  -214,   -19,  -214,  -214,  -214,   357,  -101,   301,  -214,
    -214,   140,  -214,    45,  -122,   135,  -213,  -214,  -214,   284,
    -120,  -214,   354,  -214,  -214,   228,  -214,  -214,  -214,  -214,
    -214,   390,  -214,  -214,  -214
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    85,    86,    87,   225,   226,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     113,   274,   148,   182,   183,   207,    22,    35,    41,    56,
      36,    37,    24,    25,   116,   213,    26,    33,    63,    64,
      27,    28,    68,    39,    61,   198,    40,    50,    51,   199,
     200,   201,   202,   118,   103,   126,   127,   128,   129,   130,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      29,    30,    31,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   114,   206,   102,    38,   222,    55,   283,   204,   111,
      62,   218,   220,   319,   211,   150,   206,   262,   124,   124,
     125,   125,   203,    34,    42,    42,   106,    42,    42,    23,
     212,   124,   212,   125,   120,   121,   123,   287,    18,    19,
      20,   107,   154,   155,   210,   311,   115,   114,   149,   312,
     114,  -157,   211,   211,    49,   -88,   257,   211,   252,  -157,
     228,   223,    34,   206,    59,   156,   157,   313,    60,   149,
     112,    66,   184,   221,   320,   211,   102,   232,   233,   234,
     227,   329,   275,   149,   208,   282,   327,    32,   115,   211,
     115,  -123,   115,   117,   295,   115,   249,   231,    18,    19,
      20,   124,   271,   125,   286,    52,   283,    48,   197,   211,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,    53,   149,    49,
     149,   288,   316,   290,    62,   117,    34,   117,   104,   117,
     131,   278,   117,   132,   151,   133,   134,   135,   136,   152,
     153,   325,    43,   273,    44,    45,   108,   184,   110,   109,
     276,   307,   331,    54,   216,   164,   334,   217,   166,   310,
     158,   159,   160,   161,   149,    18,    19,    20,   266,   309,
     162,   163,   291,   292,   293,   239,   240,   241,   242,   167,
     168,   321,   322,   323,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   235,   236,   165,   332,   237,
     238,   243,   244,   169,   195,   337,   338,   215,   219,   229,
     302,   230,   251,    49,   305,    66,   296,   253,   254,   255,
     256,   258,   102,   259,   308,   260,   261,   170,    70,    71,
      72,    73,   324,    74,   263,   211,   149,   264,    75,    76,
     267,    77,    78,    79,    80,    81,    82,    83,   268,    69,
      70,    71,    72,    73,   269,    74,   279,   270,   280,   197,
      75,    76,   281,    77,    78,    79,    80,    81,    82,    83,
     284,   285,   289,   294,   297,   301,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   303,   171,   172,
     104,  -184,   173,   298,   174,   175,   176,   177,   178,   179,
     180,   181,   170,    70,    71,    72,    73,   304,    74,   277,
     314,   315,    84,    75,    76,   317,    77,    78,    79,    80,
      81,    82,    83,   170,    70,    71,    72,    73,   318,    74,
     326,   330,   328,   333,    75,    76,   335,    77,    78,    79,
      80,    81,    82,    83,   336,   245,   247,   250,   246,   214,
      67,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   248,   171,   172,   104,  -183,   173,    46,   174,
     175,   176,   177,   178,   179,   180,   181,    65,   209,   300,
     205,   105,   306,   224,   171,   172,   104,   265,   173,    47,
     174,   175,   176,   177,   178,   179,   180,   181,    69,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    69,    70,    71,    72,    73,     0,    74,     0,     0,
       0,     0,    75,    76,     0,    77,    78,    79,    80,    81,
      82,    83,   196,    69,    70,    71,    72,   119,     0,    74,
       0,   277,     0,     0,    75,    76,     0,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    69,    70,    71,    72,    73,     0,    74,     0,
       0,    54,     0,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,  -207,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   299,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    69,    70,    71,    72,   122,     0,
      74,     0,     0,     0,     0,    75,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    69,    70,    71,    72,    73,
       0,    74,     0,     0,     0,     0,    75,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    69,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,    75,    76,     0,
      77,    78,   272,    80,    81,    82,    83,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    73,   110,    54,    23,   127,    38,   220,   109,    16,
       3,   124,    16,    16,    16,    89,   124,   181,    10,    10,
      12,    12,    53,    19,    24,    25,    58,    27,    28,    29,
     115,    10,   117,    12,    75,    76,    77,    39,    69,    70,
      71,    60,    20,    21,     8,     8,    73,   119,    89,     8,
     122,     8,    16,    16,    34,    51,   176,    16,   171,    16,
     132,    40,    19,   171,     3,    26,    27,     8,     7,   110,
      77,    51,   104,    77,    77,    16,   127,   151,   152,   153,
     131,     8,    53,   124,    77,    77,    77,     3,   115,    16,
     117,    76,   119,    73,   258,   122,   168,   148,    69,    70,
      71,    10,   203,    12,    11,    51,   319,    76,   108,    16,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    16,   169,   109,
     171,   251,   296,   253,     3,   115,    19,   117,    76,   119,
       7,   215,   122,    10,    19,    12,    13,    14,    15,    24,
      25,   315,    25,   204,    27,    28,     7,   189,    40,    10,
     211,   283,   326,    40,   119,    18,   330,   122,    34,   289,
      28,    29,    30,    31,   215,    69,    70,    71,   197,   287,
      32,    33,   254,   255,   256,   158,   159,   160,   161,    37,
      38,   311,   312,   313,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   154,   155,    35,   328,   156,
     157,   162,   163,    36,     8,   335,   336,     8,     3,     3,
     271,     3,    39,   203,   275,   205,   258,    39,     7,     7,
       7,     7,   283,     3,   285,    51,    51,     3,     4,     5,
       6,     7,   314,     9,    51,    16,   287,    77,    14,    15,
       8,    17,    18,    19,    20,    21,    22,    23,     8,     3,
       4,     5,     6,     7,    16,     9,     8,    16,     8,   269,
      14,    15,    11,    17,    18,    19,    20,    21,    22,    23,
       8,    16,    39,    81,    51,     3,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    11,    74,    75,
      76,    77,    78,    51,    80,    81,    82,    83,    84,    85,
      86,    87,     3,     4,     5,     6,     7,    11,     9,    76,
       7,    51,    76,    14,    15,    11,    17,    18,    19,    20,
      21,    22,    23,     3,     4,     5,     6,     7,    11,     9,
      51,    51,    79,    51,    14,    15,     8,    17,    18,    19,
      20,    21,    22,    23,     8,   164,   166,   169,   165,   117,
      53,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,   167,    74,    75,    76,    77,    78,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    50,   111,   269,
     109,    57,   277,   129,    74,    75,    76,   189,    78,    29,
      80,    81,    82,    83,    84,    85,    86,    87,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,    -1,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,     3,     3,     4,     5,     6,     7,    -1,     9,
      -1,    76,    -1,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,     7,    -1,     9,    -1,
      -1,    40,    -1,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,     7,    -1,
       9,    -1,    -1,    -1,    -1,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    -1,    -1,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,     3,     4,     5,     6,
       7,    -1,     9,    -1,    -1,    -1,    -1,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,   115,   118,   121,   122,   125,   129,   130,   159,
     160,   161,     3,   126,    19,   116,   119,   120,   131,   132,
     135,   117,   118,   117,   117,   117,     0,   160,    76,   129,
     136,   137,    51,    16,    40,   115,   118,   162,   163,     3,
       7,   133,     3,   127,   128,   135,   129,   120,   131,     3,
       4,     5,     6,     7,     9,    14,    15,    17,    18,    19,
      20,    21,    22,    23,    76,    90,    91,    92,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   143,    76,   151,   115,   131,     7,    10,
      40,    16,    77,   109,   113,   122,   123,   129,   142,     7,
      95,    95,     7,    95,    10,    12,   144,   145,   146,   147,
     148,     7,    10,    12,    13,    14,    15,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   111,    95,
      97,    19,    24,    25,    20,    21,    26,    27,    28,    29,
      30,    31,    32,    33,    18,    35,    34,    37,    38,    36,
       3,    74,    75,    78,    80,    81,    82,    83,    84,    85,
      86,    87,   112,   113,   115,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     8,     3,   118,   134,   138,
     139,   140,   141,    53,   136,   137,   108,   114,    77,   128,
       8,    16,   123,   124,   124,     8,   142,   142,   114,     3,
      16,    77,   143,    40,   148,    93,    94,   109,   113,     3,
       3,   109,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   101,   101,   102,   103,   104,   107,   113,
     105,    39,   114,    39,     7,     7,     7,   149,     7,     3,
      51,    51,   112,    51,    77,   154,   131,     8,     8,    16,
      16,   136,    19,   109,   110,    53,   109,    76,    97,     8,
       8,    11,    77,   145,     8,    16,    11,    39,   149,    39,
     149,   113,   113,   113,    81,   112,   115,    51,    51,    73,
     140,     3,   109,    11,    11,   109,   144,   143,   109,   108,
     149,     8,     8,     8,     7,    51,   112,    11,    11,    16,
      77,   149,   149,   149,   113,   112,    51,    77,    79,     8,
      51,   112,   149,    51,   112,     8,     8,   149,   149
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    98,    98,
      99,    99,    99,   100,   100,   100,   101,   101,   101,   101,
     101,   102,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   112,   112,   113,   113,   114,   115,   116,   116,   117,
     117,   118,   118,   118,   118,   119,   119,   120,   120,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   130,   131,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   139,   139,   140,   140,   141,   141,
     142,   143,   143,   143,   144,   144,   145,   145,   146,   147,
     147,   148,   148,   149,   149,   149,   149,   149,   149,   150,
     150,   150,   151,   152,   152,   153,   153,   154,   154,   155,
     156,   156,   156,   157,   157,   157,   157,   158,   158,   158,
     158,   159,   159,   160,   160,   161,   162,   162,   163,   163
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     4,     3,     3,     2,     2,     6,     7,     1,     0,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     3,     1,     3,     1,     0,     1,
       0,     2,     2,     2,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     0,
       5,     6,     2,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     0,     1,     3,     5,     6,
       6,     5,     4,     4,     1,     0,     2,     3,     1,     0,
       1,     2,     1,     3,     1,     3,     2,     1,     1,     3,
       1,     1,     3,     4,     2,     4,     1,     0,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     3,     1,     0,     1,     2,     1,     1,     2,
       5,     7,     5,     5,     7,     9,     8,     3,     2,     2,
       3,     1,     2,     1,     1,     4,     1,     0,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary-expression: IDENTIFIER  */
#line 112 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tprimary-expression -> identifier(%s)\n",(yyvsp[0].stringval));}
#line 1812 "y.tab.c"
    break;

  case 3: /* primary-expression: constant  */
#line 114 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tprimary-expression -> constant\n");}
#line 1818 "y.tab.c"
    break;

  case 4: /* primary-expression: STRING_LITERAL  */
#line 116 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tprimary-expression -> string-literal(%s)\n",(yyvsp[0].stringval));}
#line 1824 "y.tab.c"
    break;

  case 5: /* primary-expression: LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET  */
#line 118 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tprimary-expression -> %s expression %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 1830 "y.tab.c"
    break;

  case 6: /* constant: INT_CONSTANT  */
#line 123 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tconstant -> integer-constant(%d)\n",(yyvsp[0].intval));}
#line 1836 "y.tab.c"
    break;

  case 7: /* constant: FLOAT_CONSTANT  */
#line 125 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tconstant -> float-constant(%f)\n",(yyvsp[0].doubleval));}
#line 1842 "y.tab.c"
    break;

  case 8: /* constant: CHAR_CONSTANT  */
#line 127 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tconstant -> char-constant(%c)\n",(yyvsp[0].charval));}
#line 1848 "y.tab.c"
    break;

  case 9: /* postfix-expression: primary-expression  */
#line 131 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> primary-expression\n");}
#line 1854 "y.tab.c"
    break;

  case 10: /* postfix-expression: postfix-expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET  */
#line 133 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> postfix-expression %s expression %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 1860 "y.tab.c"
    break;

  case 11: /* postfix-expression: postfix-expression LEFT_ROUND_BRACKET argument-expression-list-opt RIGHT_ROUND_BRACKET  */
#line 135 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> postfix-expression %s argument-expression-list-opt %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 1866 "y.tab.c"
    break;

  case 12: /* postfix-expression: postfix-expression DOT IDENTIFIER  */
#line 137 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> postfix-expression %s identifier(%s)\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 1872 "y.tab.c"
    break;

  case 13: /* postfix-expression: postfix-expression ARROW IDENTIFIER  */
#line 139 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> postfix-expression %s identifier(%s)\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 1878 "y.tab.c"
    break;

  case 14: /* postfix-expression: postfix-expression UNARY_INCREMENT  */
#line 141 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> postfix-expression %s\n",(yyvsp[0].stringval));}
#line 1884 "y.tab.c"
    break;

  case 15: /* postfix-expression: postfix-expression UNARY_DECREMENT  */
#line 143 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> postfix-expression %s\n",(yyvsp[0].stringval));}
#line 1890 "y.tab.c"
    break;

  case 16: /* postfix-expression: LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET initializer-list RIGHT_CURLY_BRACKET  */
#line 145 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> %s type-name %s %s initializer-list %s\n",(yyvsp[-5].stringval),(yyvsp[-3].stringval),(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 1896 "y.tab.c"
    break;

  case 17: /* postfix-expression: LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET initializer-list COMMA RIGHT_CURLY_BRACKET  */
#line 147 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpostfix-expression -> %s type-name %s %s initializer-list %s %s\n",(yyvsp[-6].stringval),(yyvsp[-4].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 1902 "y.tab.c"
    break;

  case 18: /* argument-expression-list-opt: argument-expression-list  */
#line 151 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\targument-expression-list-opt -> argument-expression-list\n");}
#line 1908 "y.tab.c"
    break;

  case 19: /* argument-expression-list-opt: %empty  */
#line 153 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\targument-expression-list-opt -> epsilon\n");}
#line 1914 "y.tab.c"
    break;

  case 20: /* argument-expression-list: assignment-expression  */
#line 156 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\targument-expression-list -> assignment-expression\n");}
#line 1920 "y.tab.c"
    break;

  case 21: /* argument-expression-list: argument-expression-list COMMA assignment-expression  */
#line 158 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\targument-expression-list -> argument-expression-list %s assignment-expression\n",(yyvsp[-1].stringval));}
#line 1926 "y.tab.c"
    break;

  case 22: /* unary-expression: postfix-expression  */
#line 162 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-expression -> postfix-expression\n");}
#line 1932 "y.tab.c"
    break;

  case 23: /* unary-expression: UNARY_INCREMENT unary-expression  */
#line 164 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-expression -> %s unary-expression\n",(yyvsp[-1].stringval));}
#line 1938 "y.tab.c"
    break;

  case 24: /* unary-expression: UNARY_DECREMENT unary-expression  */
#line 166 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-expression -> %s unary-expression\n",(yyvsp[-1].stringval));}
#line 1944 "y.tab.c"
    break;

  case 25: /* unary-expression: unary-operator cast-expression  */
#line 168 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-expression -> unary-operator cast-expression\n");}
#line 1950 "y.tab.c"
    break;

  case 26: /* unary-expression: SIZEOF unary-expression  */
#line 170 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-expression -> %s unary-expression\n",(yyvsp[-1].stringval));}
#line 1956 "y.tab.c"
    break;

  case 27: /* unary-expression: SIZEOF LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET  */
#line 172 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-expression -> %s %s type-name %s\n",(yyvsp[-3].stringval),(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 1962 "y.tab.c"
    break;

  case 28: /* unary-operator: AMPERSAND  */
#line 175 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-operator -> %s\n",(yyvsp[0].stringval));}
#line 1968 "y.tab.c"
    break;

  case 29: /* unary-operator: ASTERISK  */
#line 177 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-operator -> %s\n",(yyvsp[0].stringval));}
#line 1974 "y.tab.c"
    break;

  case 30: /* unary-operator: PLUS  */
#line 179 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-operator -> %s\n",(yyvsp[0].stringval));}
#line 1980 "y.tab.c"
    break;

  case 31: /* unary-operator: MINUS  */
#line 181 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-operator -> %s\n",(yyvsp[0].stringval));}
#line 1986 "y.tab.c"
    break;

  case 32: /* unary-operator: TILDE  */
#line 183 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-operator -> %s\n",(yyvsp[0].stringval));}
#line 1992 "y.tab.c"
    break;

  case 33: /* unary-operator: EXCLAMATION  */
#line 185 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tunary-operator -> %s\n",(yyvsp[0].stringval));}
#line 1998 "y.tab.c"
    break;

  case 34: /* cast-expression: unary-expression  */
#line 189 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tcast-expression -> unary-expression\n");}
#line 2004 "y.tab.c"
    break;

  case 35: /* cast-expression: LEFT_ROUND_BRACKET type-name RIGHT_ROUND_BRACKET cast-expression  */
#line 191 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tcast-expression -> %s type-name %s cast-expression\n",(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2010 "y.tab.c"
    break;

  case 36: /* multiplicative-expression: cast-expression  */
#line 195 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tmultiplicative-expression -> cast-expression\n");}
#line 2016 "y.tab.c"
    break;

  case 37: /* multiplicative-expression: multiplicative-expression ASTERISK cast-expression  */
#line 197 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tmultiplicative-expression -> multiplicative-expression %s cast-expression\n",(yyvsp[-1].stringval));}
#line 2022 "y.tab.c"
    break;

  case 38: /* multiplicative-expression: multiplicative-expression DIVIDE cast-expression  */
#line 199 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tmultiplicative-expression -> multiplicative-expression %s cast-expression\n",(yyvsp[-1].stringval));}
#line 2028 "y.tab.c"
    break;

  case 39: /* multiplicative-expression: multiplicative-expression PERCENT cast-expression  */
#line 201 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tmultiplicative-expression -> multiplicative-expression %s cast-expression\n",(yyvsp[-1].stringval));}
#line 2034 "y.tab.c"
    break;

  case 40: /* additive-expression: multiplicative-expression  */
#line 205 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tadditive-expression -> multiplicative-expression\n");}
#line 2040 "y.tab.c"
    break;

  case 41: /* additive-expression: additive-expression PLUS multiplicative-expression  */
#line 207 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tadditive-expression -> additive-expression %s multiplicative-expression\n",(yyvsp[-1].stringval));}
#line 2046 "y.tab.c"
    break;

  case 42: /* additive-expression: additive-expression MINUS multiplicative-expression  */
#line 209 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tadditive-expression -> additive-expression %s multiplicative-expression\n",(yyvsp[-1].stringval));}
#line 2052 "y.tab.c"
    break;

  case 43: /* shift-expression: additive-expression  */
#line 212 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tshift-expression -> additive-expression\n");}
#line 2058 "y.tab.c"
    break;

  case 44: /* shift-expression: shift-expression LEFT_SHIFT additive-expression  */
#line 214 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tshift-expression -> shift-expression %s additive-expression\n",(yyvsp[-1].stringval));}
#line 2064 "y.tab.c"
    break;

  case 45: /* shift-expression: shift-expression RIGHT_SHIFT additive-expression  */
#line 216 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tshift-expression -> shift-expression %s additive-expression\n",(yyvsp[-1].stringval));}
#line 2070 "y.tab.c"
    break;

  case 46: /* relational-expression: shift-expression  */
#line 219 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\trelational-expression -> shift-expression\n");}
#line 2076 "y.tab.c"
    break;

  case 47: /* relational-expression: relational-expression LESS_THAN shift-expression  */
#line 221 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",(yyvsp[-1].stringval));}
#line 2082 "y.tab.c"
    break;

  case 48: /* relational-expression: relational-expression GREATER_THAN shift-expression  */
#line 223 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",(yyvsp[-1].stringval));}
#line 2088 "y.tab.c"
    break;

  case 49: /* relational-expression: relational-expression LESS_THAN_EQUAL shift-expression  */
#line 225 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",(yyvsp[-1].stringval));}
#line 2094 "y.tab.c"
    break;

  case 50: /* relational-expression: relational-expression GREATER_THAN_EQUAL shift-expression  */
#line 227 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\trelational-expression -> relational-expression %s shift-expression\n",(yyvsp[-1].stringval));}
#line 2100 "y.tab.c"
    break;

  case 51: /* equality-expression: relational-expression  */
#line 230 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tequality-expression -> relational-expression\n");}
#line 2106 "y.tab.c"
    break;

  case 52: /* equality-expression: equality-expression DOUBLE_EQUAL relational-expression  */
#line 232 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tequality-expression -> equality-expression %s relational-expression\n",(yyvsp[-1].stringval));}
#line 2112 "y.tab.c"
    break;

  case 53: /* equality-expression: equality-expression NOT_EQUAL relational-expression  */
#line 234 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tequality-expression -> equality-expression %s relational-expression\n",(yyvsp[-1].stringval));}
#line 2118 "y.tab.c"
    break;

  case 54: /* AND-expression: equality-expression  */
#line 237 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tAND-expression -> equality-expression\n");}
#line 2124 "y.tab.c"
    break;

  case 55: /* AND-expression: AND-expression AMPERSAND equality-expression  */
#line 239 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tAND-expression -> AND-expression %s equality-expression\n",(yyvsp[-1].stringval));}
#line 2130 "y.tab.c"
    break;

  case 56: /* exclusive-OR-expression: AND-expression  */
#line 242 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texclusive-OR-expression -> AND-expression\n");}
#line 2136 "y.tab.c"
    break;

  case 57: /* exclusive-OR-expression: exclusive-OR-expression CARET AND-expression  */
#line 244 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texclusive-OR-expression -> exclusive-OR-expression %s AND-expression\n",(yyvsp[-1].stringval));}
#line 2142 "y.tab.c"
    break;

  case 58: /* inclusive-OR-expression: exclusive-OR-expression  */
#line 247 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinclusive-OR-expression -> exclusive-OR-expression\n");}
#line 2148 "y.tab.c"
    break;

  case 59: /* inclusive-OR-expression: inclusive-OR-expression PIPE exclusive-OR-expression  */
#line 249 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinclusive-OR-expression -> inclusive-OR-expression %s exclusive-OR-expression\n",(yyvsp[-1].stringval));}
#line 2154 "y.tab.c"
    break;

  case 60: /* logical-OR-expression: logical-AND-expression  */
#line 252 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tlogical-OR-expression -> logical-AND-expression\n");}
#line 2160 "y.tab.c"
    break;

  case 61: /* logical-OR-expression: logical-OR-expression LOGICAL_OR logical-AND-expression  */
#line 254 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tlogical-OR-expression -> logical-OR-expression %s logical-AND-expression\n",(yyvsp[-1].stringval));}
#line 2166 "y.tab.c"
    break;

  case 62: /* logical-AND-expression: inclusive-OR-expression  */
#line 257 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tlogical-AND-expression -> inclusive-OR-expression\n");}
#line 2172 "y.tab.c"
    break;

  case 63: /* logical-AND-expression: logical-AND-expression LOGICAL_AND inclusive-OR-expression  */
#line 259 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tlogical-AND-expression -> logical-AND-expression %s inclusive-OR-expression\n",(yyvsp[-1].stringval));}
#line 2178 "y.tab.c"
    break;

  case 64: /* conditional-expression: logical-OR-expression  */
#line 262 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tconditional-expression -> logical-OR-expression\n");}
#line 2184 "y.tab.c"
    break;

  case 65: /* conditional-expression: logical-OR-expression QUESTION expression COLON conditional-expression  */
#line 264 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tconditional-expression -> logical-OR-expression %s expression %s conditional-expression\n",(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2190 "y.tab.c"
    break;

  case 66: /* assignment-expression: conditional-expression  */
#line 267 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-expression -> conditional-expression\n");}
#line 2196 "y.tab.c"
    break;

  case 67: /* assignment-expression: unary-expression assignment-operator assignment-expression  */
#line 269 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-expression -> unary-expression assignment-operator assignment-expression\n");}
#line 2202 "y.tab.c"
    break;

  case 68: /* assignment-expression-opt: assignment-expression  */
#line 272 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-expression-opt -> assignment-expression\n");}
#line 2208 "y.tab.c"
    break;

  case 69: /* assignment-expression-opt: %empty  */
#line 274 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-expression-opt -> epsilon\n");}
#line 2214 "y.tab.c"
    break;

  case 70: /* assignment-operator: EQUAL  */
#line 277 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2220 "y.tab.c"
    break;

  case 71: /* assignment-operator: ASTERISK_EQUAL  */
#line 279 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2226 "y.tab.c"
    break;

  case 72: /* assignment-operator: DIVIDE_EQUAL  */
#line 281 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2232 "y.tab.c"
    break;

  case 73: /* assignment-operator: PERCENT_EQUAL  */
#line 283 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2238 "y.tab.c"
    break;

  case 74: /* assignment-operator: PLUS_EQUAL  */
#line 285 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2244 "y.tab.c"
    break;

  case 75: /* assignment-operator: MINUS_EQUAL  */
#line 287 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2250 "y.tab.c"
    break;

  case 76: /* assignment-operator: LEFT_SHIFT_EQUAL  */
#line 289 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2256 "y.tab.c"
    break;

  case 77: /* assignment-operator: RIGHT_SHIFT_EQUAL  */
#line 291 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2262 "y.tab.c"
    break;

  case 78: /* assignment-operator: AMPERSAND_EQUAL  */
#line 293 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2268 "y.tab.c"
    break;

  case 79: /* assignment-operator: CARET_EQUAL  */
#line 295 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2274 "y.tab.c"
    break;

  case 80: /* assignment-operator: PIPE_EQUAL  */
#line 297 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tassignment-operator -> %s\n",(yyvsp[0].stringval));}
#line 2280 "y.tab.c"
    break;

  case 81: /* expression-opt: expression  */
#line 300 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texpression-opt -> expression\n");}
#line 2286 "y.tab.c"
    break;

  case 82: /* expression-opt: %empty  */
#line 302 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texpression-opt -> epsilon\n");}
#line 2292 "y.tab.c"
    break;

  case 83: /* expression: assignment-expression  */
#line 306 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texpression -> assignment-expression\n");}
#line 2298 "y.tab.c"
    break;

  case 84: /* expression: expression COMMA assignment-expression  */
#line 308 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texpression -> expression %s assignment-expression\n",(yyvsp[-1].stringval));}
#line 2304 "y.tab.c"
    break;

  case 85: /* constant-expression: conditional-expression  */
#line 311 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tconstant-expression -> conditional-expression\n");}
#line 2310 "y.tab.c"
    break;

  case 86: /* declaration: declaration-specifiers init-declarator-list-opt SEMI_COLON  */
#line 315 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration -> declaration-specifiers init-declarator-list-opt %s\n",(yyvsp[0].stringval));}
#line 2316 "y.tab.c"
    break;

  case 87: /* init-declarator-list-opt: init-declarator-list  */
#line 319 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinit-declaration-list-opt -> init-declarator-list\n");}
#line 2322 "y.tab.c"
    break;

  case 88: /* init-declarator-list-opt: %empty  */
#line 321 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinit-declaration-list-opt -> epsilon\n");}
#line 2328 "y.tab.c"
    break;

  case 89: /* declaration-specifiers-opt: declaration-specifiers  */
#line 324 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-specifiers-opt -> declaration-specifiers\n");}
#line 2334 "y.tab.c"
    break;

  case 90: /* declaration-specifiers-opt: %empty  */
#line 326 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-specifiers-opt -> epsilon\n");}
#line 2340 "y.tab.c"
    break;

  case 91: /* declaration-specifiers: storage-class-specifier declaration-specifiers-opt  */
#line 329 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-specifiers -> storage-class-specifier declaration-specifiers-opt\n");}
#line 2346 "y.tab.c"
    break;

  case 92: /* declaration-specifiers: type-specifier declaration-specifiers-opt  */
#line 331 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-specifiers -> type-specifier declaration-specifiers-opt\n");}
#line 2352 "y.tab.c"
    break;

  case 93: /* declaration-specifiers: type-qualifier declaration-specifiers-opt  */
#line 333 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-specifiers -> type-qualifier declaration-specifiers-opt\n");}
#line 2358 "y.tab.c"
    break;

  case 94: /* declaration-specifiers: function-specifier declaration-specifiers-opt  */
#line 335 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-specifiers -> function-specifier declaration-specifiers-opt\n");}
#line 2364 "y.tab.c"
    break;

  case 95: /* init-declarator-list: init-declarator  */
#line 338 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinit-declarator-list -> init-declarator\n");}
#line 2370 "y.tab.c"
    break;

  case 96: /* init-declarator-list: init-declarator-list COMMA init-declarator  */
#line 340 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinit-declarator-list -> init-declarator-list %s init-declarator\n",(yyvsp[-1].stringval));}
#line 2376 "y.tab.c"
    break;

  case 97: /* init-declarator: declarator  */
#line 343 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinit-declarator -> declarator\n");}
#line 2382 "y.tab.c"
    break;

  case 98: /* init-declarator: declarator EQUAL initializer  */
#line 345 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinit-declarator -> declarator %s initializer\n",(yyvsp[-1].stringval));}
#line 2388 "y.tab.c"
    break;

  case 99: /* storage-class-specifier: EXTERN  */
#line 349 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstorage-class-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2394 "y.tab.c"
    break;

  case 100: /* storage-class-specifier: STATIC  */
#line 351 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstorage-class-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2400 "y.tab.c"
    break;

  case 101: /* storage-class-specifier: AUTO  */
#line 353 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstorage-class-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2406 "y.tab.c"
    break;

  case 102: /* storage-class-specifier: REGISTER  */
#line 355 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstorage-class-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2412 "y.tab.c"
    break;

  case 103: /* type-specifier: VOID  */
#line 359 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2418 "y.tab.c"
    break;

  case 104: /* type-specifier: CHAR  */
#line 361 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2424 "y.tab.c"
    break;

  case 105: /* type-specifier: SHORT  */
#line 363 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2430 "y.tab.c"
    break;

  case 106: /* type-specifier: INT  */
#line 365 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2436 "y.tab.c"
    break;

  case 107: /* type-specifier: LONG  */
#line 367 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2442 "y.tab.c"
    break;

  case 108: /* type-specifier: FLOAT  */
#line 369 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2448 "y.tab.c"
    break;

  case 109: /* type-specifier: DOUBLE  */
#line 371 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2454 "y.tab.c"
    break;

  case 110: /* type-specifier: SIGNED  */
#line 373 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2460 "y.tab.c"
    break;

  case 111: /* type-specifier: UNSIGNED  */
#line 375 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2466 "y.tab.c"
    break;

  case 112: /* type-specifier: BOOL  */
#line 377 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2472 "y.tab.c"
    break;

  case 113: /* type-specifier: COMPLEX  */
#line 379 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2478 "y.tab.c"
    break;

  case 114: /* type-specifier: IMAGINARY  */
#line 381 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2484 "y.tab.c"
    break;

  case 115: /* type-specifier: enum-specifier  */
#line 383 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-specifier -> enum-specifier\n");}
#line 2490 "y.tab.c"
    break;

  case 116: /* specifier-qualifier-list: type-specifier specifier-qualifier-list-opt  */
#line 387 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tspecifier-qualifier-list -> type-specifier specifier-qualifier-list-opt\n");}
#line 2496 "y.tab.c"
    break;

  case 117: /* specifier-qualifier-list: type-qualifier specifier-qualifier-list-opt  */
#line 389 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tspecifier-qualifier-list -> type-qualifier specifier-qualifier-list-opt\n");}
#line 2502 "y.tab.c"
    break;

  case 118: /* specifier-qualifier-list-opt: specifier-qualifier-list  */
#line 392 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tspecifier-qualifier-list-opt -> specifier-qualifier-list\n");}
#line 2508 "y.tab.c"
    break;

  case 119: /* specifier-qualifier-list-opt: %empty  */
#line 394 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tspecifier-qualifier-list-opt -> epsilon\n");}
#line 2514 "y.tab.c"
    break;

  case 120: /* enum-specifier: ENUM identifier-opt LEFT_CURLY_BRACKET enumerator-list RIGHT_CURLY_BRACKET  */
#line 397 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tenum-specifier -> %s identifier-opt %s enumerator-list %s\n",(yyvsp[-4].stringval),(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2520 "y.tab.c"
    break;

  case 121: /* enum-specifier: ENUM identifier-opt LEFT_CURLY_BRACKET enumerator-list COMMA RIGHT_CURLY_BRACKET  */
#line 399 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tenum-specifier -> %s identifier-opt %s enumerator-list %s %s\n",(yyvsp[-5].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2526 "y.tab.c"
    break;

  case 122: /* enum-specifier: ENUM IDENTIFIER  */
#line 401 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tenum-specifier -> %s identifier(%s)\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2532 "y.tab.c"
    break;

  case 123: /* identifier-opt: IDENTIFIER  */
#line 404 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tidentifier-opt -> identifier(%s)\n",(yyvsp[0].stringval));}
#line 2538 "y.tab.c"
    break;

  case 124: /* identifier-opt: %empty  */
#line 406 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tidentifier-opt -> epsilon\n");}
#line 2544 "y.tab.c"
    break;

  case 125: /* enumerator-list: enumerator  */
#line 409 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tenumerator-list -> enumerator\n");}
#line 2550 "y.tab.c"
    break;

  case 126: /* enumerator-list: enumerator-list COMMA enumerator  */
#line 411 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tenumerator-list -> enumerator-list %s enumerator\n",(yyvsp[-1].stringval));}
#line 2556 "y.tab.c"
    break;

  case 127: /* enumerator: IDENTIFIER  */
#line 415 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tenumerator -> enumerator-constant(%s)\n",(yyvsp[0].stringval));}
#line 2562 "y.tab.c"
    break;

  case 128: /* enumerator: IDENTIFIER EQUAL constant-expression  */
#line 417 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tenumerator -> enumeration-constant(%s) %s constant-expression\n",(yyvsp[-2].stringval),(yyvsp[-1].stringval));}
#line 2568 "y.tab.c"
    break;

  case 129: /* type-qualifier: CONST  */
#line 421 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-qualifier -> %s\n",(yyvsp[0].stringval));}
#line 2574 "y.tab.c"
    break;

  case 130: /* type-qualifier: RESTRICT  */
#line 423 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-qualifier -> %s\n",(yyvsp[0].stringval));}
#line 2580 "y.tab.c"
    break;

  case 131: /* type-qualifier: VOLATILE  */
#line 425 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-qualifier -> %s\n",(yyvsp[0].stringval));}
#line 2586 "y.tab.c"
    break;

  case 132: /* function-specifier: INLINE  */
#line 429 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tfunction-specifier -> %s\n",(yyvsp[0].stringval));}
#line 2592 "y.tab.c"
    break;

  case 133: /* declarator: pointer-opt direct-declarator  */
#line 432 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclarator -> pointer-opt direct-declarator\n");}
#line 2598 "y.tab.c"
    break;

  case 134: /* pointer-opt: pointer  */
#line 435 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpointer-opt -> pointer\n");}
#line 2604 "y.tab.c"
    break;

  case 135: /* pointer-opt: %empty  */
#line 437 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpointer-opt -> epsilon\n");}
#line 2610 "y.tab.c"
    break;

  case 136: /* direct-declarator: IDENTIFIER  */
#line 440 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> identifier(%s)\n",(yyvsp[0].stringval));}
#line 2616 "y.tab.c"
    break;

  case 137: /* direct-declarator: LEFT_ROUND_BRACKET declarator RIGHT_ROUND_BRACKET  */
#line 442 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> %s declarator %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2622 "y.tab.c"
    break;

  case 138: /* direct-declarator: direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list-opt assignment-expression-opt RIGHT_SQUARE_BRACKET  */
#line 444 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> direct-declarator %s type-qualifier-list-opt assignment-expression-opt %s\n",(yyvsp[-3].stringval),(yyvsp[0].stringval));}
#line 2628 "y.tab.c"
    break;

  case 139: /* direct-declarator: direct-declarator LEFT_SQUARE_BRACKET STATIC type-qualifier-list-opt assignment-expression RIGHT_SQUARE_BRACKET  */
#line 446 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> direct-declarator %s %s type-qualifier-list-opt assignment-expression %s\n",(yyvsp[-4].stringval),(yyvsp[-3].stringval),(yyvsp[0].stringval));}
#line 2634 "y.tab.c"
    break;

  case 140: /* direct-declarator: direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list STATIC assignment-expression RIGHT_SQUARE_BRACKET  */
#line 448 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> direct-declarator %s type-qualifier-list %s assignment-expression %s\n",(yyvsp[-4].stringval),(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2640 "y.tab.c"
    break;

  case 141: /* direct-declarator: direct-declarator LEFT_SQUARE_BRACKET type-qualifier-list-opt ASTERISK RIGHT_SQUARE_BRACKET  */
#line 450 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> direct-declarator %s type-qualifier-list-opt %s %s\n",(yyvsp[-3].stringval),(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2646 "y.tab.c"
    break;

  case 142: /* direct-declarator: direct-declarator LEFT_ROUND_BRACKET parameter-type-list RIGHT_ROUND_BRACKET  */
#line 452 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> direct-declarator %s parameter-type-list %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2652 "y.tab.c"
    break;

  case 143: /* direct-declarator: direct-declarator LEFT_ROUND_BRACKET identifier-list-opt RIGHT_ROUND_BRACKET  */
#line 454 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdirect-declarator -> direct-declarator %s identifier-list-opt %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2658 "y.tab.c"
    break;

  case 144: /* identifier-list-opt: identifier-list  */
#line 457 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tidentifier-list-opt -> identifier-list\n");}
#line 2664 "y.tab.c"
    break;

  case 145: /* identifier-list-opt: %empty  */
#line 459 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tidentifier-list-opt -> epsilon\n");}
#line 2670 "y.tab.c"
    break;

  case 146: /* pointer: ASTERISK type-qualifier-list-opt  */
#line 462 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpointer -> %s type-qualifier-list-opt\n",(yyvsp[-1].stringval));}
#line 2676 "y.tab.c"
    break;

  case 147: /* pointer: ASTERISK type-qualifier-list-opt pointer  */
#line 464 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tpointer -> %s type-qualifier-list-opt pointer\n",(yyvsp[-2].stringval));}
#line 2682 "y.tab.c"
    break;

  case 148: /* type-qualifier-list-opt: type-qualifier-list  */
#line 467 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-qualifier-list-opt -> type-qualifier-list\n");}
#line 2688 "y.tab.c"
    break;

  case 149: /* type-qualifier-list-opt: %empty  */
#line 469 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-qualifier-list-opt -> epsilon\n");}
#line 2694 "y.tab.c"
    break;

  case 150: /* type-qualifier-list: type-qualifier  */
#line 472 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-qualifier-list -> type-qualifier\n");}
#line 2700 "y.tab.c"
    break;

  case 151: /* type-qualifier-list: type-qualifier-list type-qualifier  */
#line 474 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-qualifier-list -> type-qualifier-list type-qualifier\n");}
#line 2706 "y.tab.c"
    break;

  case 152: /* parameter-type-list: parameter-list  */
#line 477 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tparameter-type-list -> parameter-list\n");}
#line 2712 "y.tab.c"
    break;

  case 153: /* parameter-type-list: parameter-list COMMA ELLIPSIS  */
#line 479 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tparameter-type-list -> parameter-list %s %s\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2718 "y.tab.c"
    break;

  case 154: /* parameter-list: parameter-declaration  */
#line 482 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tparameter-list -> parameter-declaration\n");}
#line 2724 "y.tab.c"
    break;

  case 155: /* parameter-list: parameter-list COMMA parameter-declaration  */
#line 484 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tparameter-list -> parameter-list %s parameter-declaration\n",(yyvsp[-1].stringval));}
#line 2730 "y.tab.c"
    break;

  case 156: /* parameter-declaration: declaration-specifiers declarator  */
#line 487 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tparameter-declaration -> declaration-specifiers declarator\n");}
#line 2736 "y.tab.c"
    break;

  case 157: /* parameter-declaration: declaration-specifiers  */
#line 489 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tparameter-declaration -> declaration-specifiers\n");}
#line 2742 "y.tab.c"
    break;

  case 158: /* identifier-list: IDENTIFIER  */
#line 493 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tidentifier-list -> identifier(%s)\n",(yyvsp[0].stringval));}
#line 2748 "y.tab.c"
    break;

  case 159: /* identifier-list: identifier-list COMMA IDENTIFIER  */
#line 495 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tidentifier-list -> identifier-list %s identifier(%s)\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2754 "y.tab.c"
    break;

  case 160: /* type-name: specifier-qualifier-list  */
#line 499 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttype-name -> specifier-qualifier-list\n");}
#line 2760 "y.tab.c"
    break;

  case 161: /* initializer: assignment-expression  */
#line 502 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinitializer -> assignment-expression\n");}
#line 2766 "y.tab.c"
    break;

  case 162: /* initializer: LEFT_CURLY_BRACKET initializer-list RIGHT_CURLY_BRACKET  */
#line 504 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinitializer -> %s initializer-list %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2772 "y.tab.c"
    break;

  case 163: /* initializer: LEFT_CURLY_BRACKET initializer-list COMMA RIGHT_CURLY_BRACKET  */
#line 506 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinitializer -> %s initializer-list %s %s\n",(yyvsp[-3].stringval),(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2778 "y.tab.c"
    break;

  case 164: /* initializer-list: designation-opt initializer  */
#line 509 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinitializer-list -> designation-opt initializer\n");}
#line 2784 "y.tab.c"
    break;

  case 165: /* initializer-list: initializer-list COMMA designation-opt initializer  */
#line 511 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tinitializer-list -> initializer-list %s designation-opt initializer\n",(yyvsp[-2].stringval));}
#line 2790 "y.tab.c"
    break;

  case 166: /* designation-opt: designation  */
#line 514 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdesignation-opt -> designation\n");}
#line 2796 "y.tab.c"
    break;

  case 167: /* designation-opt: %empty  */
#line 516 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdesignation-opt -> epsilon\n");}
#line 2802 "y.tab.c"
    break;

  case 168: /* designation: designator-list EQUAL  */
#line 519 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdesignation -> designator-list %s\n",(yyvsp[0].stringval));}
#line 2808 "y.tab.c"
    break;

  case 169: /* designator-list: designator  */
#line 522 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdesignator-list -> designator\n");}
#line 2814 "y.tab.c"
    break;

  case 170: /* designator-list: designator-list designator  */
#line 524 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdesignator-list -> designator-list designator\n");}
#line 2820 "y.tab.c"
    break;

  case 171: /* designator: LEFT_SQUARE_BRACKET constant-expression RIGHT_SQUARE_BRACKET  */
#line 527 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdesignator -> %s constant-expression %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2826 "y.tab.c"
    break;

  case 172: /* designator: DOT IDENTIFIER  */
#line 529 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdesignator -> %s identifier(%s)\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2832 "y.tab.c"
    break;

  case 173: /* statement: labeled-statement  */
#line 534 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstatement -> labeled-statement\n");}
#line 2838 "y.tab.c"
    break;

  case 174: /* statement: compound-statement  */
#line 536 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstatement -> compound-statement\n");}
#line 2844 "y.tab.c"
    break;

  case 175: /* statement: expression-statement  */
#line 538 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstatement -> expression-statement\n");}
#line 2850 "y.tab.c"
    break;

  case 176: /* statement: selection-statement  */
#line 540 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstatement -> selection-statement\n");}
#line 2856 "y.tab.c"
    break;

  case 177: /* statement: iteration-statement  */
#line 542 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstatement -> iteration-statement\n");}
#line 2862 "y.tab.c"
    break;

  case 178: /* statement: jump-statement  */
#line 544 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tstatement -> jump-statement\n");}
#line 2868 "y.tab.c"
    break;

  case 179: /* labeled-statement: IDENTIFIER COLON statement  */
#line 547 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tlabeled-statement -> identifier(%s) %s statement\n",(yyvsp[-2].stringval),(yyvsp[-1].stringval));}
#line 2874 "y.tab.c"
    break;

  case 180: /* labeled-statement: CASE constant-expression COLON statement  */
#line 549 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tlabeled-statement -> %s constant-expression %s statement\n",(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2880 "y.tab.c"
    break;

  case 181: /* labeled-statement: DEFAULT COLON statement  */
#line 551 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tlabeled-statement -> %s %s statement\n",(yyvsp[-2].stringval),(yyvsp[-1].stringval));}
#line 2886 "y.tab.c"
    break;

  case 182: /* compound-statement: LEFT_CURLY_BRACKET block-item-list-opt RIGHT_CURLY_BRACKET  */
#line 554 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tcompound-statement -> %s block-item-list-opt %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 2892 "y.tab.c"
    break;

  case 183: /* block-item-list-opt: block-item-list  */
#line 557 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tblock-item-list-opt -> block-item-list\n");}
#line 2898 "y.tab.c"
    break;

  case 184: /* block-item-list-opt: %empty  */
#line 559 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tblock-item-list-opt -> epsilon\n");}
#line 2904 "y.tab.c"
    break;

  case 185: /* block-item-list: block-item  */
#line 562 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tblock-item-list -> block-item\n");}
#line 2910 "y.tab.c"
    break;

  case 186: /* block-item-list: block-item-list block-item  */
#line 564 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tblock-item-list -> block-item-list block-item\n");}
#line 2916 "y.tab.c"
    break;

  case 187: /* block-item: declaration  */
#line 567 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tblock-item -> declaration\n");}
#line 2922 "y.tab.c"
    break;

  case 188: /* block-item: statement  */
#line 569 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tblock-item -> statement\n");}
#line 2928 "y.tab.c"
    break;

  case 189: /* expression-statement: expression-opt SEMI_COLON  */
#line 572 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texpression-statement -> expression-opt %s\n",(yyvsp[0].stringval));}
#line 2934 "y.tab.c"
    break;

  case 190: /* selection-statement: IF LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement  */
#line 575 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tselection-statement -> %s %s expression %s statement\n",(yyvsp[-4].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2940 "y.tab.c"
    break;

  case 191: /* selection-statement: IF LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement ELSE statement  */
#line 577 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tselection-statement -> %s %s expression %s statement %s statement\n",(yyvsp[-6].stringval),(yyvsp[-5].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2946 "y.tab.c"
    break;

  case 192: /* selection-statement: SWITCH LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement  */
#line 579 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tselection-statement -> %s %s expression %s statement\n",(yyvsp[-4].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2952 "y.tab.c"
    break;

  case 193: /* iteration-statement: WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement  */
#line 582 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\titeration-statement -> %s %s expression %s statement\n",(yyvsp[-4].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2958 "y.tab.c"
    break;

  case 194: /* iteration-statement: DO statement WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET SEMI_COLON  */
#line 584 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\titeration-statement -> %s statement %s %s expression %s %s\n",(yyvsp[-6].stringval),(yyvsp[-4].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2964 "y.tab.c"
    break;

  case 195: /* iteration-statement: FOR LEFT_ROUND_BRACKET expression-opt SEMI_COLON expression-opt SEMI_COLON expression-opt RIGHT_ROUND_BRACKET statement  */
#line 586 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\titeration-statement -> %s %s expression-opt %s expression-opt %s expression-opt %s statement\n",(yyvsp[-8].stringval),(yyvsp[-7].stringval),(yyvsp[-5].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2970 "y.tab.c"
    break;

  case 196: /* iteration-statement: FOR LEFT_ROUND_BRACKET declaration expression-opt SEMI_COLON expression-opt RIGHT_ROUND_BRACKET statement  */
#line 588 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\titeration-statement -> %s %s declaration expression-opt %s expression-opt %s statement\n",(yyvsp[-7].stringval),(yyvsp[-6].stringval),(yyvsp[-3].stringval),(yyvsp[-1].stringval));}
#line 2976 "y.tab.c"
    break;

  case 197: /* jump-statement: GOTO IDENTIFIER SEMI_COLON  */
#line 591 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tjump-statement -> %s identifier(%s) %s\n",(yyvsp[-2].stringval),(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2982 "y.tab.c"
    break;

  case 198: /* jump-statement: CONTINUE SEMI_COLON  */
#line 593 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tjump-statement -> %s %s\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2988 "y.tab.c"
    break;

  case 199: /* jump-statement: BREAK SEMI_COLON  */
#line 595 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tjump-statement -> %s %s\n",(yyvsp[-1].stringval),(yyvsp[0].stringval));}
#line 2994 "y.tab.c"
    break;

  case 200: /* jump-statement: RETURN expression-opt SEMI_COLON  */
#line 597 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tjump-statement -> %s expression-opt %s\n",(yyvsp[-2].stringval),(yyvsp[0].stringval));}
#line 3000 "y.tab.c"
    break;

  case 201: /* translation-unit: external-declaration  */
#line 601 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttranslation-unit -> external-declaration\n");}
#line 3006 "y.tab.c"
    break;

  case 202: /* translation-unit: translation-unit external-declaration  */
#line 603 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\ttranslation-unit -> translation-unit external-declaration\n");}
#line 3012 "y.tab.c"
    break;

  case 203: /* external-declaration: function-definition  */
#line 606 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texternal-declaration -> function-definition\n");}
#line 3018 "y.tab.c"
    break;

  case 204: /* external-declaration: declaration  */
#line 608 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\texternal-declaration -> declaration\n");}
#line 3024 "y.tab.c"
    break;

  case 205: /* function-definition: declaration-specifiers declarator declaration-list-opt compound-statement  */
#line 611 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tfunction-definition -> declaration-specifiers declarator declaration-list-opt compound-statement\n");}
#line 3030 "y.tab.c"
    break;

  case 206: /* declaration-list-opt: declaration-list  */
#line 614 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-list-opt -> declaration-list\n");}
#line 3036 "y.tab.c"
    break;

  case 207: /* declaration-list-opt: %empty  */
#line 616 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-list-opt -> epsilon\n");}
#line 3042 "y.tab.c"
    break;

  case 208: /* declaration-list: declaration  */
#line 619 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-list -> declaration\n");}
#line 3048 "y.tab.c"
    break;

  case 209: /* declaration-list: declaration-list declaration  */
#line 621 "ass4_20CS30062_20CS30043.y"
                        {printf("\t\tdeclaration-list -> declaration-list declaration\n");}
#line 3054 "y.tab.c"
    break;


#line 3058 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 624 "ass4_20CS30062_20CS30043.y"

void yyerror(char* s) {
    printf("\t\tERROR in line %d : %s\n", yylineno, s);
}
