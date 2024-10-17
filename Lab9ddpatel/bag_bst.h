// FILE: bag_bst.h (part of the namespace coen79_lab9)
// Behnam Dezfouli, COEN, SCU
//
// TEMPLATE CLASS PROVIDED: bag<Item>
//     (a container template class for a collection of items)
//
// TYPEDEFS for the bag<Item> class:
//   bag<Item>::value_type
//     bag<Item>::value_type is the data type of the items in the bag. It may
//     be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
//   bag<Item>::size_type
//     bag<Item>::size_type is the data type of any variable that keeps track
//     of how many items are in a bag.
//
// CONSTRUCTOR for the bag<Item> class:
//   bag( )
//     Postcondition: The bag is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the bag<Item> class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the bag. The
//     return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the bag, then one copy of target has been
//     removed from the bag; otherwise the bag is unchanged. A true return value
//     indicates that one copy was removed; false indicates that nothing was
//     removed.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//   void operator +=(const bag& addend)
//     Postcondition: Each item in addend has been added to this bag.
//
// CONSTANT MEMBER FUNCTIONS for the bag<Item> class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the bag.
//
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bag.
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//     Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag: 
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc: The constructors, insert, operator +=, operator +, and
//   the assignment operator.

#ifndef COEN79_BST_BAG
#define COEN79_BST_BAG

#include <cstdlib>     // Provides NULL and size_t
#include "bintree.h"   // Provides binary_tree_node and related functions

namespace coen79_lab9
{
    template <class Item>
    class bag
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;
        
        // CONSTRUCTORS and DESTRUCTOR
        bag( ) { root_ptr = NULL; }
        bag(const bag& source);
        ~bag( );
        
        // MODIFICATION functions
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);
        
        // CONSTANT functions
        size_type size( ) const;
        size_type count(const Item& target) const;
        void debug( ) const { print(root_ptr, 0); }
        
    private:
        binary_tree_node<Item> *root_ptr; // Root pointer of binary search tree
        void insert_all(binary_tree_node<Item>* addroot_ptr);
    };
    
    // NONMEMBER functions for the bag<Item> template class
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);
}



// -----------------------------
// *** IMPLEMENTATION ***
// -----------------------------

namespace coen79_lab9
{
    
#pragma mark - Toolkit Function Implementation
    
    
    // ---------------------------------
    // Toolkit functions for implementing bag class using BST
    // Note: These are not functions of the bag class
    // ---------------------------------
    
    template <class Item>
    void bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed) {
        binary_tree_node<Item> *oldroot_ptr;
        
        assert(root_ptr != NULL);
        
        if (root_ptr->right() != NULL)
            bst_remove_max(root_ptr->right(), removed);
        else {
            removed = root_ptr->data();
            oldroot_ptr = root_ptr;
            root_ptr = root_ptr->left();
            delete oldroot_ptr;
        }
    }

    
    
    template <class Item>
    bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target) {
        binary_tree_node<Item> *oldroot_ptr;
        
        if (root_ptr == NULL) {
            return false;
        }
        
        if (target < root_ptr->data()) {
            return bst_remove(root_ptr->left(), target);
        }
        
        if (target > root_ptr->data()) {
            return bst_remove(root_ptr->right(), target);
        }
        
        // Target found
        if (root_ptr->left() == NULL) {
            oldroot_ptr = root_ptr;
            root_ptr = root_ptr->right();
            delete oldroot_ptr;
            return true;
        } else {
            Item max_item;
            bst_remove_max(root_ptr->left(), max_item);
            root_ptr->set_data(max_item);
            return true;
        }
    }

    
    
    template <class Item>
    typename bag<Item>::size_type bst_remove_all(binary_tree_node<Item>*& root_ptr, const Item& target) {
        binary_tree_node<Item> *oldroot_ptr;
        
        if (root_ptr == NULL) {
            return 0;
        }
        
        if (target < root_ptr->data()) {
            return bst_remove_all(root_ptr->left(), target);
        }
        
        if (target > root_ptr->data()) {
            return bst_remove_all(root_ptr->right(), target);
        }
        
        if (root_ptr->left() == NULL) {
            oldroot_ptr = root_ptr;
            root_ptr = root_ptr->right();
            delete oldroot_ptr;
            return 1 + bst_remove_all(root_ptr, target);
        } else {
            Item max_item;
            bst_remove_max(root_ptr->left(), max_item);
            root_ptr->set_data(max_item);
            return 1 + bst_remove_all(root_ptr, target);
        }
    }

    
    
