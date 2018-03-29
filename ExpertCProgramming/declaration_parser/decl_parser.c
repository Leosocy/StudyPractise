#include "decl_parser.h"
#include <stdio.h>
#include <string.h>

#define IS_STR_EQ(lhs, rhs) (strcmp((lhs), (rhs)) == 0)

typedef enum tagType
{
    VALID = 0,
    QUALIFIER,
    IDENTIFIER,
    TYPE,
} StrType;

const char *g_TypeArray[] = {
    "void",
    "char",
    "signed",
    "unsigned",
    "short",
    "int",
    "long",
    "float",
    "double",
    "struct",
    "enum",
    "union"
};
const char *g_QualifierArray[] = {
    "const",
    "volatile"
};

#define TOKEN_MAX_LEN 128
typedef struct tagToken
{
    char string[TOKEN_MAX_LEN];
    StrType type;
} Token;

void classify_token(const char *str, Token *token);

void parse_decl(const char *declaration)
{
    
}

void classify_token(const char *str, Token *token)
{
    if (str == NULL || token == NULL)
    {
        return;
    }
    int index = 0;
    for (index = 0; index < sizeof(g_QualifierArray) / sizeof(g_QualifierArray[0]); ++index)
    if (IS_STR_EQ(str, g_QualifierArray[index]))
    {
        strncpy(token->string, g_QualifierArray[index], TOKEN_MAX_LEN);
        token->type = QUALIFIER;
        return;
    }
    
    for (index = 0; index < sizeof(g_TypeArray) / sizeof(g_TypeArray[0]); ++index)
    {
        if (IS_STR_EQ(str, g_TypeArray[index]))
        {
            strncpy(token->string, g_TypeArray[index], TOKEN_MAX_LEN);
            token->type = TYPE;
            return;
        }
    }
    strncpy(token->string, str, TOKEN_MAX_LEN);
    token->type = IDENTIFIER;
}
