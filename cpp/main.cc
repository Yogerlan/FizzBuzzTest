#include <cstring>
#include <iostream>
#include <limits>

/**
 * Prints the numbers from "start" to "end". But for multiples of "fizz" print
 * "Fizz" instead of the number and for the multiples of "buzz" print "Buzz".
 * For numbers which are multiples of both "fizz" and "buzz" print "FizzBuzz".
 *
 * @param fizz Prints "Fizz" if the list index is divisible by "fizz".
 * @param buzz Prints "Buzz" if the list index is divisible by "buzz".
 * @param start Starting iteration index.
 * @param end Ending iteration index.
 * 
 * The list can be filled in ascendent or descendent order.
 */
void fizzbuzz(int fizz, int buzz, int start, int end) {
    std::string fb;
    if (start <= end) {
        for (int i = start; i <= end; i++) {
            fb = (i % fizz) == 0 || (i % buzz == 0)
               ? std::string(i % fizz == 0 ? "Fizz" : "") + std::string(i % buzz == 0 ? "Buzz" : "")
               : std::to_string(i);
            std::cout << fb << std::endl;
        }
    } else {
        for (int i = start; i >= end; i--) {
            fb = (i % fizz) == 0 || (i % buzz == 0)
               ? std::string(i % fizz == 0 ? "Fizz" : "") + std::string(i % buzz == 0 ? "Buzz" : "")
               : std::to_string(i);
            std::cout << fb << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    int fizz = 3;
    int buzz = 5;
    int start = 1;
    int end = 100;

    // Get fizz, buzz, start & end params from command line arguments.
    for (int a = 0; a < argc; a++) {
        if (std::strcmp(argv[a], "-f") == 0) {
            fizz = std::stoi(argv[a + 1]);
        }
        if (std::strcmp(argv[a], "-b") == 0) {
            buzz = std::stoi(argv[a + 1]);
        }
        if (std::strcmp(argv[a], "-s") == 0) {
            start = std::stoi(argv[a + 1]);
        }
        if (std::strcmp(argv[a], "-e") == 0) {
            end = std::stoi(argv[a + 1]);
        }
    }

    fizzbuzz(fizz, buzz, start, end);
    
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
