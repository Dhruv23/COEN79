
/*
 *  Dhruv Patel, Lab 6
 */
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>

namespace csen79 {
    class Student {
    public:
        using ID_t = unsigned int;
        Student(ID_t n, std::string fn, std::string ln);
        friend std::ostream& operator<<(std::ostream& os, const Student &);

        int getID() const { return ID; }
        std::string getFirstName() const { return firstName; }
        std::string getLastName() const { return lastName; }
        Student() : ID(0), firstName(""), lastName("") {}

    private:
        int ID;
        std::string firstName;
        std::string lastName;
    };

    class Node {
    public:
        Student data;
        Node* next;
        Node(Student s) : data(s), next(nullptr) {}
    };

    class Roster {
    public:
        Roster() : head(nullptr), tail(nullptr), size(0) {}
        void insert(Student &);
        void erase(Student::ID_t);
        Node* begin(void);
        Node* next(void);
        Node* end(void);
        int getSize() const { return size; }

    private:
        Node* head;
        Node* tail;
        int size;
    };
}

#endif // ROSTER_H
