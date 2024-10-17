/*
* Name: Dhruv Patel 
* Email: ddpatel@scu.edu
* Student ID: W1634050
* Contact: 4088059668
* Assignment: this program takes a ten digit string, and prints the desired pattern.
* File: 2 of 3
*/


#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string reversestring(string str)
{
  int i,len=0,n;
  char temp;
  len=str.length();
  n=len-1;
  for(i = 0; i <=(len/2); i++)
  {
    temp=str[i];
    str[i]=str[n];
    str[n]=temp;
    n--;
  }
  return str;
}
int main()

{
    /* define strings */
    string order;    
    cout <<"input a string of length 10: ";
    getline(cin, order);
    
    if(order.length() != 10){
        cout << "String was not of length 10 \n";
        return -1;
    }
    string empty = " ";
    string reversed;
    reversed = reversestring(order);
    cout << "Reversed string is: " << reversed << " \n";

    /* print first set of digits */
    cout<<right<<setw(20)<<order<<empty<<endl;

    /* for loop to increment the spacing between the in order and reversed for lines 2 - 5 */
    for(int n = 10; n<14; n+=1)
    {
        cout<<right<<empty<<setw(2 * n)<<reversed<<right<<setw(2 * n)<<order<<endl;
    }

    /* print last set of digits */
    cout<<right<<empty<<setw(28)<<reversed<<empty<<endl;


    return 0;

}