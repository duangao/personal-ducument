def tokenAnalysis(strings):
    return strings.replace('(', ' ( ').replace(')', ' ) ').split()


def parse(tokens):
    first_token = tokens.pop(0)
    if first_token == '(':
        expr = []
        while tokens[0] != ')':
            expr.append(parse(tokens))
        tokens.pop(0)
        return expr
    else:
        return parse_constant_value(first_token)


def parse_constant_value(token):
    try:
        return int(token)
    except ValueError:
        try:
            return float(token)
        except ValueError:
            return Symbol(token)

##########################################################################################
List = list
Number = (int, float)
Symbol = str
Bool = bool


class Env(dict):
    def find(self, var):
        return self if (var in self) else self.outer.find(var)

    def __init__(self, parms=(), args=(), outer=None):
        self.update(zip(parms, args))
        self.outer = outer


###########################################################################################

def init_global_env():
    import math, operator as op

    env = Env()
    env.update(vars(math))
    env.update(
        {

            'car': lambda x: x[0],
            'cdr': lambda x: x[1:],
            'cons': lambda x, y: [x] + [y],
            'eq?': op.is_,
            'equal?': op.eq,
            'length': len,
            'list': lambda *x: list(x),
            'list?': lambda x: isinstance(x, list),
            'map': map,
            'not': op.not_,
            'null?': lambda x: x == [],
            'number?': lambda x: isinstance(x, Number),
            'proc?': callable,
            'symbol?': lambda x: isinstance(x, Symbol),
        })
    return env


global_env = init_global_env()




##proc###############################################

class Proc(object):
    def __init__(self, paras, body, env):
        self.paras = paras
        self.body = body
        self.env = env

    def __call__(self, *args):
        return eval(self.body, Env(self.paras, args, self.env))


######################################################



##########################################################

def is_begin_with(expr, specific_value):
    if expr[0] == specific_value:
        return True
    else:
        return False


operator = ['+', '-', '*', '/', '>', '<', '=', '>=', '<=']


def is_arit_expr(stat):
    if stat[0] in operator:
        return True
    else:
        return False


###############################################################################
def eval_var(var, env):
    result = var
    try:
        result = env.find(var)[var]
    except AttributeError:
        result = var
    return result


def eval_constant(cons_var):
    return cons_var


def eval_arit_expr(stat, env):
    (op, first, second) = stat
    first = eval(first, env)
    second = eval(second, env)
    if op == '+':
        return first + second
    elif op == '-':
        return first - second
    elif op == '*':
        return first * second
    elif op == '/':
        if second == 0:
            print("Wrong , the divide number cannot be zero!")
            return None
        else:
            return first / second
    elif op == '>':
        return first > second
    elif op == '<':
        return first < second
    elif op == '=':
        return first == second
    elif op == '<=':
        return first <= second
    elif op == '>=':
        return first >= second


def eval_quote(stat):
    (_, exp) = stat
    return exp


def eval_define(stat, env):
    (_, var, exp) = stat
    env[var] = eval(exp, env)


def eval_lambda(stat, env):
    (_, paras, body) = stat
    return Proc(paras, body, env)


def eval_begin(stat, env):
    for item in stat[1:-1]:
        eval(item, env)
    return eval(stat[-1])


################################################################################



def eval(stat, env=global_env):
    while (True):

        if isinstance(stat, Symbol):
            return eval_var(stat, env)

        elif not isinstance(stat, List):
            return eval_constant(stat)

        elif is_arit_expr(stat):
            return eval_arit_expr(stat, env)

        elif is_begin_with(stat, 'quote'):
            return eval_quote(stat)

        elif is_begin_with(stat, 'if'):
            (_, test, if_part, else_part) = stat
            stat = (if_part if eval(test, env) else else_part)
        elif is_begin_with(stat, 'define'):
            return eval_define(stat, env)

        elif is_begin_with(stat, 'lambda'):
            return eval_lambda(stat, env)

        elif is_begin_with(stat, 'exit'):
            exit()

        elif is_begin_with(stat, 'begin'):
            return eval_begin(stat, env)

        else:
            expr = [eval(item, env) for item in stat]
            proc = expr.pop(0)
            if isinstance(proc, Proc):
                stat = proc.body
                env = Env(proc.paras, expr, proc.env)
            else:
                return proc(*expr)


##############################################################
def REPL(program=";;;GD-interpreter >"):
    while True:
        result = eval(parse(tokenAnalysis(input(program))))
        my_print(result)


def my_print(value):
    if value is True:
        print("#t")
    elif value is False:
        print("#f")
    elif value is None:
        pass
    else:
        print (value)


# run########################################################
REPL()