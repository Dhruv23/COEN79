#include "mystring.h"

using namespace coen79_lab5;
namespace coen79_lab5{
    string::string(const char str[]) {

        current_length = strlen(str);
        allocated = current_length + 1; // Plus one for null

        characters = new char[allocated];
        strncpy(characters, str, allocated); 

        characters[allocated - 1] = '\0'; //null terminate

        // If str is longer than allocated, do it manually
        if (current_length >= allocated - 1) {
            characters[allocated - 1] = '\0';
        }
    }

    string::string(char c) {
        current_length = 1;
        allocated = 2; 
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0'; // Null terminator
    }

    string::string(const string& source) {
        current_length = source.current_length;
        allocated = source.allocated;
        characters = new char[allocated];
        strncpy(characters, source.characters, allocated);
    }

    string::~string(){
        current_length = 0;
        allocated = 0;
        delete characters;
    }
    void string::insert(const string& source, unsigned int position) {
        // Check if position is valid
        if (position > current_length) {
            return; // Invalid position, do nothing
        }

        // Calculate the new length and allocate memory for the updated string
        size_t new_length = current_length + source.current_length;
        char *new_characters = new char[new_length + 1]; // Plus one for the null terminator

        // Copy the characters before the insertion point
        strncpy(new_characters, characters, position);

        // Copy the characters from the source string
        strncpy(new_characters + position, source.characters, source.current_length);

        // Copy the characters after the insertion point
        strncpy(new_characters + position + source.current_length, characters + position, current_length - position);

        // Null-terminate the new string
        new_characters[new_length] = '\0';

        // Deallocate the old memory
        delete[] characters;

        // Update the pointers and current length
        characters = new_characters;
        current_length = new_length;
        allocated = new_length + 1; // Plus one for the null terminator
    }

    void string::dlt(unsigned int position, unsigned int num) {
        // Check if position and num are valid
        if (position + num > current_length) {
            return; // Invalid position or num, do nothing
        }

        // Calculate the new length and allocate memory for the updated string
        size_t new_length = current_length - num;
        char *new_characters = new char[new_length + 1]; // Plus one for the null terminator

        // Copy the characters before the deleted section
        strncpy(new_characters, characters, position);

        // Copy the characters after the deleted section
        strncpy(new_characters + position, characters + position + num, current_length - position - num);

        // Null-terminate the new string
        new_characters[new_length] = '\0';

        // Deallocate the old memory
        delete[] characters;

        // Update the pointers and current length
        characters = new_characters;
        current_length = new_length;
        allocated = new_length + 1; // Plus one for the null terminator
    }

    void string::replace(char c, unsigned int position) {
        // Check if position is valid
        if (position >= current_length) {
            return; // Invalid position, do nothing
        }

        // Replace the character at the given position
        characters[position] = c;
    }

    void string::replace(const string& source, unsigned int position) {
        // Check if position is valid
        if (position + source.current_length > current_length) {
            return; // Invalid position, do nothing
        }
        // Calculate the new length and allocate memory for the updated string
        size_t new_length = current_length - source.current_length + source.current_length;
        char *new_characters = new char[new_length + 1]; // Plus one for the null terminator

        // Copy the characters before the replacement
        strncpy(new_characters, characters, position);

        // Copy the characters from the source string
        strncpy(new_characters + position, source.characters, source.current_length);

        // Copy the characters after the replacement
        strncpy(new_characters + position + source.current_length, characters + position + source.current_length, current_length - position - source.current_length);

        // Null-terminate the new string
        new_characters[new_length] = '\0';

        // Deallocate the old memory
        delete[] characters;

        // Update the pointers and current length
        characters = new_characters;
        current_length = new_length;
        allocated = new_length + 1; // Plus one for the null terminator
    }

    void string::reserve(size_t n) {
        if (n > allocated) {
            char* new_storage = new char[n];
            std::memcpy(new_storage, characters, current_length);
            delete[] characters;
            characters = new_storage;
            allocated += n;
        }
    }
    string& string::operator=(const string& source) {
            
            if (this == &source) {
                return *this;  // Return the same object if self-assignment
            }

            
            if (source.current_length > allocated) {
                
                char* new_characters = new char[source.current_length + 1]; 
                delete[] characters;
                characters = new_characters;
                allocated = source.current_length + 1;  // Update the allocated size to the new size
            }

            std::memcpy(characters, source.characters, source.current_length);
            
            characters[source.current_length] = '\0';

            current_length = source.current_length;

            return *this;
        }


