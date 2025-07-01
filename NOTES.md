# Notes

## Steps to remember

- tokenization
    - use enum to list down all the token types (easier to read and debug, easier to update (add/remove tokens), easier to understand what the language supports)
    - a vector can be used to store tokens
        - it will contain the tokentype and value for each token
        - a function can be made to tokenize a given input
            - we read char by char(cant split by " " its possible there are no spaces)
            -  an unordered map can be used to match keywords