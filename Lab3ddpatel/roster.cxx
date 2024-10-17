/*
 * Dhruv Patel, Lab 3
 */
#include <string>
#include <iostream>
#include <stdexcept>
#include "roster.h"

namespace csen79 {
	static int index = 0;
	Student::Student(Student::ID_t n, std::string fn, std::string ln){
		this->ID = n;
		this->firstName = fn;
		this->lastName = ln;
	}

	std::ostream& operator<<(std::ostream& os, const Student &t) {
		os << "ID: " << t.ID << ", First Name: " << t.firstName << ", Last Name: " << t.lastName;
		return os;
	}

	//precondition: roster isnt full
	//postcondition: program exits out of current instance if roster is full
	void Roster::insert(S &rec) {
		if (size >= CAPACITY) {
            // Roster is full, cannot insert more students
            std::cout << "Roster is full" << std::endl;
            return;
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

		
		// Check if student with same ID already exists
		for (int i = 0; i < size; ++i) {
			if (students[i].getID() == rec.getID()) {
				std::cout << "Student with ID " << rec.getID() << " already exists in the roster." << std::endl;
				return;
			}
		}
		students[size++] = rec; // Add the student to the array and increment the size
		return;
	}

	//precondition: roster isnt empty
	//postcondition: program exits out of current instance if roster is empty
	void Roster::erase(Student::ID_t id) {
		bool found = false;
		if(size == 0){
			std::cout << "No students exist "<< std::endl;
		}
		for(int i = 0 ; i<size ; ++i){
			if(students[i].getID()==id){
				students[i] = students[size - 1];
				size--;
				found = true;
			}
  	  	}
		if(!found){
			std::cout<< "Student not found. Please try with a valid id "<<std::endl;
		}
    }


	
	Roster::S* Roster::begin(void) {
		index = 0;
		return students;
	}

	Roster::S* Roster::end(void) {
		return &students[size-1];
	}

	
	Roster::S* Roster::next(void) {
		 
        if (index < size - 1) {
			index++;
            return &students[index]; 
        } else {
            return nullptr; // Reached the end of the roster
        }
	}
}
