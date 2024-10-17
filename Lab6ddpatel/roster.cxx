/*
 *  Dhruv Patel, Lab 6
 */
#include "roster.h"

namespace csen79 {
    Student::Student(Student::ID_t n, std::string fn, std::string ln){
        this->ID = n;
        this->firstName = fn;
        this->lastName = ln;
    }

    std::ostream& operator<<(std::ostream& os, const Student &t) {
        os << "ID: " << t.ID << ", First Name: " << t.firstName << ", Last Name: " << t.lastName;
        return os;
    }

    void Roster::insert(Student &rec) {
        Node* newNode = new Node(rec);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void Roster::erase(Student::ID_t id) {
        Node *current = head;
        Node *prev = nullptr;
        while (current != nullptr) {
            if (current->data.getID() == id) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                size--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    Node* Roster::begin(void) {
        return head;
    }

    Node* Roster::next(void) {
        static Node* current = nullptr;
        if (current == nullptr) current = head;
        else current = current->next;

        return current;
    }

    Node* Roster::end(void) {
        return tail;
    }
}
