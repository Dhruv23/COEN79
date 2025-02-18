// FILE: company.cpp
// CLASS IMPLEMENTED: company (see company.h for documentation)

#include <cassert>
#include "company.h"
#include "node.h"

//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace coen79_lab7
{
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    
    company::company(const std::string& company_name) {
        assert(company_name.length() > 0);
        this->company_name = company_name;
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    
    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);

        company_name = src.company_name;
       list_copy(src.head_ptr, head_ptr, tail_ptr);
    }

    company& company::operator= (const company &src) {
        Debug("Company assignment operator..." << std::endl);
        
        if (this == &src)
            return *this;

        list_clear(head_ptr);

        company_name = src.company_name;
        list_copy(src.head_ptr, head_ptr, tail_ptr);

        return *this;
    }
    
    company::~company() {
        list_clear(head_ptr);
    }
    
    std::string company::get_name() const {
        return company_name;
    }
    
    const node *company::get_head() const {
        return head_ptr;
    }
    
    const node *company::get_tail() const {
        return tail_ptr;
    }
    
    node* company::get_head() {
        return head_ptr;
    }
    
    node* company::get_tail() {
        return tail_ptr;
    }
    
    void company::print_items() {
        list_print(head_ptr);
    }
    
    bool company::insert(const std::string& product_name, const float& price) {
        assert(product_name.length() > 0);

        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }
        
        if (head_ptr == NULL) {
            list_init(head_ptr, tail_ptr, product_name, price);
        } else {
            list_tail_insert(tail_ptr, product_name, price);
        }
        
        return true;
    }

    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);

        node *prev = NULL;
        node *curr = head_ptr;

        while (curr != NULL) {
            if (curr->getName() == product_name) {
                if (prev == NULL) {
                    head_ptr = curr->getLink();
                } else {
                    prev->setLink(curr->getLink());
                }

                if (curr == tail_ptr) {
                    tail_ptr = prev;
                }

                delete curr;
                return true;
            }

            prev = curr;
            curr = curr->getLink();
        }

        return false;
    }
}
