#!/usr/bin/env python3
""" nQueens project"""
import sys


def nQueens(n):
    """ This function should be resolve the problem of n queens in a chest table with size n * n """

    def nQueensV2(queens, cord_dif, cord_sum):
        """ Recursive function """
        p = len(queens)
        if p == n:
            result.append(queens)
            return None
        for q in range(n):
            if q not in queens and p - q not in cord_dif and p + q not in cord_sum:
                nQueensV2(queens + [q], cord_dif + [p - q], cord_sum + [p + q])

    result = []
    final_result = []
    nQueensV2([], [], [])
    for row in result:
        for i, col in enumerate(row):
            coord = [i, col]
            final_result.append(coord)
        print(final_result)
        final_result = []

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    num = sys.argv[1]

    try:
        num = int(num)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if num < 4:
        print("N must be at least 4")
        sys.exit(1)

    nQueens(num)