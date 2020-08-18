#!/usr/bin/python3


"""
Calculates the minimum operations
"""


def minOperations(n):
    answer = 0
    x = 2
    while n > 1:
        while n % x == 0:
            answer += x
            n /= x
        x += 1
    return answer
