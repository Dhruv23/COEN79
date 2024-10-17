// dhruv patel 
// Lab 4 - roster.cxx 
#include <string>
#include <iostream>
#include <stdexcept>
#include "roster.h"

namespace csen79 {
    static int index = -1;
    Student::Student(Student::ID_t n, std::string fn, std::string ln) {
        this->ID = n;
        this->firstName = fn;
        this->lastName = ln;
    }

    std::ostream& operator<<(std::ostream& os, const Student& t) {
        os << "ID: " << t.getID() << ", First Name: " << t.getFirstName() << ", Last Name: " << t.getLastName();
        return os;
    }

    Roster::Roster() : roster(nullptr), capacity(INITIAL_CAPACITY), size(0) {
        roster = new S[capacity];
    }

    void Roster::delRoster() {
        delete[] roster;
    }
    //precondition: roster isnt full
	//postcondition: program doubles the capacity of roster if roster is full
    void Roster::insert(S& rec) {
        if (size >= capacity) {
            resize(); // Allocate more memory if capacity is exhausted
        }
        if(rec.getFirstName() == ""){
			std::cout<<"Invalid or defualt First name"<<std::endl;
			return;
		}

		if(rec.getLastName() == ""){
			std::cout<<"Invalid or defualt Last name"<<std::endl;
			return;
		}

		if(rec.getID() == 0){
			std::cout<<"Invalid or defualt ID"<<std::endl;
			return;
		}
        // Add the student to the array and increment the size
        // Check if student with same ID already exists
		for (int i = 0; i < size; ++i) {
			if (roster[i].getID() == rec.getID()) {
				std::cout << "Student with ID " << rec.getID() << " already exists in the roster." << std::endl;
				return;
			}
		}
        roster[size++] = rec;
    }

    void Roster::erase(Student::ID_t id) {
        bool found = false;
        if (size == 0) {
            std::cout << "No students exist" << std::endl;
        }
        for (int i = 0; i < size; ++i) {
            if (roster[i].getID() == id) {
                roster[i] = roster[size - 1];
                size--;
                found = true;
            }
        }
        if (!found) {
            std::cout << "Student not found. Please try with a valid id " << std::endl;
        }
    }

    Roster::S* Roster::begin() {
        index = 0;
        return roster;
    }

    Roster::S* Roster::end() {
        return roster + size;
    }

    Roster::S* Roster::next(S* &current) {
        if(index < size - 1){
            index++;
            return &roster[index];
        }else{
            resize();
            index++;
            return &roster[index];
        }  
    }

    //doubles the size of roster if roster is full.
    void Roster::resize() {
        
        capacity *= 2; // Double the capacity
        S* newRoster = new S[capacity];
        // Copy existing data to the new array
        for (int i = 0; i < size; ++i) {
            newRoster[i] = roster[i];
        }
        delete[] roster; // Deallocate old memory
        roster = newRoster; // Update pointer to new array
    }
}
