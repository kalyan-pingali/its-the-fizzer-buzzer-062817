//Author   : V Kalyan Pingali
//Revision : v2.3
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
//                - v2.0 : Buzz, Fizz or FizzBuzz if divisible by 3, 5 or 15. Else number printed
//                - v2.1 : #defines added instead of raw numbers
//                - v2.2 : Negative inputs avoided
//		  - v2.3 : Non integral inputs avoided (See issues), comments added, user input prompt added

#include <iostream>
#include <string>

#define modulo_wrapper 1500000000000000000			// 1.5E+18 is considered as it is just greater than the limit of long long int,
								// and there is no Fibonacci number between the upper limit and this
								// Also 1.5E+18 is divisible by 15, and hence 3 and 5 too
#define Fib_40 63245986						// 40th Fibonacci number
#define Fib_41 102334155					// 41st Fibonacci number
#define Fib_81 23416728348467685				// 81st Fibonacci number
#define Fib_82 37889062373143906				// 82nd Fibonacci number
#define Fib_121 754990966640871840				// 121st Fibonacci number modulo 1.5E+18
#define Fib_122 1398507948658051921				// 122nd Fibonacci number modulo 1.5E+18
#define Fib_161 293000174702095995				// 161st Fibonacci number modulo 1.5E+18
#define Fib_162 432247806074196061				// 162nd Fibonacci number modulo 1.5E+18

using namespace std;

long long fib( int input ){					// Using recursion to calculate fibonacci number
    if(input==1){
	return 0;
    }
    else if(input==2 or input==3){
	return 1;
    }
    else if(input==40){
	return Fib_40;
    }
    else if(input==41){
	return Fib_41;
    }
    else if(input==81){
	return Fib_81;
    }
    else if(input==82){
	return Fib_82;
    }
    else if(input==121){
	return Fib_121;
    }
    else if(input==122){
	return Fib_122;
    }
    else if(input==161){
	return Fib_161;
    }
    else if(input==162){
	return Fib_162;
    }
    else if(input>200 || input<1){				// if input is not within bounds defined
	return -1;
    }
    else{
	return fib(input-2)%modulo_wrapper + fib(input-1)%modulo_wrapper;
    }
}

int modify_string(string input_string){
    const char *char_input = input_string.c_str();		// Convert string entered by user to character pointer for use in atoi()
    int user_input = atoi(char_input);				// Converting to integer
    string test = to_string(user_input);			// Converting integer back to string format; test is integer part of input as a string
    if(!test.compare(input_string)){				// Comparing user input and modified input (test) are same, to check for non integral inputs
        return user_input;
    }
    else{
        return -1;                              
    }
}

int main(void){
    string user_str;						// To store raw user input
    long long out;						// To store output
    cout<<"Please enter an integer between (including) 1 and 200 : ";
    cin>>user_str;						// Read input from user
	int user_input = modify_string(user_str);
    if(user_input==-1){
        cout<<"Input not supported!";				// If input is not an integer
    }	
    else{	
	out = fib(user_input);					// Calling fib function with argument user_input
	bool mod_3 = (out%3==0)?true:false;			// returned output of function fib modulo 3
	bool mod_5 = (out%5==0)?true:false;			// returned output of function fib modulo 5
    	if(out==-1){						// To check if integer is within bounds
	    cout<<"Input entered is not within bounds [1,200]";
    	}
	else if(mod_3 && mod_5){				// If output is divisible by 15
    	    cout<<"FizzBuzz";	
	}	
	else if(mod_3 && !(mod_5)){				// only divisible by 3
	    cout<<"Buzz";	
	}	
	else if(!(mod_3) && mod_5){				// only divisible by 5
	    cout<<"Fizz";
	}
	else{							// not divisible by 3 and/or 5
	    cout<<out;
	}
    }
    return 0;
}
