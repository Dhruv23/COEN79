#include "mystring.h"
using namespace coen79_lab5;
int main(void) {
    string s1 = " ";
    string s2 = "Hello World!";
    string s3 = "Hello World!";
    std::cout<<s1<<" "<<s2<<" "<<s3<<std::endl;
    s1+=s2;
    std::cout<<s1<<" "<<s2<<" "<<s3<<std::endl;
    string s4 = s2;
    std::cout<<s1<<" "<<s4<<" "<<s3<<std::endl;
    s4.insert(s2, 0);
    std::cout<<s4<<std::endl;
    s4.dlt(0, 12);
    std::cout<<s4<<std::endl;
    s4.replace('H', 2);
    std::cout<<s4<<std::endl;
    int lengths4 = s4.length();
    std::cout<<lengths4<<std::endl;
    char s4char = s4[0];
    std::cout<<s4char<<std::endl;
    int searchs4 = s4.search('H');
    std::cout<<searchs4<<std::endl;
    int searchs42 = s4.search("He");
    std::cout<<searchs42<<std::endl;
    int counts4 = s4.count('l'); //HeHlo World;
    std::cout<<counts4<<std::endl;
    bool check;
    std::cout<<(s2 == s3)<<std::endl; //1 if true
    std::cout<<(s2 != s3)<<std::endl; //1 if true
    std::cout<<(s2 > s3)<<std::endl; //1 if true
    std::cout<<(s2 >= s3)<<std::endl; //1 if true
    std::cout<<(s2 < s3)<<std::endl; //1 if true
    std::cout<<(s2 <= s3)<<std::endl; //1 if true
    string s5 = s1 + s2;
    std::cout<<s5<<std::endl;
    s5 = s5 + 'c';
    std::cout<<s5<<std::endl;
    std::cout<<"Enter a character: "<<std::endl;
    
}