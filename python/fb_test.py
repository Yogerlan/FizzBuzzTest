#!/usr/bin/python


import sys


def fizzbuzz(fizz, buzz, start, end):
    """
    Prints the numbers from "start" to "end". But for multiples of "fizz" print
    "Fizz" instead of the number and for the multiples of "buzz" print "Buzz".
    For numbers which are multiples of both "fizz" and "buzz" print "FizzBuzz".

    Parameters
    ----------
    fizz : int
        Print "Fizz" if the list index is divisible by "fizz".
    buzz : int
        Print "Buzz" if the list index is divisible by "buzz".
    start : int
        Starting iteration index.
    end : int
        Ending iteration index.

    The list can be filled in ascendent or descendent order.
    """

    if start <= end:
        for i in range(start, end + 1):
            fb = (i, ('', 'Fizz')[i % fizz == 0] + ('', 'Buzz')[i % buzz == 0]) \
                 [i % fizz == 0 or i % buzz == 0]
            print(fb)
    else:
        for i in reversed(range(end, start + 1)):
            fb = (i, ('', 'Fizz')[i % fizz == 0] + ('', 'Buzz')[i % buzz == 0]) \
                 [i % fizz == 0 or i % buzz == 0]
            print(fb)


if __name__ == '__main__':
    fizz = 3
    buzz = 5
    start = 1
    end = 100

    # Get fizz, buzz, start & end params from command line arguments.
    for a in range(1, len(sys.argv)):
        if sys.argv[a] == '-f':
            fizz = int(sys.argv[a + 1])
        if sys.argv[a] == '-b':
            buzz = int(sys.argv[a + 1])
        if sys.argv[a] == '-s':
            start = int(sys.argv[a + 1])
        if sys.argv[a] == '-e':
            end = int(sys.argv[a + 1])

    fizzbuzz(fizz, buzz, start, end)

    try:
        input('Press ENTER to continue...')
    except:
        pass
