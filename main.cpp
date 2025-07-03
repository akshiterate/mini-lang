#include <iostream>
#include <string>
#include <vector>
#include <cctype> //for isalpha() and isalnum()
#include <unordered_map>

#include "Token.h"
#include "Parser.h"
#include "AST.h"

using namespace std;


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
            else if(c=='-'){
                tokens.push_back(Token(TokenType::MINUS,"-"));
            }
            else if(c=='*'){
                tokens.push_back(Token(TokenType::MULTIPLY,"*"));
            }
            else if(c=='/'){
                tokens.push_back(Token(TokenType::DIVIDE,"/"));
            }
            else if(c=='{'){
                tokens.push_back(Token(TokenType::LCURL,"{"));
            }
            else if(c=='}'){
                tokens.push_back(Token(TokenType::RCURL,"}"));
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
        case TokenType::MULTIPLY: return "MULTIPLY";
        case TokenType::DIVIDE: return "DIVIDE";
        case TokenType::RCURL: return "RCURL";
        case TokenType::LCURL: return "LCURL";
        case TokenType::MINUS: return "MINUS";
        default: return "UNKNOWN";
    }
}


int main(){
    string input="let x = 5;";
    Tokenizer tokenizer(input);
    vector<Token> tokens = tokenizer.tokenize();

    //test for tokenization
    for (Token t : tokens) {
        cout << "Token(" << tokenTypeToString(t.type) << ", \"" << t.value << "\")" << endl;
    }

    Parser parser(tokens);
    Statement* stmt = parser.parseStatement();

    if(stmt){
        stmt->print();
        cout<<endl;
    }


    return 0;
}

