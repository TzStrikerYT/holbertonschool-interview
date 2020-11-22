#!/usr/bin/python3
""" Rain task """


def rain(walls):
    """ Function that return the value of water
    that can contains into the walls """

    if walls is None:
        return 0

    n = len(walls)
    water = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])

        water += (min(left, right) - walls[i])

    return water
