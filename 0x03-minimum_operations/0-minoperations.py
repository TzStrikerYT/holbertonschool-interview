#!/usr/bin/python3
"""
Function that calculates the min operations to copy and paste letters
"""
def minOperations(n):
    """ caculation of the operations """

    if type(n) == int or n > 1:
        return int(operations(n))
    else:
        return 0
        
def operations(n):
    """ calculates n operations to copy paste """
    
    op = 2
    sum = 0
    
    while n >= op:  
        if n % op == 0:
            n = n // op
            sum += op
        else:
            op += 1
    
    return sum