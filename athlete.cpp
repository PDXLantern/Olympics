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
// - athlete sport data type
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
int Athlete::key() const
{
    if(ranking != 0)
    {
        return ranking;
    }
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
bool Node::link_left(Node * rhs)
{
    if(rhs == nullptr)
    {
        left = nullptr;
        return false;
    }
    left = rhs;
    return true;
}
// node - link right node;
bool Node::link_right(Node * rhs)
{
    if(rhs == nullptr)
    {
        right = nullptr;
        return false;
    }
    right = rhs;
    return true;
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
// - node > operator
bool operator >(const Node & lhs, const Node & rhs)
{
    if(lhs.ranking > rhs.ranking)
        return true;
    return false;   
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
BinaryTree::BinaryTree(const BinaryTree & rhs) : BinaryTree()
{
    root = copy_nodes(root, rhs.root);
}
// - binarytree destructor
BinaryTree::~BinaryTree()
{
    remove_nodes(root);
}
// - binarytree display
bool BinaryTree::display() const
{
    this->display(root);
    return false;
}
// - binarytree search
bool BinaryTree::search(const int & rhs_key) const
{
    return search(root, rhs_key);
}
// - binarytree insert
bool BinaryTree::insert(const Node & rhs)
{
    return root = insert(root, rhs);
}
// - binarytree remove
bool BinaryTree::remove(const int & rhs_key)
{
    if(root)
    {
        root = remove(root, rhs_key);
        return true;
    }
    return false;
}
// - binarytree add an athlete to data structure
bool BinaryTree::operator +=(const Node & rhs)
{
    this->insert(rhs);
    if(root)
        return true;
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
    rhs.display();
    return output;
}
// binary class private
// - binary copy nodes
Node * BinaryTree::copy_nodes(Node * curr, const Node * rhs)
{
    if(rhs == nullptr)
    {
        return curr;
    }
    if(rhs)
    {
        curr = new Node(*rhs);
    }
    if(rhs->go_left())
    {
        Node * Temp = copy_nodes(curr->go_left(), rhs->go_left());
        curr->link_left(Temp);
    }
    if(rhs->go_right())
    {
        Node * Temp2 = copy_nodes(curr->go_right(), rhs->go_right());
        curr->link_right(Temp2);
    }
    return curr;
}
// - binarytree display
bool BinaryTree::display(const Node * curr) const
{
    if(curr->go_left())
        display(curr->go_left());
    curr->display();
    std::cout << std::endl;
    if(curr->go_right())
        display(curr->go_right());
    return true;
}
Node * BinaryTree::insert(Node * curr, const Node & rhs)
{
    if(curr == nullptr)
    {
        curr = new Node(rhs);
        return curr;
    }
    if(*curr > rhs)
    {
        if(curr->go_left() == nullptr)
        {
            curr->link_left(insert(curr->go_left(), rhs));
        }
        else
            insert(curr->go_left(), rhs);
    }
    else
    {
        if(curr->go_right() == nullptr)
        {
            curr->link_right(insert(curr->go_right(), rhs));
        }
        else
            insert(curr->go_right(), rhs);
    }
    return curr;
}
Node * BinaryTree::remove(Node * curr, const int & rhs_key)
{
    if(!curr)
    {
        std::cout << "No Match Found" << std::endl;
        return curr;
    }
    if(curr->key() > rhs_key)
    {
        curr->link_left(remove(curr->go_left(), rhs_key));
    }
    if (curr->key() < rhs_key)
    {
        curr->link_right(remove(curr->go_right(), rhs_key));
    }
    if (curr->key() == rhs_key)
    {
        std::cout << "Match Found" << std::endl;
        
        if(curr->go_left() == nullptr && curr->go_right() == nullptr)
        {
            std::cout << "Node has no children" << std::endl;
            delete curr;
            return NULL;
        }
        if(curr->go_left() && curr->go_right())
        {
            std::cout << "Node has both children" << std::endl;
            std::cout << "Next Node" << std::endl;
            Node * del = nextInOrder(curr->go_right());
            Node * Temp = new Node(*del);
            delete del;
            Temp->link_left(curr->go_left());
            delete curr;
            return Temp; 
        }
        if(curr->go_left() == nullptr && curr->go_right())
        {
            std::cout << "Node has no left child" << std::endl;
            Node * del = curr->go_right();
            Node * Temp = new Node(*del);
            delete del;
            delete curr;
            return Temp;
        }
        if(curr->go_right() == nullptr && curr->go_left())
        {
            std::cout << "Node has no right child" << std::endl;
            Node * del = curr->go_left();
            Node * Temp = new Node(*del);
            delete del;
            delete curr;
            return Temp;
        }
    }  
    return curr;
}
Node * BinaryTree::nextInOrder(Node * curr)
{
    if(curr->go_left() == nullptr)
        return curr;
    return nextInOrder(curr->go_left());
}
bool BinaryTree::remove_nodes(Node * curr)
{
    if(curr->go_left() != nullptr)
        remove_nodes(curr->go_left());
    if(curr->go_right() != nullptr)
        remove_nodes(curr->go_right());
    if(curr)
        delete curr;
    return true;
}
bool BinaryTree::search(const Node * curr, const int & rhs_key) const
{
    if(!curr)
        return false;
    if(curr->key() > rhs_key)
    {
        search(curr->go_left(), rhs_key);
    }
    if(curr->key() < rhs_key)
    {
        search(curr->go_right(), rhs_key);
    }
    if(curr->key() == rhs_key)
    {
        std::cout << "Match Found" << std::endl;
        curr->display();
        return true;
    }
    return false;
}