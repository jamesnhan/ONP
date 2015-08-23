# ONP - Transform the Expression

Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). Two-argument operators: +, -, *, /, ^ (priority from lowest to highest), brackets (). Operands: only letters: a, b, ..., z. Assume that there is only one RPN form (no expressions like a\*b\*c).

## Input

''' c
    t [the number of expressions <= **100**]
    *expression* [length <= **400**]
    [other expressions]
'''

Text grouped in [] do not appear in the input file.

## Output

''' c
    The *expression* in RPN form, one per line.
'''

## Example

''' c
    Input:
    3
    (a+(b*c))
    ((a+b)*(z+x))
    ((a+t)*((b+(a+c))^(c+d)))

    Output:
    abc*+
    ab+zx+*
    at+bac++cd+^*
'''
