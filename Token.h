#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_map>

using namespace std;

enum TokenType{
    LET,
    IDENTIFIER,
    NUMBER,
    EQUAL,
    SEMICOLON,
    PLUS,
    PRINT,
    LPAREN,
    RPAREN,
    IF,
    ELSE,
    WHILE,
    FOR,
    MINUS,
    DIVIDE,
    MULTIPLY,
    RCURL,
    LCURL
};


class Token{
public:
    TokenType type;
    string value;

    Token() {  // <-- Add this
        type = TokenType::SEMICOLON;
        value = "";
    }

    Token(TokenType t, string v){
        type = t;
        value = v;
    }
};

std::unordered_map<std::string, TokenType> keywordMap = {
    {"let", TokenType::LET},
    {"print", TokenType::PRINT},
    {"if", TokenType::IF},
    {"else", TokenType::ELSE},
    {"while", TokenType::WHILE},
    {"for", TokenType::FOR}
};
#endif