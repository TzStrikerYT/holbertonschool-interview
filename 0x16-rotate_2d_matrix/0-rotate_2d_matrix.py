#!/usr/bin/python3

""" Rotate 2D Matrix
"""


def rotate_2d_matrix(mat):
    """
    Rotates 2d mat by 90 degrees.
    """
    num = len(mat)
    for x in range(int(num / 2)):
        offset = 0
        i = num - 1 - x
        for y in range(x, num - 1 - x):
            top = mat[x][y]
            mat[x][y] = mat[i - offset][x]
            mat[i - offset][x] = mat[i][i - offset]
            mat[i][i - offset] = mat[y][i]
            mat[y][i] = top
            offset += 1
