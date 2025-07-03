#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
using namespace std;


class Expression{
public:
    virtual void print()=0;
};

class Number : public Expression{
public:
    string value;

    Number(string v){
        value = v;
    }
    void print() override{
        cout<<value;
    }
};

class Statement{
public:
    virtual void print() = 0;
};

class LetExpression : public Statement{
public:
    string name;
    Expression* value;

    LetExpression(string n,Expression* v){
        name = n;
        value = v;
    }

    void print() override{
        cout<<"Let("<<name<<"=";
        value->print();
        cout<<")";
    }
};

#endif