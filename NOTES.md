# Notes

## Steps to remember

- tokenization
    - use enum to list down all the token types (easier to read and debug, easier to update (add/remove tokens), easier to understand what the language supports)
    - a vector can be used to store tokens
        - it will contain the tokentype and value for each token
        - a function can be made to tokenize a given input
            - we read char by char(cant split by " " its possible there are no spaces)
            -  an unordered map can be used to match keywords

- Abstract Syntax Tree
    - Built:
        - Expression (abstract class)
        - Number (holds a number string)
        - Statement (abstract)
        - LetExpression (assigns a name to an expression)
    - basically
    ```
        Expression* exp = new Number("5");
        LetExpression stmt("x", exp);
        stmt.print();
    ```
    -gives output   Let(x = 5)