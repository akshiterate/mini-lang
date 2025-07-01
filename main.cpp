#include <iostream>
#include <string>
#include <vector>
#include <cctype> //for isalpha() and isalnum()
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
    FOR
};

class Token{
public:
    TokenType type;
    string value;

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


class Tokenizer{
public:
    string source;
    Tokenizer(string src){
        source = src;
    }

    vector<Token> tokenize(){
        vector<Token> tokens;
        for (int i=0;i<source.length();i++){
            char c = source[i];
            if(isspace(c)){
                continue;
            }
            else if(isalpha(c) || c=='_'){
                string word ="";
                while(i<source.length() && isalnum(source[i]) || source[i]=='_'){
                    word+=source[i];
                    i++;
                }
                i--; //goes 1 count back to compensate for the for loop
                if (keywordMap.count(word)) {
                    tokens.push_back(Token(keywordMap[word],word));
                }
                else{
                    tokens.push_back(Token(TokenType::IDENTIFIER,word));
                }

            }
             else if (isdigit(c)) { 
                string number = "";
                while (i < source.length() && isdigit(source[i])) {
                    number += source[i];
                    i++;
                }
                i--;  // same reason: compensate for for-loop increment
                tokens.push_back(Token(TokenType::NUMBER, number));
            }

            else if(c=='='){
                tokens.push_back(Token(TokenType::EQUAL,"="));
            }
            else if(c=='+'){
                tokens.push_back(Token(TokenType::PLUS,"+"));
            }
            else if(c==';'){
                tokens.push_back(Token(TokenType::SEMICOLON,";"));
            }
            else if(c==')'){
                tokens.push_back(Token(TokenType::RPAREN,")"));
            }
            else if(c=='('){
                tokens.push_back(Token(TokenType::LPAREN,"("));
            }
            else{
                cout<<"Unexpected char: "<<c<<endl;
            }
        }
        return tokens;
    }
    
};


//token tester
string tokenTypeToString(TokenType type) {
    switch(type) {
        case TokenType::LET: return "LET";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::PLUS: return "PLUS";
        case TokenType::PRINT: return "PRINT";
        case TokenType::LPAREN: return "LPAREN";
        case TokenType::RPAREN: return "RPAREN";
        case TokenType::IF: return "IF";
        case TokenType::ELSE: return "ELSE";
        case TokenType::WHILE: return "WHILE";
        case TokenType::FOR: return "FOR";
        default: return "UNKNOWN";
    }
}


int main(){
    string input=" x= 5+ 3";
    Tokenizer tokenizer(input);
    vector<Token> tokens = tokenizer.tokenize();

    //token printer
    for (int i = 0; i < tokens.size(); i++) {
        cout << "Token(" << tokenTypeToString(tokens[i].type) << ", \"" << tokens[i].value << "\")" << endl;
    }


    return 0;
}

