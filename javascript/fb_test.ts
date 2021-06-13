'use strict';
import * as readline from 'readline';

/**
 * Prints the numbers from "start" to "end". But for multiples of "fizz" print
 * "Fizz" instead of the number and for the multiples of "buzz" print "Buzz".
 * For numbers which are multiples of both "fizz" and "buzz" print "FizzBuzz".
 *
 * @param fizz - Prints "Fizz" if the list index is divisible by "fizz".
 * @param buzz - Prints "Buzz" if the list index is divisible by "buzz".
 * @param start - Starting iteration index.
 * @param end - Ending iteration index.
 * 
 * The list can be filled in ascendent or descendent order.
 */
function fizzbuzz(fizz: number, buzz: number, start: number, end: number) {
    if (start <= end) {
        for (let i = start; i <= end; i++) {
            let fb = (i % fizz == 0) || (i % buzz == 0)
                   ? (i % fizz == 0 ? 'Fizz' : '') +  (i % buzz == 0 ? 'Buzz' : '')
                   : i;
            console.log(fb);
        }
    } else {
        for (let i = start; i >= end; i--) {
            let fb = (i % fizz == 0) || (i % buzz == 0)
                   ? (i % fizz == 0 ? 'Fizz' : '') +  (i % buzz == 0 ? 'Buzz' : '')
                   : i;
            console.log(fb);
        }
    }
}

var fizz = 3;
var buzz = 5;
var start = 1;
var end = 100;

// Get fizz, buzz, start & end params from command line arguments.
const argv = process.argv.slice(2);
for (let a = 0; a < argv.length; a++) {
    if (argv[a] == '-f') {
        fizz = argv[a + 1];
    }
    if (argv[a] == '-b') {
        buzz = argv[a + 1];
    }
    if (argv[a] == '-s') {
        start = argv[a + 1];
    }
    if (argv[a] == '-e') {
        end = argv[a + 1];
    }
}

fizzbuzz(fizz, buzz, start, end);

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.question('Press ENTER to continue...', () => {
    rl.close();
});
