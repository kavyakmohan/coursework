grammar Interpreter;

start  :
     expression  EOF
  ;

expression :
   |   INT
   |   NUMBER
   |   WORD
   |   LPARENTHESIS expression RPARENTHESIS
   |   expression (EQUALITY | GREATER | LESSER) expression
   |   expression (MULTIPLY | DIVIDE) expression
   |   expression (PLUS | MINUS) expression
   |   expression (AND | OR) expression
   |   'IF' condition 'THEN' statement
   |   'IF' condition 'THEN' statement ('ELSE' statement)?
   |   'IF' condition 'THEN' statement ('ELSE IF' condition 'THEN' statement)+? ('ELSE' statement)
   |   'WHILE' LPARENTHESIS condition RPARENTHESIS 'REPEAT' action
   ;

condition :
    | expression
    ;

statement :
    | expression
    ;

action :
   |  expression
   ;

MULTIPLY : '*';
DIVIDE :  '/';
PLUS   :  '+';
MINUS  :  '-';
AND    :  '&&';
OR     :  '||';
EQUALITY : '==';
LESSER : '<';
GREATER : '>';
INT    :  '0'..'9'+;
NUMBER : INT'.'INT;
WHITESPACE : (' ' | '\n' | '\t')+ -> skip;
WORD : ('A'..'z')+;
COMMENTS : '##' (WORD | WHITESPACE | INT | NUMBER)+ '##' -> skip;
LPARENTHESIS : '(';
RPARENTHESIS : ')';
