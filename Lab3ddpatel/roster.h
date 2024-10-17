/*
 * CSEN 79 Lab Sample Code
 */
#ifndef ROSTER_H
#define ROSTER_H

// Class declaration for roster
namespace csen79 {
	// base data for the roster
	class Student {
	public:
		using ID_t = unsigned int;	// really should be a 7-digit unsigned int
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
	
	class Roster {
	public:
		using S = Student;
		static const int CAPACITY=30;

		void insert(S &);
		void erase(Student::ID_t);
		Roster() : size(0) {}
		S* begin(void);
		S* end(void);
		S* next(void);
		int getSize() const { return size; }
	private:
		S students[CAPACITY]; // Array of students with size CAPACITY
        int size; // Current size of the roster
	};
}

#endif // ROSTER_H
