#include "athlete.h"
#include <fstream>
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
    if(!root)
    {
        return false;
    }
    this->display(root);
    return true;
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
        curr->display();
        return true;
    }
    return false;
}

List::List()
{
    Hockey_Event = nullptr;
    Soccer_Event = nullptr;
    size = 5;
    load_file();
}
List::List(const List & rhs)
{

}
List::~List()
{
    if(Hockey_Event)
	{
		remove_array(Hockey_Event, 0);
		delete [] Hockey_Event;
	}
    remove_vector();
    if(Soccer_Event)
    {
        delete Soccer_Event;
    }
}
bool List::load_file()
{
    // hockey event
    // initiliaze array
    Hockey_Event = new Node *[size];
    //if(!create_nodes(Hockey_Event, 0))
        //return false;
    std::fstream data_file;
    data_file.open("hockey.txt");
    read_hockey_event(data_file, 0);
    data_file.close();

    // basketball event
    std::fstream basketball_file;
    basketball_file.open("basketball.txt");
    read_basketball_event(basketball_file);
    basketball_file.close();

    // soccer event
    Soccer_Event = new BinaryTree();
    std::fstream data_file2;
    data_file2.open("soccer.txt");
    read_soccer_event(data_file2, 0);
    data_file2.close();

    return true;
}
bool List::read_hockey_event(std::fstream & data_file, int count)
{
    if(data_file.eof())
        return true;

    char temp_name[max_char];
    char temp_country[max_char];
    int temp_rank;
    int temp_saves;
    int temp_penalties;
    int temp_goals;
    int games_played;
    int wins;
    int loss;

    data_file.get(temp_name, max_char, ';');
    data_file.ignore(2);
    data_file.get(temp_country, max_char, ';');
    data_file.ignore(2);
    data_file >> temp_rank;
    data_file.ignore(2);
    data_file >> temp_saves;
    data_file.ignore(2);
    data_file >> temp_penalties;
    data_file.ignore(2);
    data_file >> temp_goals;
    data_file.ignore(2);
    data_file >> games_played;
    data_file.ignore(2);
    data_file >> wins;
    data_file.ignore(2);
    data_file >> loss;
    data_file.ignore(2);

    char * nameptr = new char [strlen(temp_name)+1];
    strcpy(nameptr, temp_name);

    std::string * countryptr = new std::string(temp_country);
    
    Hockey test_sport (temp_saves, temp_penalties, temp_goals, games_played, wins, loss);

    Athlete temp_athlete(nameptr, countryptr, temp_rank);
    temp_athlete.insert(test_sport);
    Node temp_node;
    temp_node.insert(temp_athlete);
    create_nodes(Hockey_Event, count, temp_node);

    delete [] nameptr;
    delete countryptr;
    return read_hockey_event(data_file, ++count);
}
bool List::read_basketball_event(std::fstream & data_file)
{
    if(data_file.eof())
        return true;

    char temp_name[max_char];
    char temp_country[max_char];
    int temp_rank;
    int temp_FG;
    int temp_3FG;
    int temp_fouls;
    int games_played;
    int wins;
    int loss;

    data_file.get(temp_name, max_char, ';');
    data_file.ignore(2);
    data_file.get(temp_country, max_char, ';');
    data_file.ignore(2);
    data_file >> temp_rank;
    data_file.ignore(2);
    data_file >> temp_FG;
    data_file.ignore(2);
    data_file >> temp_3FG;
    data_file.ignore(2);
    data_file >> temp_fouls;
    data_file.ignore(2);
    data_file >> games_played;
    data_file.ignore(2);
    data_file >> wins;
    data_file.ignore(2);
    data_file >> loss;
    data_file.ignore(2);

    char * nameptr = new char [strlen(temp_name)+1];
    strcpy(nameptr, temp_name);

    std::string * countryptr = new std::string(temp_country);
    
    Basketball test_sport (temp_FG, temp_3FG, temp_fouls, games_played, wins, loss);

    Athlete temp_athlete(nameptr, countryptr, temp_rank);
    temp_athlete.insert(test_sport);
    Node temp_node;
    temp_node.insert(temp_athlete);

    create_vector(temp_node);

    delete [] nameptr;
    delete countryptr;
    return read_basketball_event(data_file);
}
bool List::read_soccer_event(std::fstream & data_file, int count)
{
    if(data_file.eof())
        return true;

    char temp_name[max_char];
    char temp_country[max_char];
    int temp_rank;
    int temp_goals;
    int temp_GA;
    int temp_GD;
    int games_played;
    int wins;
    int loss;

    data_file.get(temp_name, max_char, ';');
    data_file.ignore(2);
    data_file.get(temp_country, max_char, ';');
    data_file.ignore(2);
    data_file >> temp_rank;
    data_file.ignore(2);
    data_file >> temp_goals;
    data_file.ignore(2);
    data_file >> temp_GA;
    data_file.ignore(2);
    data_file >> temp_GD;
    data_file.ignore(2);
    data_file >> games_played;
    data_file.ignore(2);
    data_file >> wins;
    data_file.ignore(2);
    data_file >> loss;
    data_file.ignore(2);

    char * nameptr = new char [strlen(temp_name)+1];
    strcpy(nameptr, temp_name);

    std::string * countryptr = new std::string(temp_country);
    
    Soccer test_sport (temp_goals, temp_GA, temp_GD, games_played, wins, loss);

    Athlete temp_athlete(nameptr, countryptr, temp_rank);
    temp_athlete.insert(test_sport);
    Node temp_node;
    temp_node.insert(temp_athlete);
    create_BT(temp_node);

    delete [] nameptr;
    delete countryptr;
    return read_soccer_event(data_file, ++count);
}
bool List::search(const int & rank)
{
    if(rank > 0 && rank > 5)
        return false;
    std::cout << "Hockey Medal" << std::endl;
    for(int i = 0; i < size; i++)
        {
            if(Hockey_Event[i]->key() == rank)
            {
                Hockey_Event[i]->display();
                std::cout << std::endl;
            }
        }
    std::cout << "Basketball Medal" << std::endl;
    for(Node * curr: Basketball_Event)
    {
        if(curr->key() == rank)
        {
            curr->display();
            std::cout << std::endl;
        }
    }
    std::cout << "Basketball Medal" << std::endl;
    Soccer_Event->search(rank);
    return true;
}

