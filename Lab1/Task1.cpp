#include<stdio.h>
#include<iostream>
#include<string> 
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;

int main(){
    int AN = 0;
    int notAN = 0;
    /* Get input */
    string input;
    cout << "Enter a word to count Alphanumeric characters: ";
    getline(cin, input);

    /* Count length for usage in for loop */
    int length = input.length();

    
    /* Loop to count alphanumeric characters*/
    int n;
    for(n = 0; n<length; n+=1){
   
        if(isalnum(input[n])){
            AN+=1;
        }else if(input[n] == ' '){
            continue;
        }else{
            notAN +=1;
        }

    }

    /*output*/
    cout<<"Your input had "<<AN<<" Alphanumeric characters, and "<<notAN<<" non Alphanumeric characters \n";
    return 0;
}

