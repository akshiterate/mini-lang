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
    - gives output   Let(x = 5)

- Parser
    - **Purpose**
        - The parser consumes a list of tokens and builds the AST.
            - It determines structure (syntax) from flat tokens, converting them into hierarchical expressions/statements.

    - **Parser Class**
        - Fields:
            - `vector<Token> tokens`
            - `int position`
            - `Token current`
        - Core Functions:
            - `advance()`: Moves to the next token.
            - `peek()`: Looks at the upcoming token without advancing.
            - `parseExpression()`: Parses numeric expressions (currently only supports `Number`).
            - `parseStatement()`: Parses statements like `let x = 5;`

    - **Parsing Logic**
        - Example `parseStatement()` handles a `let` statement:
            1. Check for `LET` token.
            2. Expect an `IDENTIFIER` (variable name).
            3. Expect an `EQUAL` token.
            4. Parse an `Expression` using `parseExpression()`.
            5. Expect a `SEMICOLON` at the end.
            6. Return a new `LetExpression`.