# interpreter of scheme

## This is a tiny interpreter of scheme, which use racket language.
## There are several parts:

+ global variable                  (define a 1)
+ some simple function             (list 1 2 3)
+ evaluation environment            
+ lambda function                  (lambda(x) (* x x))
+ call function                     ((lambda(x)(* x x )) 3)
+ numbers and strings               123 "scheme"
+ arithmetic evaluation             (+ - * / ** % cons car cdr)


