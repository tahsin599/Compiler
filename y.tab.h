#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NEWLINE 257
#define CONST_FLOAT 258
#define CONST_INT 259
#define CONST_CHAR 260
#define IF 261
#define LOWER_THAN_ELSE 262
#define FOR 263
#define DO 264
#define INT 265
#define FLOAT 266
#define VOID 267
#define SWITCH 268
#define DEFAULT 269
#define ELSE 270
#define WHILE 271
#define BREAK 272
#define CHAR 273
#define DOUBLE 274
#define RETURN 275
#define CASE 276
#define CONTINUE 277
#define PRINTLN 278
#define ADDOP 279
#define MULOP 280
#define INCOP 281
#define RELOP 282
#define ASSIGNOP 283
#define LOGICOP 284
#define BITOP 285
#define NOT 286
#define LPAREN 287
#define RPAREN 288
#define LTHIRD 289
#define RTHIRD 290
#define LCURL 291
#define RCURL 292
#define COMMA 293
#define SEMICOLON 294
#define ID 295
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
    SymbolInfo* si; 
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
