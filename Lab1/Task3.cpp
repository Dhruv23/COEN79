#include <iostream>

#include <fstream>

#include <string>

using namespace std;

string lowerToUpper(string str){
    int i;
    int length = str.size();
    for(i=0; i<=length; i+=1){

        if(str[i]>=97 && str[i]<=122){ /* Use the ascii values of the string to check if it is lower case. If it is, translate it to uppercase by subtracting 32 */

            str[i]=str[i]-32;
            
        }
            if((str[i]>=65 && str[i]<=90)||(str[i]>=48 && str[i]<=57) ){ /* if uppercase or number do nothing */

                continue;
            }

        else{ /* if not letter or number, replace with null character*/

            str[i]=0;

        }

    } 

    return str;

}

int main(){
    string name;
    cout << "Enter the name of the file you would like to use: ";
    getline(cin, name);
    ifstream inputFile(name);
    if (!inputFile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        return 1; 
    } 
    string word;


    while (inputFile >> word){
        for(int i = word.length() - 1; i>=0; i--){
            if(!(isalnum(word[i]))){
                word.erase(i,1);
            }
        }
        if(word.length()>=10){
            cout<<lowerToUpper(word)<<endl;
        }
        else{
            continue;
        }
    }

}

