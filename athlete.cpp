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
}
// - athlete contructor w args
Athlete::Athlete(const char * rhs_name, const std::string * rhs_country, const int & rhs_ranking) : Athlete()
{
    if(name)
        delete name;
    this->name = new char[strlen(rhs_name) + 1];
    strcpy(this->name, rhs_name);
    if(this->country)
         delete country;
    this->country = new std::string(*rhs_country);
    this->ranking = rhs_ranking;
}
// - athlete copy constructor
Athlete::Athlete(const Athlete & rhs) : Athlete()
{
    this->copy(rhs);
}
// - athlete insert hockey obj
bool Athlete::insert(const Hockey & rhs)
{
    this->hockey_data = new Hockey(rhs);
    return true;
}
// - athlete insert basketball obj
bool Athlete::insert(const Basketball & rhs)
{
    this->basketball_data = new Basketball(rhs);
    return true;
}
// - athlete insert soocer obj
bool Athlete::insert(const Soccer & rhs)
{
    this->soccer_data = new Soccer(rhs);
    return true;
}
// - athlete destructor
Athlete::~Athlete()
{
    if(name)
        delete [] name;
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
// - athlete copy
bool Athlete::copy(const Athlete & rhs)
{
    if(this != &rhs)
    {
        if(this->name)
            delete [] name;
        this->name = new char[strlen(rhs.name) + 1];
        strcpy(this->name, rhs.name);
        if(this->country)
            delete country;
        this->country = new std::string(*rhs.country);
        this->ranking = rhs.ranking;
        switch (rhs.sport_type())
        {
            case 0:
                std::cout << "No Data" << std::endl;
                return false;
                break;
            case 1:
                if(hockey_data)
                    delete hockey_data;
                hockey_data = new Hockey(*rhs.hockey_data);
                break;
            case 2:
                if(basketball_data)
                    delete basketball_data;
                basketball_data = new Basketball(*rhs.basketball_data);
                break;
            case 3:
                if(soccer_data)
                    delete soccer_data;
                soccer_data = new Soccer(*rhs.soccer_data);
                break;
            default:
                return false;
                break;
        }
        return true;
    }
    return false;
}
// - athlete compare
bool Athlete::compare(const Athlete & rhs) const
{
    if(this->sport_type() == rhs.sport_type())
    {
        switch (rhs.sport_type())
        {
            case 0:
                std::cout << "No Data" << std::endl;
                return false;
                break;
            case 1:
                if(*this->hockey_data != (*rhs.hockey_data))
                    return false;
                return true;
                break;
            case 2:
                if(*this->basketball_data != (*rhs.basketball_data));
                    return false;
                return true;
                break;
            case 3:
                if(*this->soccer_data != (*rhs.soccer_data))
                    return false;
                return true;
                break;
            default:
                return false;
                break;
        }
    }
    return false;
}
// - athlete
bool Athlete::display() const
{
    if(name)
        std::cout << "Name: " << name << std::endl;
    if(country)
        std::cout << "Country: " << *country << std::endl;
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
    if(this->copy(rhs))
        return true;
    return false;
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
Node::Node(const Node & rhs) : Athlete(rhs.name, rhs.country, rhs.ranking)
{
    left = nullptr;
    right = nullptr;
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
// node - link left node;
bool Node::link_left(const Node & rhs)
{
    if(this != &rhs)
    {
        if(this->left)
            delete this->left;
        this->left = new Node(rhs);
        return true;
    }
    return false;
}
// node - link right node;
bool Node::link_right(const Node & rhs)
{
    if(this != &rhs)
    {
        if(this->right)
            delete this->right;
        this->right = new Node(rhs);
        return true;
    }
    return false;
}
// node - insert athlete 
bool Node::insert(const Athlete & rhs)
{
    if(Athlete::copy(rhs))
        return true;
    return false;
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
// - node + overload
Node & operator + (Node & lhs, const Athlete & rhs)
{
    if(lhs.insert(rhs))
        return lhs;
    return lhs;
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
BinaryTree::BinaryTree(const BinaryTree & rhs)
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