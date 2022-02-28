#include "main.h"
int main(){
    std::cout << "Sport Class" << std::endl;
    Basketball test_sport (400, 340, 123, 4, 3, 1);
    std::cout << test_sport << std::endl;

    std::cout << "Athlete Class" << std::endl;
    char * test_char = new char [strlen("USA National Team")+1];
    strcpy(test_char,"USA National Team");
    std::string * test_string = new std::string("United States of America");
    Athlete test_athlete(test_char, test_string, 5);
    std::cout << test_athlete << std::endl;

    std::cout << "Athlete Class Insert" << std::endl;
    test_athlete.insert(test_sport);
    std::cout << test_athlete << std::endl;

    std::cout << "Node Class" << std::endl;
    Node test_node;
    std::cout << test_node << std::endl;
    std::cout << "Node Class Insert" << std::endl;
    test_node.insert(test_athlete);
    std::cout << test_node << std::endl;

    std::cout << "Sport Class 2" << std::endl;
    Basketball test_sport2 (500, 250, 32, 10, 1, 9);
    std::cout << test_sport2 << std::endl;

    std::cout << "Athlete Class 2" << std::endl;
    char * test_char2 = new char [strlen("USA National Team")+1];
    strcpy(test_char2,"USA National Team");
    std::string * test_string2 = new std::string("United States of America");
    Athlete test_athlete2(test_char2, test_string2, 5);
    std::cout << test_athlete2 << std::endl;

    std::cout << "Athlete Class Insert 2" << std::endl;
    test_athlete2.insert(test_sport2);
    std::cout << test_athlete2 << std::endl;

    std::cout << "Node Class 2" << std::endl;
    Node test_node2;
    std::cout << test_node2 << std::endl;
    std::cout << "Node Class + Overload" << std::endl;
    test_node2 = test_node2 + test_athlete2;
    std::cout << test_node2 << std::endl;


    delete [] test_char;
    delete test_string;
    delete [] test_char2;
    delete test_string2;

    return 0;
}