#pragma mark - Member Function Implementation

    
    // ---------------------------------
    // Member functions of the bag class
    // ---------------------------------

    
    // NOTE: The copy constructor needs to make a new copy of the source’s
    // tree, and point root_ptr to the root of this copy
    // Use the tree_copy function to do the copying
    template <class Item>
    bag<Item>::bag(const bag<Item>& source) {
        root_ptr = tree_copy(source.root_ptr);
    }

    
    

    template <class Item>
    bag<Item>::~bag( )
    // Header file used: bintree.h
    {
        tree_clear(root_ptr);
    }
    
    
    template <class Item>
    typename bag<Item>::size_type bag<Item>::size( ) const
    // Header file used: bintree.h
    {
        return tree_size(root_ptr);
    }
    
    
    // Insert
    // Case 1: First handle this special case: When the first entry is inserted,
    //         simply call root_ptr = new binary_tree_node<Item>(entry)
    // Case 2: There are already some other entries in the tree:
    //    • We pretend to search for the exact entry that we are trying to insert
    //    • We stop the search just before the cursor falls off the bottom of the tree,
    //      and we insert the new entry at the spot where the cursor was about to fall off
    template <class Item>
    void bag<Item>::insert(const Item& entry) {
        binary_tree_node<Item> *cursor = root_ptr;
        bool done = false;
        
        if (root_ptr == NULL) {
            root_ptr = new binary_tree_node<Item>(entry);
            return;
        }
        
        do {
            if (cursor->data() >= entry) {
                if (cursor->left() == NULL) {
                    cursor->set_left(new binary_tree_node<Item>(entry));
                    done = true;
                } else {
                    cursor = cursor->left();
                }
            } else {
                if (cursor->right() == NULL) {
                    cursor->set_right(new binary_tree_node<Item>(entry));
                    done = true;
                } else {
                    cursor = cursor->right();
                }
            }
        } while (!done);
    }

    
    template <class Item>
    typename bag<Item>::size_type bag<Item>::count(const Item& target) const {
        size_type answer = 0;
        binary_tree_node<Item> *cursor = root_ptr;
        
        while (cursor != NULL) {
            if (cursor->data() < target) {
                cursor = cursor->right();
            } else {
                if (cursor->data() == target) {
                    ++answer;
                }
                cursor = cursor->left();
            }
        }
        return answer;
    }

    
    
    template <class Item>
    typename bag<Item>::size_type bag<Item>::erase(const Item& target)
    {
        return bst_remove_all(root_ptr, target);
    }
    
    
    template <class Item>
    bool bag<Item>::erase_one(const Item& target)
    {
        return bst_remove(root_ptr, target);
    }
    
    
    // The assignment operator:
    // 1. First check if it is a self-assignment by comparing (this == &source): If yes, then return
    // 2. If there is no self-assignment, then before we copy the source tree we must release all
    //    memory used by the nodes of the current tree
    //    Use tree_clear to release memory
    template <class Item>
    void bag<Item>::operator =(const bag<Item>& source) {
        if (this == &source) {
            return;
        }
        tree_clear(root_ptr);
        root_ptr = tree_copy(source.root_ptr);
    }

    
    
    template <class Item>
    void bag<Item>::operator +=(const bag<Item>& addend) {
        if (this == &addend) {
            bag<Item> copy = addend;
            insert_all(copy.root_ptr);
        } else {
            insert_all(addend.root_ptr);
        }
    }

    
    
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2) {
        bag<Item> result = b1;
        result += b2;
        return result;
    }

    
    
    template <class Item>
    void bag<Item>::insert_all(binary_tree_node<Item>* addroot_ptr) {
        if (addroot_ptr != NULL) {
            insert(addroot_ptr->data());
            insert_all(addroot_ptr->left());
            insert_all(addroot_ptr->right());
        }
    }


}

#endif
