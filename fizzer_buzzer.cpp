//Author   : V Kalyan Pingali
//Revision : v2.1
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

#include <iostream>

#define modulo_wrapper 1500000000000000000	// 1.5E+18 is considered as it is just greater than the limit of long long int,
						// and there is no Fibonacci number between the upper limit and this
						// Also 1.5E+18 is divisible by 15, and hence 3 and 5 too
#define Fib_40 63245986				// 40th Fibonacci number
#define Fib_41 102334155			// 41st Fibonacci number
#define Fib_81 23416728348467685		// 81st Fibonacci number
#define Fib_82 37889062373143906		// 82nd Fibonacci number
#define Fib_121 754990966640871840		// 121st Fibonacci number modulo 1.5E+18
#define Fib_122 1398507948658051921		// 122nd Fibonacci number modulo 1.5E+18
#define Fib_161 293000174702095995		// 161st Fibonacci number modulo 1.5E+18
#define Fib_162 432247806074196061		// 162nd Fibonacci number modulo 1.5E+18

using namespace std;

long long fib( int input ){
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
    else if(input>200 || input<1){
        return -1;
    }
	else{
        return fib(input-2)%modulo_wrapper + fib(input-1)%modulo_wrapper;
	}
}

int main(void){
    int user_input;
    long long out;
    if((scanf("%d", &user_input))==1){
        cout<<user_input<<endl;
        out = fib(user_input);
        int mod_3 = out%3;
        int mod_5 = out%5;
        if(out==-1){
            cout<<"Input entered is not within bounds [1,200]";
        }
        else if(mod_3==0){
            if(mod_5==0){
                cout<<"FizzBuzz";
            }
            else{
                cout<<"Buzz";
            }
        }
        else if(mod_5==0){
            cout<<"Fizz";
        }
        else{
            cout<<out;
        }
    }
    else{
        cout<<"Input not supported!";
    }
    return 0;
}
