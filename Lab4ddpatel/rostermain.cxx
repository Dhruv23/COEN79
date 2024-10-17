// dhruv patel 
// Lab 4 - rostermain.cxx
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "roster.h"

using namespace std;
using namespace csen79;

int main() {
    Roster r;
    Student::ID_t id;
    string cmd, first, last;

    while (cin >> cmd) {
        cout << cmd << endl;
        if (cmd == "A") {
            cin >> id >> first >> last;
            Student newStudent(id, first, last);
            r.insert(newStudent);
        } else if (cmd == "X") {
            cin >> id;
            r.erase(id);
        } else if (cmd == "L" && r.getSize() !=0) {
            int i = 1;
            for (auto a = r.begin(); a != r.end(); a = r.next(a), ++i) {
                cout << i << ": " << *a << endl;
            }
        } else {
            cout << "Invalid operator" << endl;
        }
    }
    r.delRoster();
    return EXIT_SUCCESS;
}
