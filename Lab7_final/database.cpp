//FILE: database.cpp
//CLASS implemented: database (see database.h for documentation)

//INVARIANT for the database ADT:
//  1. The items in the database are stored in a dynamic array, where each entry of the array includes
//     a company name, a pointer to the head of the linked list of products, and a
//     a pointer to the tail of the linked list of products
//  2. The number of slots in the array of companies is stored in member varibale aloc_slots
//  3. The number of used slots of the array of companies is stored in member varibale used_slots


#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "database.h"


//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif



namespace coen79_lab7 {
    //Constructor
    database::database(const size_type& initial_capacity) {
        aloc_slots = initial_capacity;
        used_slots = 0;
        company_array = new company[aloc_slots];
    }

    //Copy Constructor
    database::database(const database &src) {
        company_array = NULL;
        *this = src; //Use the assignment operator
    }

    //Destructor
    database::~database() {
        delete[] company_array;
    }

    //Assignment Operator
    database& database::operator=(const database &rhs) {
        if (this == &rhs)
            return *this;

        delete[] company_array;

        aloc_slots = rhs.aloc_slots;
        used_slots = rhs.used_slots;
        company_array = new company[aloc_slots];
        for (size_type i = 0; i < used_slots; ++i) {
            company_array[i] = rhs.company_array[i];
        }

        return *this;
    }

    void database::reserve(size_type new_capacity) {
        if (new_capacity == aloc_slots) {
            return;
        }

        if (new_capacity < used_slots) {
            new_capacity = used_slots;
        }

        company *new_array = new company[new_capacity];
        for (size_type i = 0; i < used_slots; ++i) {
            new_array[i] = company_array[i];
        }

        delete[] company_array;
        company_array = new_array;
        aloc_slots = new_capacity;
    }

    bool database::insert_company(const std::string& company_name) {
        assert(company_name.length() > 0);

        if (search_company(company_name) != COMPANY_NOT_FOUND) {
            return false;
        }

        if (used_slots == aloc_slots) {
            reserve(aloc_slots + 1);
        }

        company_array[used_slots] = company(company_name);
        ++used_slots;
        return true;
    }

    bool database::erase_company(const std::string& company_name) {
        size_type index = search_company(company_name);

        if (index == COMPANY_NOT_FOUND) {
            return false;
        }

        for (size_type i = index; i < used_slots - 1; ++i) {
            company_array[i] = company_array[i + 1];
        }

        --used_slots;
        return true;
    }

    bool database::insert_item(const std::string &company_name, const std::string& product_name, const float& price) {
        assert(company_name.length() > 0 && product_name.length() > 0);

        size_type index = search_company(company_name);

        if (index == COMPANY_NOT_FOUND) {
            return false;
        }

        return company_array[index].insert(product_name, price);
    }

    bool database::erase_item(const std::string &company_name, const std::string& product_name) {
        assert(company_name.length() > 0 && product_name.length() > 0);

        size_type index = search_company(company_name);

        if (index == COMPANY_NOT_FOUND) {
            return false;
        }

        return company_array[index].erase(product_name);
    }

    void database::print_companies() {
        std::cout << "Company List" << std::endl;
        for (size_type i = 0; i < used_slots; ++i) {
            std::cout << "- " << company_array[i].get_name() << std::endl;
        }
    }

    bool database::print_items_by_company(const std::string& company_name) {
        assert(company_name.length() > 0);

        size_type index = search_company(company_name);

        if (index == COMPANY_NOT_FOUND) {
            return false;
        }

        std::cout << "Printing the products of " << company_name << ":" << std::endl;
        company_array[index].print_items();
        std::cout << std::endl;

        return true;
    }

    database::size_type database::search_company(const std::string& company_name) {
        assert(company_name.length() > 0);

        for (size_type i = 0; i < used_slots; ++i) {
            if (company_array[i].get_name() == company_name) {
                return i;
            }
        }

        return COMPANY_NOT_FOUND;
    }
}


#endif
