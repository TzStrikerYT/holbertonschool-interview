#!/usr/bin/python3
import sys


def nqueens(n):
    """ The N queens puzzle is the challenge
            of placing N non-attacking queens on an N×N chessboard
    """
    def nqueensv2(queens, cord_dif, cord_sum):
        """ Recursive function
        """
        p = len(queens)
        if p == n:
            result.append(queens)
            return None
        for q in range(n):
            if q not in queens and p-q not in cord_dif and p+q not in cord_sum:
                nqueensv2(queens + [q], cord_dif + [p - q], cord_sum + [p + q])
    result = []
    final_result = []
    nqueensv2([], [], [])
    for row in result:
        for i, col in enumerate(row):
            coord = [i, col]
            final_result.append(coord)
        print(final_result)
        final_result = []


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)
    nqueens(n)
