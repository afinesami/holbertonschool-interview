#!/usr/bin/python3
import numpy as np
isWinner = __import__('0-prime_game').isWinner

np.random.seed(0)
print("Winner: {}".format(isWinner(5, [1, 2, 3, 4, 5])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(4, [1, 2, 3, 4, 5])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(3, [1, 2, 3, 4, 5])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(2, [1, 2, 3, 4, 5])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(1, [1, 2, 3, 4, 5])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(5, [1, 2, 3, 4])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(5, [1, 2, 3])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(5, [1, 2, 3, 4, 5, 6])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(5, [1, 3, 8, 9, 12, 14])))
print("----new game-----"*5)
print("Winner: {}".format(isWinner(3000,
                          np.random.randint(10000, size=10000).tolist())))
print("----new game-----"*5)
