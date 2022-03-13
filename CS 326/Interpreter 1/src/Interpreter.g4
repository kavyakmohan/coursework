grammar Interpreter;

start  : IDENTIFIER ASSIGN variable;

variable:
    | '(' variable ')'
    | variable (MULTIPLY | DIVIDE) variable
    | variable (PLUS | MINUS) variable
    | variable STOMP variable
    | NUM
    | INT
    | IDENTIFIER
    ;

ASSIGN: '=';
STOMP: '^';
MULTIPLY: '*';
DIVIDE: '/';
PLUS: '+';
MINUS: '-';
NUM:  '0'..'9'+;
INT: NUM'.'NUM;
IDENTIFIER: ('$')*('a'..'z' | 'A' .. 'Z')+('_')*;
WHITESPACE: (' ' | '\t')+ -> skip;