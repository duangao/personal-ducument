#lang racket
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;env;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define nil '() )
(define empty-env nil)

(define ( extend-env! variable new-value env)
          (cons (cons variable new-value) env))

(define lookup
  (lambda (var env)
    (let ([p (assq var env)])    	;;assq 是在一个pair 组成的list中，找到以x为key的那个pair
                ;; (assq 3 (list (list 1 2) (list 3 4) (list 4 3)))返回(3 4)
      (cond
       [(not p) var]					;;在env中没有找到(x,)这样的p
       [else (cdr p)]))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;eval;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (eval exp env)
	(cond     [(self-evaluting? exp) exp]
		  [(variable? exp)       (lookup exp env)]
		  [(quoted? exp) (cadr exp)]
              [(define-variable? exp) (set! global-env  (eval-define exp env)) global-env]
              [(arit-expr? exp) (eval-arit exp env)]
              [(if-expr? exp) (eval-if exp env)]
              [(list? exp) (eval-list exp env)]
              [(lambda? exp) (eval-lambda exp env)]
              [(proc? exp)(eval-proc exp env)]
		))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


 ;;;self-evaluting expr 
(define (self-evaluting? exp)
	(cond [(number? exp) true ]
		[(string? exp) true]
		[else false]))

  ;;;variable
(define (variable? exp)
	 (symbol? exp))
 ;;; one help function:
 ;;; it just depends a expression is begin with some specific word or not
(define (is-begin-with exp tag)
   (if(pair? exp) 
      (eq? (car exp) tag)
       false))
  
 ;;;quote expr
(define (quoted? exp)
	(is-begin-with exp 'quote))
(define (define-variable? exp)
  (is-begin-with exp 'define))

(define (eval-define exp env)
  (let ([var (cadr exp)]
        [val (eval (caddr exp) env)])
  (extend-env! var val global-env))) 


(struct closure (func env))

(define (lambda? exp)
  (is-begin-with exp 'lambda))
(define (eval-lambda exp env)
   (closure  exp env))


(define (power num e)
   (if (= e 0) 
       1
       (* num (power num (- e 1)))))
(define (op? exp)
  ( if (or (eq? exp '+) (eq? exp '-) (eq? exp '*) (eq? exp '/) (eq? exp '%) (eq? exp '**) (eq? exp '>) (eq? exp '<) (eq? exp '=) (eq? exp 'cons))
       #t
       #f))
(define (arit-expr? exp)
	(if (op? (car exp))
		#t 
		#f))

(define (eval-arit exp env)
	(let (    [operand1 (eval (cadr exp) env )]
		  [operand2 (eval (caddr exp) env)]
		  [op (car exp)])

		( cond [(eq? op  '+)(+ operand1 operand2) ]
		       [(eq? op '-) (- operand1 operand2) ]
	           [(eq? op '*) (* operand1 operand2)]
	           [(eq? op '/) (/ operand1 operand2)]
	          [(eq? op '%) (remainder operand1 operand2)]
	          [(eq? op '**) (power operand1 operand2)]
	          [(eq? op '>) (> operand1 operand2)]
	          [(eq? op '<) (< operand1 operand2)]
	          [(eq? op '=) (= operand1 operand2)]
	          [(eq? op 'cons) (cons operand1 operand2)]
	        
		)))

(define (if-expr? exp)
	(is-begin-with exp 'if))

(define (eval-if exp env)
  (let      ([predicate (eval (cadr exp) env )]
		  [if-part (caddr exp)]
		  [else-part (cadddr exp)])
      (if   predicate
		(eval if-part env)
		(eval else-part	env))))


(define (list? exp)
   (is-begin-with exp 'list))
(define (eval-list exp env)
  (cdr exp))


(define (proc? exp)
	 (if (pair? exp)
	 	#t
	 	#f))
(define (eval-proc exp env)
	(let     ([func (eval (car exp) env)]
		  [para (eval (cadr exp) env )])
         ( if  (procedure? func)
              (func para)  
           (match func
            [
             (closure `(lambda (,x) ,body) env-temp)
            (eval body (extend-env! x para env-temp) )
            ]
		)
       )))
 









;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;drive-loop;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



(define input-pro ";;;GD-eval input:")
(define output-pro ";;;GD-eval value:")
(define (prompt-for-input string)
   (newline) (newline) (display string) (newline))
(define (annouce-output string)
  (newline)(display string)(newline))
(define (user-print object)
  ;(if(compound-func? object)
   ; (display (list 'compound-func (func-parameters object) (func-body object) '<env>))
    (display object))
;)


(define global-env nil)
 
(set! global-env (extend-env! 'length length  global-env ))
(set! global-env (extend-env! 'car car global-env))
(set! global-env (extend-env! 'cdr cdr global-env))

(display "Welcome to use GD-eval machine! You can quit it when you type 'exit'. ") 
(define (drive-loop)
  (prompt-for-input input-pro)
  (let ((input (read)))
    (if (eq? input 'exit)
        (exit)
       (let ((output (eval input global-env)))
         
        (annouce-output output-pro)
        (user-print output)
        )))
  (drive-loop))

(drive-loop)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