    void string::operator+=(const string& addend) {
        // Make a copy of the current string
        char *temp = new char[current_length + 1];
        strncpy(temp, characters, current_length + 1);

        // Deallocate the current characters array
        delete[] characters;

        // Calculate the new length and allocate memory for the concatenated string
        current_length += addend.current_length;
        allocated = current_length + 1;
        characters = new char[allocated];

        // Copy the original string back
        strncpy(characters, temp, current_length - addend.current_length);

        // Concatenate the addend to the end of the string
        strncat(characters, addend.characters, addend.current_length);

        // Null terminate the string
        characters[current_length] = '\0';

        // Deallocate the temporary array
        delete[] temp;
}   


    void string::operator+=(const char addend[]) {
        size_t addend_length = std::strlen(addend);
        size_t new_length = current_length + addend_length;
        if (new_length >= allocated) {
            reserve(new_length + 1);  
        }
        std::memcpy(characters + current_length, addend, addend_length);
        current_length = new_length;
        characters[current_length] = '\0';  
    }

    // Append a single character
    void string::operator+=(char addend) {
        if (current_length + 1 >= allocated) {
            reserve(current_length + 2);  
        }
        characters[current_length] = addend;
        current_length++;
        characters[current_length] = '\0';  
    }

    char string::operator[](size_t position) const {
        // Check if position is valid
        if (position >= current_length) {
            return '\0'; // Invalid position, return null character
        }
        return characters[position];
    }

    int string::search(char c) const {
        for (size_t i = 0; i < current_length; ++i) {
            if (characters[i] == c) {
                return static_cast<int>(i); // Found the character, return its index
            }
        }
        return -1; // Character not found
    }

    int string::search(const string& substring) const {
        // Iterate through the characters in the string
        for (size_t i = 0; i <= current_length - substring.current_length; ++i) {
            // Check if the substring matches the characters starting at index i
            if (strncmp(characters + i, substring.characters, substring.current_length) == 0) {
                return static_cast<int>(i); // Found the substring, return its index
            }
        }
        return -1; // Substring not found
    }


    unsigned int string::count(char c) const {
        unsigned int counter = 0;
        for (size_t i = 0; i < current_length; ++i) {
            if (characters[i] == c) {
                counter++; // Increment the counter if the character matches c
            }
        }
        return counter; // Return the total count
    }

    bool operator ==(const string& s1, const string& s2) {
        return std::strncmp(s1.characters, s2.characters, std::max(s1.current_length, s2.current_length)) == 0;
    }

    // Check if two strings are not the same
    bool operator !=(const string& s1, const string& s2) {
        return std::strncmp(s1.characters, s2.characters, std::max(s1.current_length, s2.current_length)) != 0;
    }

    // Check if string s1 has higher ASCII values
    bool operator >(const string& s1, const string& s2) {
        return std::strncmp(s1.characters, s2.characters, std::max(s1.current_length, s2.current_length)) > 0;
    }

    // Check if string s2 has higher ASCII values
    bool operator <(const string& s1, const string& s2) {
        return std::strncmp(s1.characters, s2.characters, std::max(s1.current_length, s2.current_length)) < 0;
    }

    // Check if s1 is equal to or larger than s2
    bool operator >=(const string& s1, const string& s2) {
        return (s1 > s2) || (s1 == s2);
    }

    // Check if s1 is equal to or smaller than s2
    bool operator <=(const string& s1, const string& s2) {
        return (s1 < s2) || (s1 == s2);
    }
    std::ostream& operator <<(std::ostream& outs, const string& source) {
        outs << source.characters;                                      // Put the sequence source.characters into outs
        return outs;                                                    // return ostream object
    }
    string operator+(const string& s1, const string& s2) {
        string temp;                                                    // Create temporary string
        temp.reserve(s1.length()+s2.length()+1);                        // reserve/allocate s1+s2+1 size
        temp += s1;                                                     // call overloaded += operator
        temp += s2;                                                     // call overloaded += operator
        return temp;                                                    // return our temporary string
    }

    // Returns the concatenation of string s1 and char array addend[]
    string operator +(const string& s1, const char addend[ ]) {
        string temp;                                                    // Same code as above
        temp.reserve(s1.length()+strlen(addend)+1);                     // use strlen on char array
        temp += s1;                                                     // call overloaded += operator
        temp += addend;                                                 // call overloaded += operator
        return temp;                                                    // return our temporary string
    }
}