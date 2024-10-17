#include <iostream>
#include "deque.h"

using namespace coen79_lab8;

template <class Item>
void printDeque(deque<Item>& dq) {
    typename deque<Item>::iterator it;
    for (it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testConstructor() {
    std::cout << "constructor test" << std::endl;
    deque<int> dq;
}

void testPushBackAndBack() {
    std::cout << "push_back()" << std::endl;
    deque<int> dq;
    for (int i = 0; i < 100; ++i) {
        dq.push_back(i);
    }
    printDeque(dq);
}

void testPushFrontAndFront() {
    std::cout << "push_front()" << std::endl;
    deque<int> dq;
    for (int i = 0; i < 100; ++i) {
        dq.push_front(i);
    }
    printDeque(dq);
}

void testIterator() {
    std::cout << "iterator" << std::endl;
    deque<int> dq;
    for (int i = 0; i < 100; ++i) {
        dq.push_back(i);
    }
    typename deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testPopFront() {
    std::cout << "po fornt" << std::endl;
    deque<int> dq;
    for (int i = 0; i < 100; ++i) {
        dq.push_back(i);
    }
    dq.pop_front();
    std::cout << "Front->" << dq.front() << std::endl;
    std::cout << "Back->" << dq.back() << std::endl;
}

void testPopBack() {
    std::cout << "back pop" << std::endl;
    deque<int> dq;
    for (int i = 0; i < 100; ++i) {
        dq.push_back(i);
    }
    dq.pop_back();
    std::cout << "Front -> " << dq.front() << std::endl;
    std::cout << "Back -> " << dq.back() << std::endl;
}

void testIteratorAfterPopBack() {
    std::cout << "iterator after popping from teh bakc" << std::endl;
    deque<int> dq;
    for (int i = 0; i < 100; ++i) {
        dq.push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        dq.pop_back();
    }
    printDeque(dq);
}

void testAssignmentOperator() {
    std::cout << "Value Semantinc - > assignment op" << std::endl;
    deque<int> dq1;
    for (int i = 1; i <= 6; ++i) {
        dq1.push_back(i);
    }
    deque<int> dq2 = dq1;
    printDeque(dq2);
}

void testCopyConstructor() {
    std::cout << "Value Semantic -> copy constructor" << std::endl;
    deque<int> dq1;
    for (int i = 1; i <= 6; ++i) {
        dq1.push_back(i);
    }
    deque<int> dq2(dq1);
    printDeque(dq2);
}

void testIteratorWithValue() {
    std::cout << "Iterator test with value" << std::endl;
    deque<int> dq;
    for (int i = 0; i < 6; ++i) {
        dq.push_back(950);
    }
    printDeque(dq);
}

int main() {
    testConstructor();
    testPushBackAndBack();
    testPushFrontAndFront();
    testIterator();
    testPopFront();
    testPopBack();
    std::cout << std::endl <<std::endl << std::endl;
    std::cout<< " Finsihed teesting basic functions " << std::endl;
    testIteratorAfterPopBack();
    testAssignmentOperator();
    testCopyConstructor();
    testIteratorWithValue();
    std::cout << std::endl<<std::endl;
    std::cout << "EVERTYTININF  DONE " << std::endl;

    return 0;
}
