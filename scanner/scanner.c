
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include "scanner.h"
#include "token.h"
#define size 1055

char* getline()
{

    char *str=NULL;
    int pos=0;
    char ch;
    int len=size;
    str=(char*)malloc(sizeof(char)*size);
    do
    {
        ch=getchar();
        str[pos]=ch;
        pos++;
        if(pos>=sizeof(char)*size)
        {

            str=(char *)realloc(str,len*2);
            len*=2;
        }
    }while(ch!='/');
    if (str==NULL)
    {
        printf("%s","string is null");
        return NULL;
    }

    str[pos]='\0';
return str;
}

bool match(char* str,char match,int *current)
{
    if(str[*current]==match)
    {
        return true;
    }
    //current++;
    return false;
}
char currentchar(char *str,int *current)
{
    if(str==NULL || current==NULL)
    {
        printf("%s","str or current is NULL");
        return NULL;
    }

    return str[(*current)++];
}

bool isstring(char* str,int *current)
{
    int ascii=0;
    ascii=(int)str[*current];

    if(ascii>=97 && ascii<=122 || ascii>=65 && ascii<=90)
    {
        return true;
    }
    return false;
}


bool isnumber(char* str,int* current)
{
    if(str==NULL || current==NULL)
    {
        printf("%s","str or current is null");
        return NULL;
    }
    int integer=0;
    return isdigit(str[*current]);
}


bool iskeyword(char *subs,char* key)
{

    const char* keywords[]={"and", "class", "else", "false", "fun", "for", "if", "nil", "or",
    "print", "return", "super", "this", "true", "var", "while", "end"};
    int keyword_count = sizeof(keywords) / sizeof(keywords[0]);
    for(int i=0;i<keyword_count;i++)
    {

        if(strcmp(subs,keywords[i])==0)
        {

            return true;
        }
    }
    return false;
}

void err(char* error,int line)
{
    if(error==NULL)
    {
        printf("%s","error is null");
    }
    char str[100];
    sprintf(str, "%s%d", error, line);
    printf("%s\n", str);
}

char* concat(char ch)
{

    char *res=malloc(2);
    res[0]=ch;
    res[1]='\0';
    return res;
}


void addToken(Token *tkarr,Tokentype type,int *index,int *j,int *current,char *ch,int line,LiteralValue val,int* count)
{

    if(tkarr==NULL)
    {
      printf("token array Pointer is  null ");
      return;
    }
    if(current==NULL || index==NULL|| j==NULL || count==NULL)
    {
        printf("Pointer is null");
        return;
    }
    Token tk;
    tk.type = type;
    tk.literal = val;
    tk.line = line;
    tk.lexeme = strdup(ch);// make a copy
    tkarr[*index]=tk;
    (*index)++;
    (*j)++;
    (*current)++;
    (*count)++;
}


