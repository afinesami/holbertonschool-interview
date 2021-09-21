#!/usr/bin/python3
""" Prime Game """


def isprime(n):
    """ n: number to check if it is prime"""
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def delete_numbers(n, nums):
    """ delete numbers - assign zero """
    for i in range(len(nums)):
        if nums[i] % n == 0:
            nums[i] = 0


def isWinner(x, nums):
    """ where x is the number of rounds and nums is an array of n
        Return: name of the player that won the most rounds
        Iriaf the winner cannot be determined, return None
        You can assume n and x will not be larger than 10000
    """
    nums.sort()
    winner = False
    Maria = 0
    Ben = 0
    for game in range(x):
        # print("game# ", game+1)
        nums2 = list(range(1, nums[game] + 1))
        # print("nums: ", nums2)
        turn = 0
        while True:
            """
            # uncomment to monitor turns
            if turn % 2 != 0:
                print("Ben turn ")
            else:
                print("Maria turn ")
            """
            change = False
            for i, n in enumerate(nums2):
                # print("n: ", n, "i: ", i)
                if n > 1 and isprime(n):
                    delete_numbers(n, nums2)
                    change = True
                    turn += 1
                    break
            # print("movement: ", nums2)
            if change is False:
                break
        if turn % 2 != 0:
            Maria += 1
        else:
            Ben += 1
        # print("Maria: {}, Ben: {}".format(Maria, Ben))
    if Maria == Ben:
        return None
    if Maria > Ben:
        return "Maria"
    return "Ben"
