/*
 * Dhruv Patel, Lab 3
 */
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "roster.h"

using namespace std;
using namespace csen79;

// Test code for class roster
// Input file: <CMD> [ID] [FIRST LAST]
// CMD : A | X | L
// ID: 7-digit unsigned integer
// FIRST, LAST: string
int main() {
	Roster r;
	Student::ID_t id;
	string cmd, first, last;

    /*  THE CODE THAT IS COMMENTED BELOW IS FOR SOME TEST CASES  */
	// Student test1(1, "Adam1", "dave1");
	// Student test2(2, "Adam2", "dave2");
	// Student test3(3, "Adam3", "dave3");


	// //cout<<test<<endl;
	// r.insert(test1);
	// r.insert(test2);
	// r.insert(test3);
	// int i = 1;
	


	// for (auto st = r.begin(); st != r.end(); st = r.next(), ++i)
	// 	cout << i << ": " << *st << endl;
	// for(auto a = r.begin(); a != r.end(); a = r.next()){
	// 			cout << *a<<endl;;
	// }

	//Read cmd first, then branch accordingly
	while (cin >> cmd) {
		cout << cmd << endl;
		if (cmd == "A") {
			cin >> id >> first >> last;
            Student newStudent(id, first, last); // Create a new student object
			//cout << "Inserting student: " <<newStudent << endl;
            r.insert(newStudent); // Insert the new student into the roster
		} else if (cmd == "X") {
			cin >> id;
            r.erase(id); // Erase the student with the given ID from the roster
		} else if (cmd == "L") {
			// this should just work, if you did your begin/end/next correctly
			int i = 1;
			for(auto a = r.begin(); a != r.end(); a = r.next(), i++){
				cout <<i<<": "<< *a<<endl;
			}
		}
		else{
			cout<<"Invalid operator"<<endl;
		}
	}
	return EXIT_SUCCESS;
}

