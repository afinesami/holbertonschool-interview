#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard.
Write a program that solves the N queens problem.
"""
import sys


def decode(list):
    """
    fn decode for square NxN
    """
    try:
        if len(list[0]) != 2:
            print("Usage: nqueens N")
            exit(1)
        NxN = int(list[0][1])
        if NxN < 4:
            print("N must be at least 4")
            exit(1)

        col = list[1]
        listThreats = list[2]
        for row in range(NxN):
            nonAttacking = 1
            for move in listThreats:
                if move[1] == row:
                    nonAttacking = 0
                    break
                if col - row == move[0] - move[1]:
                    nonAttacking = 0
                    break
                if row - move[1] == move[0] - col:
                    nonAttacking = 0
                    break
            if nonAttacking == 1:
                listThreats.append([col, row])
                if NxN - 1 != col:
                    decode([list[0], col + 1, listThreats])
                else:
                    print(listThreats)
                del listThreats[-1]

    except ValueError:
        print("N must be a number")
        exit(1)


# run init function for default
decode([sys.argv, 0, []])
