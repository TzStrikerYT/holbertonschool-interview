#!/usr/bin/python3
"""
Pascal Triangle
"""


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers
    representing the Pascal’s triangle of n

    Arguments:
     - n will be always an integer

    Returns:
     An empty list if n <= 0
    """

    pascal = []
    for i in range(1, n + 1):
        row = []
        for j in range(i):
            if j == 0 or j == i - 1:
                row.append(1)
            else:
                n = pascal[i - 2][j - 1] + pascal[i - 2][j]
                row.append(n)
        pascal.append(row)

    return pascal
