**Author**
V Kalyan Pingali

**Revision**
v2.3

**Contact**
pnglkalyan@gmail.com

**Date**
06/28/2017

****DESCRIPTION****

The program takes an integer input 'user_input' from the user (through standard input) and calculates the fibonacci number corresponding to the input. Eg: Input: 2 => Output: 1; Input: 10 => Ouput: 34; Input: 20 => Output: 4181

Also, whenever the number produced is divisible by 3, 5 or 15, "Buzz", "Fizz" or "FizzBuzz" are printed correspondingly instead of the number itself! Eg: Input: 1 => Output: FizzBuzz; Input: 6 => Ouput: Fizz; Input: 9 => Output: Buzz.

Explanation : 0 (1st Fibonacci number) is divisible by 15 => FizzBuzz; 5 (6th Fibonacci number) is divisible by 5; 21 (9th Fibonacci number) is divisible by 3.

**NOTE**
Beyond 93rd fibonacci number, all results are expressed modulo 1.5E+18

**NOTE**
Input numbers beyond [-2147483648, 2147483647] will be treated as unsupported inputs (Out of Int bounds)

****VERSION HISTORY****

v1.0 : Basic fibonacci program, prints out numbers. Time-outs for inputs over 45

v1.1 : Support extended for inputs upto 93 using long long int, and adding stepping stones to aviod time-out

v1.2 : Support upto 200 added by using modular arithmetic by 1.5E+18

v2.0 : Buzz, Fizz or FizzBuzz if divisible by 3, 5 or 15. Else number printed

v2.1 : #defines added instead of raw numbers

v2.2 : Negative inputs avoided

v2.3 : Non integral inputs avoided (See issues), comments added, user input prompt added
