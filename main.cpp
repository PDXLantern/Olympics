#include "main.h"
int main(){
    std::cout << "Sport Class" << std::endl;
    Sport test_sport;
    std::cout << test_sport << std::endl;
    std::cout << "Copy Constructor" << std::endl;
    Sport test_sport2(test_sport);
    std::cout << test_sport2 << std::endl;
    std::cout << "Constructor w Args" << std::endl;
    Sport test_sport3(2, 1, 1);
    std::cout << test_sport3 << std::endl;
    return 0;
}