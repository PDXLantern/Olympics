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
Athlete::Athlete(const Athlete & rhs) : ranking(rhs.ranking)
{
    this->name = new char[strlen(rhs.name) + 1];
    strcpy(this->name, rhs.name);
    this->country = new std::string(*rhs.country);
    switch (rhs.sport_type())
    {
        case 0:
            std::cout << "No Data" << std::endl;
            break;
        case 1:
            hockey_data = new Hockey(*rhs.hockey_data);
            break;
        case 2:
            basketball_data = new Basketball(*rhs.basketball_data);
            break;
        case 3:
            soccer_data = new Soccer(*rhs.soccer_data);
            break;
        default:
            break;
    }
}
// - athlete destructor
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
bool Athlete::compare(const Athlete & rhs) const
{
    return false;
}
// - athlete
bool Athlete::display() const
{
    if(name)
        std::cout << "Name: " << name << std::endl;
    if(country)
        std::cout << "Country: " << country << std::endl;
    if(name && country)
        std::cout << "Ranking: " << ranking << std::endl;
    if(hockey_data)
        hockey_data->display();
    if(soccer_data)
        soccer_data->display();
    if(basketball_data)
        basketball_data->display();
    if (!hockey_data && !soccer_data && !basketball_data)
        std::cout << "No Sport Data" << std::endl;
    return false;
}
// - athlete data type
int Athlete::sport_type() const
{
    if(hockey_data)
        return 1;
    if(basketball_data)
        return 2;
    if(soccer_data)
        return 3;
    return 0;
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
    rhs.display();
    return output;
}
// node class
// - node constructor
Node::Node()
{
    // node pointers
    left = nullptr;
    right = nullptr;
}
// - node copy constructor
Node::Node(const Node & rhs)
{

}
// - node destructor
Node::~Node()
{
    if(left)
        delete left;

    if(right)
        delete right;
}
// - node go left
Node * Node::go_left() const
{
    if(left)
        return left;
    return nullptr;
}
// - node go right
Node * Node::go_right() const
{
    if(right)
        return right;
    return nullptr;
}
// - node display
bool Node::display() const
{
    Athlete::display();
    return true;
}
// - node empty
bool Node::empty() const
{
    if(left && right)
        return false;
    return true;
}
// - node input overload
std::istream & operator >> (std::istream & input, Node & rhs)
{
    return input;
}
// - node output overload
std::ostream & operator << (std::ostream & output, const Node & rhs)
{
    rhs.display();
    return output;
}

// binarytree class
// - binarytree public functions
// - binarytree constructor
BinaryTree::BinaryTree()
{
    // - binarytree root node
    root = nullptr;
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