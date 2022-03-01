#include "main.h"
int main()
{
    Basketball test_sport (400, 340, 123, 4, 3, 1);
    char * test_char = new char [strlen("USA National Team")+1];
    strcpy(test_char,"USA");
    std::string * test_string = new std::string("United States of America");
    Athlete test_athlete(test_char, test_string, 5);
    test_athlete.insert(test_sport);
    Node test_node;
    test_node.insert(test_athlete);

    Basketball test_sport2 (500, 250, 32, 10, 1, 9);
    char * test_char2 = new char [strlen("Brazil National Team")+1];
    strcpy(test_char2,"Brazil");
    std::string * test_string2 = new std::string("United States of America");
    Athlete test_athlete2(test_char2, test_string2, 4);
    test_athlete2.insert(test_sport2);
    Node test_node2;
    test_node2 = test_node2 + test_athlete2;

    Basketball test_sport3 (600, 300, 32, 10, 1, 9);
    char * test_char3 = new char [strlen("Canada National Team")+1];
    strcpy(test_char3,"Canada");
    std::string * test_string3 = new std::string("United States of America");
    Athlete test_athlete3(test_char3, test_string3, 6);
    test_athlete3.insert(test_sport3);
    Node test_node3;
    test_node3 = test_node3 + test_athlete3;
    
    if(test_node > test_node2)
        std::cout << "Success" << std::endl;

    Node * test_node4;
    test_node.link_left(test_node4);

    BinaryTree test_tree;
    test_tree.insert(test_node);
    test_tree.insert(test_node2);
    test_tree.insert(test_node3);
    
    std::cout << test_tree << std::endl;
    
    delete [] test_char;
    delete test_string;
    delete [] test_char2;
    delete test_string2;
    delete [] test_char3;
    delete test_string3;
    return 0;
}
