#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard.
Write a program that solves the N queens problem.
"""
import sys


''' Python3 program to solve N Queen Problem using 
backtracking '''
k = 1

# A utility function to print solution 
def printSolution(board): 

	global k
	print(k, "-\n")
	k = k + 1
	for i in range(4): 
		for j in range(4):
			print(board[i][j], end = " ")
		print("\n")
	print("\n") 

''' A utility function to check if a queen can 
be placed on board[row][col]. Note that this 
function is called when "col" queens are 
already placed in columns from 0 to col -1. 
So we need to check only left side for 
attacking queens '''
def isSafe(board, row, col) :
	
	# Check this row on left side 
	for i in range(col): 
		if (board[row][i]): 
			return False

	# Check upper diagonal on left side 
	i = row
	j = col
	while i >= 0 and j >= 0:
		if(board[i][j]):
			return False;
		i -= 1
		j -= 1

	# Check lower diagonal on left side 
	i = row
	j = col
	while j >= 0 and i < 4:
		if(board[i][j]):
			return False
		i = i + 1
		j = j - 1

	return True

''' A recursive utility function to solve N 
Queen problem '''
def solveNQUtil(board, col) :
	
	''' base case: If all queens are placed 
	then return true '''
	if (col == 4): 
		printSolution(board) 
		return True

	''' Consider this column and try placing 
	this queen in all rows one by one '''
	res = False
	for i in range(4):
	
		''' Check if queen can be placed on 
		board[i][col] '''
		if (isSafe(board, i, col)): 
		
			# Place this queen in board[i][col] 
			board[i][col] = 1; 

			# Make result true if any placement 
			# is possible 
			res = solveNQUtil(board, col + 1) or res; 

			''' If placing queen in board[i][col] 
			doesn't lead to a solution, then 
			remove queen from board[i][col] '''
			board[i][col] = 0 # BACKTRACK 
		
	''' If queen can not be place in any row in 
		this column col then return false '''
	return res

''' This function solves the N Queen problem using 
Backtracking. It mainly uses solveNQUtil() to 
solve the problem. It returns false if queens 
cannot be placed, otherwise return true and 
prints placement of queens in the form of 1s. 
Please note that there may be more than one 
solutions, this function prints one of the 
feasible solutions.'''
def solveNQ() :

	board = [[0 for j in range(10)] 
				for i in range(10)]

	if (solveNQUtil(board, 0) == False): 
	
		print("Solution does not exist") 
		return
	return

# Driver Code 
solveNQ() 

# This code is contributed by YatinGupta


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

# Python program to solve N Queen 
# Problem using backtracking 

global N 
N = 4

def printSolution(board): 
	for i in range(N): 
		for j in range(N): 
			print board[i][j], 
		print


# A utility function to check if a queen can 
# be placed on board[row][col]. Note that this 
# function is called when "col" queens are 
# already placed in columns from 0 to col -1. 
# So we need to check only left side for 
# attacking queens 
def isSafe(board, row, col): 

	# Check this row on left side 
	for i in range(col): 
		if board[row][i] == 1: 
			return False

	# Check upper diagonal on left side 
	for i, j in zip(range(row, -1, -1), range(col, -1, -1)): 
		if board[i][j] == 1: 
			return False

	# Check lower diagonal on left side 
	for i, j in zip(range(row, N, 1), range(col, -1, -1)): 
		if board[i][j] == 1: 
			return False

	return True

def solveNQUtil(board, col): 
	# base case: If all queens are placed 
	# then return true 
	if col >= N: 
		return True

	# Consider this column and try placing 
	# this queen in all rows one by one 
	for i in range(N): 

		if isSafe(board, i, col): 
			# Place this queen in board[i][col] 
			board[i][col] = 1

			# recur to place rest of the queens 
			if solveNQUtil(board, col + 1) == True: 
				return True

			# If placing queen in board[i][col 
			# doesn't lead to a solution, then 
			# queen from board[i][col] 
			board[i][col] = 0

	# if the queen can not be placed in any row in 
	# this colum col then return false 
	return False

# This function solves the N Queen problem using 
# Backtracking. It mainly uses solveNQUtil() to 
# solve the problem. It returns false if queens 
# cannot be placed, otherwise return true and 
# placement of queens in the form of 1s. 
# note that there may be more than one 
# solutions, this function prints one of the 
# feasible solutions. 
def solveNQ(): 
	board = [ [0, 0, 0, 0], 
			[0, 0, 0, 0], 
			[0, 0, 0, 0], 
			[0, 0, 0, 0] 
			] 

	if solveNQUtil(board, 0) == False: 
		print "Solution does not exist"
		return False

	printSolution(board) 
	return True

# driver program to test above function 
solveNQ() 

# This code is contributed by Divyanshu Mehta 
