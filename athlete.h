// Carlos Rivera
// Purpose: the purpose of this file is to hold the athlete class and the data structures classes.
// The athlete class will have a derived class in each object depending on what sport the athelete
// specializes in. The athlete class will be stored in a binary tree, vector, or array data structure.
#include <iostream>
#include "sport.h"
#include <string>
#include <cstring>
#include <vector>
class Athlete
{
	public:
		// constructor
		Athlete();
		// constructor w args
		Athlete(const char * rhs_name, const std::string * rhs_country, const int & rhs_ranking);
		// copy constuctor
		Athlete(const Athlete & rhs);
		// insert hockey obj
		bool insert(const Hockey & rhs);
		// insert basketball obj
		bool insert(const Basketball & rhs);
		// insert soccer obj
		bool insert(const Soccer & rhs);
		// destructor
		~Athlete();
		// copy
		bool copy(const Athlete & rhs);
		// compare 
		bool compare(const Athlete & rhs) const;
		// display
		bool display() const;
		// get sport data type 
		int sport_type() const;
		// get key
		int key() const;
		// = overload
		bool operator = (const Athlete & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, Athlete & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Athlete & rhs);
		// > overload
		//friend bool operator > (const Athlete)
	protected:
		// athlete details
		char * name;
		// athlete country
		std::string * country;
		// athlete offical ranking
		int ranking;
		// Sport data types
		Hockey * hockey_data;
		Soccer * soccer_data;
		Basketball * basketball_data;
};

class Node : public Athlete
{
	public: 
		// constructor
		Node();
		// copy constructor
		Node(const Node & rhs);
		// destructor
		~Node();
		// go to left node
		Node * go_left() const;
		// go to right node
		Node * go_right() const;
		// link left node;
		bool link_left(Node * rhs);
		// link right node;
		bool link_right(Node * rhs);
		// insert athlete 
		bool insert(const Athlete & rhs);
		// display
		bool display() const;
		// empty
		bool empty() const;
		// + operator
		friend Node & operator + (Node & lhs, const Athlete & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, Node & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Node & rhs);
		// > operator
		friend bool operator >(const Node & lhs, const Node & rhs);
	protected:
		Node * left;
		Node * right;
};

class BinaryTree
{
	public:
		BinaryTree();
		BinaryTree(const BinaryTree & rhs);
		~BinaryTree();
		bool display() const;
		bool search(const int & rhs_key) const;
		bool insert(const Node & rhs);
		bool remove(const int & rhs_key);
		// add an athlete to data structure
		bool operator +=(const Node & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, BinaryTree & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const BinaryTree & rhs);
	protected:
		Node * copy_nodes(Node * curr, const Node * rhs);
		bool display (const Node * curr) const;
		Node * insert(Node * curr, const Node & rhs);
		Node * remove(Node * curr, const int & rhs_key);
		Node * nextInOrder(Node * curr);
		bool remove_nodes(Node * curr);
		bool search(const Node * curr, const int & rhs_key) const;
		Node * root;
};

class List
{
	public:
		List();
		List(const List & rhs);
		~List();
		bool load_file();
		bool read_hockey_event(std::fstream & data_file, int count);
		bool read_basketball_event(std::fstream & data_file);
		bool read_soccer_event(std::fstream & data_file, int count);
		bool search(const int & rank);
		bool display() const;
		bool display_hockey() const;
		bool display_basketball() const;
		bool display_soccer() const;
		friend std::ostream & operator << (std::ostream & output, const List & rhs);
	private:
		bool create_nodes(Node **& curr, int index, const Node & rhs);
		bool remove_array(Node **& curr, int index);
		bool create_vector(const Node & rhs);
		bool remove_vector();
		bool create_BT(const Node & curr);
		
		bool display_array(Node ** curr, int index) const;
		bool display_vector() const;
		Node ** Hockey_Event;
		std::vector<Node *> Basketball_Event;
		BinaryTree * Soccer_Event;
		int size;
		int max_char = 100;
};
