#!/usr/bin/python3
""" Rain based on walls """


def rain(walls):
    """ Given a list of non-negative integers
    representing walls of width 1, calculate how
    much water will be retained after it rains.
    """
    l1 = len(walls)
    if l1 == 0 or l1 == 1 or l1 == 2:
        return 0

    water = 0
    while l1 >= 3:
        w2 = walls.copy()
        w2.sort()
        top = w2[-1]
        top2 = w2[-2]
        idx1 = walls.index(top)
        idx2 = walls.index(top2)
        if idx1 == idx2:
            idx2 = walls.index(top2, idx1+1)
        idx = [idx1, idx2]
        idx.sort()
        limit = min([walls[idx[0]], walls[idx[1]]])
        for i in range(idx[0]+1, idx[1]):
            water += limit - walls[i]
        for i in range(idx[0], idx[1]+1):
            del walls[idx[0]]
        walls.insert(idx[0], limit)
        l1 = len(walls)

    return water
