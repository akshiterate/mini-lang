#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "AST.h"
#include "Token.h"
#include <vector>
using namespace std;

class Parser{
private:
    vector<Token> tokens;
    int position;
    Token current;

public:
    Parser(vector<Token> tokens){
        this->tokens=tokens;
        position = 0;
        current = Token(TokenType::SEMICOLON, "");
        advance();
    }
    Statement* parseStatement() {
    if (current.type != TokenType::LET) {
        cout << "let error" << endl;
        return nullptr;
    }

    advance();  // now pointing at IDENTIFIER

    if (current.type != TokenType::IDENTIFIER) {
        cout << "identi error" << endl;
        return nullptr;
    }

    Token name = current;
    advance();  // now pointing at '='

    if (current.type != TokenType::EQUAL) {
        cout << "equal error" << endl;
        return nullptr;
    }

    advance();  // now pointing at number

    Expression* value = parseExpression();

    if (current.type != TokenType::SEMICOLON) {
        cout << "colon error" << endl;
        return nullptr;
    }

    advance();  // move past ';'
    return new LetExpression(name.value, value);
}


    Expression* parseExpression(){
        
        if(current.type == TokenType::NUMBER){
            Token numberToken = current;
            advance();
            return new Number(numberToken.value);
        }
        else if(current.type == TokenType::IDENTIFIER){
            advance();
            return new Number(current.value);//temporarily as there is no support for variables right now.
        }

        cout<<"unexpected token oopsie >("<<current.value<<")"<<endl;
        return nullptr;
    }


    Token peek(){
        if(position<tokens.size()){
            return tokens[position];
        }
        return Token(TokenType::SEMICOLON,"");
    }
    Token advance() {
        if (position < tokens.size()) {
            current = tokens[position];
            return tokens[position++];
        }
        current = Token(TokenType::SEMICOLON, "");
        return current;
    }

    
};

#endif