#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include<stdbool.h>
#include "token.h"
char* getline();
Token* scantokens(char*,int*);
char currentchar(char*,int*);
bool isstring(char*,int*);
bool match(char*,char,int*);
bool isnumber(char*,int*);
bool iskeyword(char*,char*);
void addtoken(Token*,int*,int*,char*,LiteralValue,int*);
void err(char *error,int line);
char* concat(char);
#endif // SCANNER_H_INCLUDED
