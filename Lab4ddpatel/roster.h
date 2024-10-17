// dhruv patel 
// Lab 4 - roster.h
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>

namespace csen79 {
    class Student {
    public:
        using ID_t = unsigned int;
        Student() : ID(0), firstName(""), lastName("") {}
        Student(ID_t n, std::string fn, std::string ln);
        ID_t getID() const { return ID; }
        std::string getFirstName() const { return firstName; }
        std::string getLastName() const { return lastName; }
        friend std::ostream& operator<<(std::ostream& os, const Student& t);
    private:
        ID_t ID;
        std::string firstName;
        std::string lastName;
    };

    class Roster {
    public:
        using S = Student;
        Roster();
        void delRoster();
        void insert(S& rec);
        void erase(Student::ID_t id);
        int getSize() const {return size;}
        S* begin();
        S* end();
        S* next(S* &current);
    private:
        S* roster; // Pointer to Student
        int capacity;
        int size;
        static const int INITIAL_CAPACITY = 10; // Initial capacity for roster
        void resize();
    };
}

#endif // ROSTER_H
