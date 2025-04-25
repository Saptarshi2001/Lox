#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

typedef enum{

  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,ALPHANUMERIC,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUNC, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,END
}Tokentype;

typedef union {
    double number_val;
    char char_val;
    char *string_val;
} LiteralValue;

typedef struct{

    Tokentype type;
    LiteralValue literal;
    int line;
    char* lexeme;
}Token;


#endif // TOKEN_H_INCLUDED
