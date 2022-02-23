#include "athlete.h"
// athlete class
// - athlete public functions
// - athlete constructor
Athlete::Athlete()
{
    name = nullptr;
    country = nullptr;
    ranking = 0;
    hockey_data = nullptr;
    soccer_data = nullptr;
    basketball_data = nullptr;
    // Sport * Data; <- Could be easier to use
}
// - athlete copy constructor
Athlete::Athlete(const Athlete & aAthlete)
{

}
// - athlete
Athlete::~Athlete()
{
    if(name)
        delete name;
    if(country)
        delete country;
    if(ranking)
        ranking = 0;
    if(hockey_data)
        delete hockey_data;
    if(soccer_data)
        delete soccer_data;
    if(basketball_data)
        delete basketball_data;
}
// - athlete compare
bool Athlete::compare(const Athlete & aAthlete)
{
    return false;
}
// - athlete
bool Athlete::display()
{
    return false;
}
// - athlete
bool Athlete::insert()
{
    return false;
}
// - athlete
bool Athlete::assign_sport(const int & data) 
{
    return false;
}
// - athlete = overload
bool Athlete::operator = (const Athlete & rhs)
{
    return true;
}

// - athlete + overload
bool Athlete::operator + (const Athlete & rhs)
{
    return true;
}
// - athlete input overload
std::istream & operator >> (std::istream & input, Athlete & rhs)
{
    return input;
}
// - athlete output overload
std::ostream & operator << (std::ostream & output, const Athlete & rhs)
{
    return output;
}

// binarytree class
// - binarytree public functions
// - binarytree constructor
BinaryTree::BinaryTree()
{
    // - binarytree root node
    root = nullptr;
    // - binarytree left node
    left = nullptr;
    // - binarytree right node
    right = nullptr;
}
// - binarytree copy contructor
BinaryTree::BinaryTree(const BinaryTree & aBinaryTree)
{

}
// - binarytree destructor
BinaryTree::~BinaryTree()
{
    
}
// - binarytree display
bool BinaryTree::display() const
{
    return false;
}
// - binarytree search
bool BinaryTree::search() const
{
    return false;
}
// - binarytree insert
bool BinaryTree::insert() const
{
    return false;
}
// - binarytree remove
bool BinaryTree::remove() const
{
    return false;
}
// - binarytree add an athlete to data structure
bool BinaryTree::operator +=(const BinaryTree & rhs)
{
    return false;
}
// - binarytree input overload
std::istream & operator >> (std::istream & input, BinaryTree & rhs)
{
    return input;
}
// - binarytreeoutput overload
std::ostream & operator << (std::ostream & output, const BinaryTree & rhs)
{
    return output;
}