
#ifndef ITEM_CPP
#define ITEM_CPP

#include "node.h"

namespace coen79_lab7
{
    node::node(const std::string& itemName, const float& newPrice, node* nextNode)
        : name(itemName), price(newPrice), link(nextNode) {}

    // Modification member functions
    void node::setName(const std::string& product_name) {
        name = product_name;
    }

    void node::setPrice(const float& newPrice) {
        price = newPrice;
    }

    void node::setLink(node* newLink) {
        link = newLink;
    }

    // Constant member functions
    const node* node::getLink() const {
        return link;
    }

    node* node::getLink() {
        return link;
    }

    std::string node::getName() const {
        return name;
    }

    float node::getPrice() const {
        return price;
    }

    void list_clear(node*& head_ptr) {
        while (head_ptr != NULL) {
            node* temp = head_ptr;
            head_ptr = head_ptr->getLink();
            delete temp;
        }
    }

    void list_init(node*& head_ptr, node*& tail_ptr, const std::string& newName, const float& newPrice) {
        head_ptr = new node(newName, newPrice);
        tail_ptr = head_ptr;
    }

    void list_head_insert(node*& head_ptr, const std::string& newName, const float& newPrice) {
        head_ptr = new node(newName, newPrice, head_ptr);
    }

    void list_tail_insert(node*& tail_ptr, const std::string& newName, const float& newPrice) {
        if (tail_ptr != NULL) {
            tail_ptr->setLink(new node(newName, newPrice));
            tail_ptr = tail_ptr->getLink();
        }
    }

    void list_head_remove(node*& head_ptr) {
        if (head_ptr != NULL) {
            node* temp = head_ptr;
            head_ptr = head_ptr->getLink();
            delete temp;
        }
    }

    void list_print(node* head_ptr) {
        for (node* cur = head_ptr; cur != NULL; cur = cur->getLink()) {
            std::cout << "- " << cur->getName() << ", where the price is $" << cur->getPrice() << std::endl;
        }
    }

    bool list_contains_item(node* head_ptr, const std::string& target) {
        return list_search(head_ptr, target) != NULL;
    }

    node* list_search(node* head_ptr, const std::string& target) {
        for (node* cursor = head_ptr; cursor != NULL; cursor = cursor->getLink()) {
            if (cursor->getName() == target) {
                return cursor;
            }
        }
        return NULL;
    }

    const node* list_search(const node* head_ptr, const std::string& target) {
        for (const node* cursor = head_ptr; cursor != NULL; cursor = cursor->getLink()) {
            if (cursor->getName() == target) {
                return cursor;
            }
        }
        return NULL;
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) {
        head_ptr = NULL;
        tail_ptr = NULL;
        
        if (source_ptr == NULL) {
            return;
        }
        
        head_ptr = new node(source_ptr->getName(), source_ptr->getPrice());
        tail_ptr = head_ptr;

        source_ptr = source_ptr->getLink();
        while (source_ptr != NULL) {
            tail_ptr->setLink(new node(source_ptr->getName(), source_ptr->getPrice()));
            tail_ptr = tail_ptr->getLink();
            source_ptr = source_ptr->getLink();
        }
    }

    
}

#endif