bool List::display() const
{
    if(Hockey_Event)
        display_array(Hockey_Event, 0);
    display_vector();
        // display basketball event
    if(Soccer_Event)
        Soccer_Event->display();
        // display soccer event
    return true;
}
bool List::display_hockey() const
{
    if(Hockey_Event)
        return display_array(Hockey_Event, 0);
    return false;
}
bool List::display_basketball() const
{
    display_vector();
    return true;
}
bool List::display_soccer() const
{
    if(Soccer_Event)
        return Soccer_Event->display();
    return false;
}
std::ostream & operator << (std::ostream & output, const List & rhs)
{
    rhs.display();
    return output;
}

bool List::create_nodes(Node **& curr, int index, const Node & rhs)
{
    if(index == size)
    {
        return false;
    }
    curr[index] = new Node(rhs);
    return true;
}
bool List::remove_array(Node **& curr, int index)
{
    if(index == size)
	{
		return true;
	}
	// delete current
	if(curr[index])
	{
		// delete nodes in linked list
		delete curr[index];
	}
	// Go to next index
	return remove_array(curr, ++index);
}
bool List::create_vector(const Node & rhs)
{
    Node * temp = new Node(rhs);
    Basketball_Event.push_back(temp);
    return true;
}
bool List::create_BT(const Node & curr)
{
    Soccer_Event->insert(curr);
    return true;
}
bool List::remove_vector()
{
    for(Node * curr: Basketball_Event)
        delete curr;
    Basketball_Event.clear();
    return true;
}
bool List::display_array(Node ** curr, int index) const
{
    if(index == size)
    {
        return true;
    }
    if(curr[index])
    {
        curr[index]->display();
        std::cout << std::endl;
    }
    return display_array(curr, ++index);
}
bool List::display_vector() const
{
    for(Node * curr: Basketball_Event)
    {
        curr->display();
        std::cout << std::endl;
    }
    return true;
}