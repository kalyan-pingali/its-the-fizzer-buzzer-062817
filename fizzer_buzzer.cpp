//Author   : V Kalyan Pingali
//Revision : v2.0
//Contact  : vepi3012@colorado.edu
//Date     : 06/28/2017

//*****************************************DESCRIPTION*****************************************
//Description - The program takes an integer input 'user_input' from the user (through standard input) and calculates the fibonacci number corresponding to the input. Eg: Input: 2 => Output: 1; Input: 10 => Ouput: 34; Input: 20 => Output: 4181
//NOTE : Beyond 93rd fibonacci number, all results are expressed modulo 1.5E+18
//Also, whenever the number produced is divisible by 3, 5 or 15, "Buzz", "Fizz" or "FizzBuzz" are printed correspondingly instead of the number itself! Eg: Input: 1 => Output: FizzBuzz; Input: 6 => Ouput: Fizz; Input: 9 => Output: Buzz.
//Explanation : 0 (1st Fibonacci number) is divisible by 15 => FizzBuzz; 5 (6th Fibonacci number) is divisible by 5; 21 (9th Fibonacci number) is divisible by 3.

//*****************************************VERSION HISTORY*****************************************
//Version history - v1.0 : Basic fibonacci program, prints out numbers. Time-outs for inputs over 45
//                - v1.1 : Support extended for inputs upto 93 using long long int, and adding stepping stones to aviod time-out
//                - v1.2 : Support upto 200 added by using modular arithmetic by 1.5E+18
#include <iostream>

#define modulo_wrapper 1500000000000000000
using namespace std;

long long fib( int input ){
	if(input==1){
		return 0;
	}
	else if(input==2 or input==3){
		return 1;
	}
    else if(input==40){
        return 63245986;
    }
    else if(input==41){
        return 102334155;
    }
    else if(input==81){
        return 23416728348467685;
    }
    else if(input==82){
        return 37889062373143906;
    }
    else if(input==121){
        return 754990966640871840;
    }
    else if(input==122){
        return 1398507948658051921;
    }
    else if(input==161){
        return 293000174702095995;
    }
    else if(input==162){
        return 432247806074196061;
    }
    else if(input>200){
        return -1;
    }
	else{
        return fib(input-2)%modulo_wrapper + fib(input-1)%modulo_wrapper;
	}
}

int main(void){
	int user_input;
  long long out;
	cin<<user_input;
  out = fib(user_input);
  cout<<out;
	return 0;
}
