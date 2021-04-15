#!/usr/bin/python3
"""
0. Rain mandatory
Given a list of non-negative integers
"""


def rain(walls):
    """
    0. Rain mandatory
    """
    if (len(walls) < 2):
        return 0
    return sum([i for i in walls[1:-1] if i > 0])
