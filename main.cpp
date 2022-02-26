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
    std::cout << "== operator" << std::endl;
    if(test_sport == test_sport2)
        std::cout << "== operator working" << std::endl;
    std::cout << std::endl;
    std::cout << "Hockey Class" << std::endl;
    Hockey test_hockey;
    std::cout << test_hockey << std::endl;
    std::cout << "Hocky Constructor w Args" << std::endl;
    Hockey test_hockey2(5, 8, 10, 15, 5, 10);
    std::cout << test_hockey2 << std::endl;
    test_hockey2.add_game(1,2,8,1);
    std::cout << test_hockey2 << std::endl;
    std::cout << "Hockey Compare Function" << std::endl;
    if(test_hockey2.compare(test_hockey) == false)
        std::cout << "Compare Success" << std::endl;
    Hockey test_hockey3;
    if(test_hockey3.compare(test_hockey) == true)
        std::cout << "Compare Success" << std::endl;
    if(test_hockey3 != test_hockey2)
        std::cout << "!= Working" << std::endl;
    std::cout << std::endl;
    std::cout << "Basketball Class" << std::endl;
    Basketball test_basketball;
    std::cout << test_basketball << std::endl;
    Basketball test_basketball2;
    std::cout << "!= Operator" << std::endl;
    if(test_basketball != test_basketball2 == true)
        std::cout << "!= Operator Success" << std::endl;
    std::cout << "Compare Function" << std::endl;
    if(test_basketball.compare(test_basketball2))
        std::cout << "Compare Function Sucess" << std::endl;
    std::cout << "Basketball Constructor w Args" << std::endl;
    Basketball test_basketball3(225, 40, 50, 2, 2, 0);
    std::cout << test_basketball3 << std::endl;
    test_basketball3.add_game(120, 50, 30, 1);
    std::cout << "Basketball Add Game" << std::endl;
    std::cout << test_basketball3 << std::endl;
    return 0;
}