Token* scantokens(char* str,int* count)
{

if(str==NULL)
{
    printf("%s","str is null");
    return NULL;
}

if (__builtin_types_compatible_p(typeof(count), int)) {
        printf("x is of type int\n");
        return NULL;
    }
int length=0;
int start=0;
int current=0;
int line=1;
char *keywords=NULL;
int j=0;
int index=0;
char ch;
int len=size;
LiteralValue val;
char *subs;
subs=(char*)malloc(sizeof(char)*len*2);
Token *tkarr=(Token*)malloc(sizeof(Token)*strlen(str)*len);
while(j<strlen(str))
{
    if(j>sizeof(Token)*strlen(str)*size)
    {
        tkarr=realloc(tkarr,sizeof(Token)*strlen(str)*len*2);
        len*=2;
    }
    ch=str[j];
    switch(ch){

    case ';':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,SEMICOLON,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '(':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,LEFT_PAREN,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case ',':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,COMMA,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case ')':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,RIGHT_PAREN,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '.':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,DOT,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '{':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,LEFT_BRACE,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '}':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,RIGHT_BRACE,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '-':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,MINUS,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '+':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,PLUS,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '/':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,SLASH,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '*':{
        val.char_val='\0';
        char *temp = concat(ch);
        addToken(tkarr,STAR,&index,&j,&current,temp,line,val,count);
        free(temp);
        break;
    }
    case '!':{

        if (str[j+1]=='=')
        {

          start=j;
          val.string_val=NULL;
          strncpy(subs,str+start,start+2);
          subs[j+2]='\0';
          addToken(tkarr,BANG_EQUAL,&index,&j,&current,subs,line,val,count);
          current+=1;
          j+=1;
          break;

        }
        else
        {
          val.char_val='\0';
          char *temp = concat(ch);
          addToken(tkarr,BANG,&index,&j,&current,temp,line,val,count);
          free(temp);
          break;
        }
    }
    case '=':{

        if (str[j+1]=='=')
        {
          start=j;
          val.string_val=NULL;
          strncpy(subs,str+start,start+2);
          subs[j+2]='\0';

          addToken(tkarr,EQUAL_EQUAL,&index,&j,&current,subs,line,val,count);
          current+=1;
          j+=1;
          break;

        }
        else
        {
          val.char_val='\0';
          char *temp = concat(ch);
          addToken(tkarr,EQUAL,&index,&j,&current,temp,line,val,count);
          free(temp);
          break;
        }
    }

    case '\n':
        current++;
        line++;
        j++;
        break;
    case ' ':
        j++;
        current++;
        break;

    case '"':{
        current++;
        start=current;
        while(match(str,'"',&current)!=true)
        {
            if (j>strlen(str))
            {
                err("Error at line",line);
            }// this error condidtion needs to change
            if(isstring(str,&current)==true)
            {
                if(str[j]=='\n')
                {
                    line++;
                    current++;
                }
                current++;

            }
            else
            {
                printf("%s","Not a string");
                return NULL;
            }

        }
        int end=0;
        int diff;

        end=current;
        diff=end-start;
        strncpy(subs,str+start,diff);
        val.string_val=strdup(subs);
        addToken(tkarr,STRING,&index,&j,&current,subs,line,val,count);
        j=current;

        break;
    }
    default:

        start=j;

        while (str[j] != '\0' && !isspace(str[j]) && str[j] != ';' && str[j] != '=')
        {
          j++;
          current++;

        }
        length = current - start;

        strncpy(subs, str + start, length);
        subs[length]='\0';
        current-=1;
        j-=1;
        if(iskeyword(subs,keywords)==false)
        {

          val.string_val=NULL;
          addToken(tkarr,IDENTIFIER,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "and") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,AND,&index,&j,&current,subs,line,val,count);
          break;
        }

        if (strcmp(subs, "class") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,CLASS,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "else") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,ELSE,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "false") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,FALSE,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "func") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,FUNC,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "for") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,FOR,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "if") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,IF,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "nil") == 0)
        {
           val.string_val=NULL;
          addToken(tkarr,NIL,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "or") == 0)
        {
            val.string_val=NULL;
          addToken(tkarr,OR,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "print") == 0)
        {
            val.string_val=NULL;
          addToken(tkarr,PRINT,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "return") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,RETURN,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "super") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,SUPER,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "this") == 0)
        {
            val.string_val=NULL;
          addToken(tkarr,THIS,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "true") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,TRUE,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "var") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,VAR,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "while") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,WHILE,&index,&j,&current,subs,line,val,count);
          break;
        }
        if (strcmp(subs, "end") == 0)
        {
          val.string_val=NULL;
          addToken(tkarr,END,&index,&j,&current,subs,line,val,count);
          break;
        }
        if(isalnum(*subs))
        {
          val.string_val=NULL;
          addToken(tkarr,ALPHANUMERIC,&index,&j,&current,subs,line,val,count);
          break;
        }

        if(isnumber(subs,&current)==true)

        {
            char decimal[2]={'.','\0'};
            if(strstr(subs,decimal))
            {
                current++;
            }
            val.number_val=atof(subs);
            addToken(tkarr,NUMBER,&index,&j,&current,subs,line,val,count);
            break;
        }
        else
        {

            err("Error at line",line);
        }

    }


}
subs[strlen(subs)] = '\0';
val.string_val = NULL;
addToken(tkarr, END, &index, &j, &current, '\0', line, val,count);

free(subs);
return tkarr;
}


int main()
{
    char* source;
    Token* tokens;
    source=getline();
    int count;
    tokens=scantokens(source,&count);


    for(int i=0;i<count-1;i++)
    {
    printf("%s",tokens[i].lexeme);
    }
    free(tokens);
    return 0;
}


