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
		// = overload
		bool operator = (const Athlete & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, Athlete & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Athlete & rhs);
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
		bool link_left(const Node & rhs);
		// link right node;
		bool link_right(const Node & rhs);
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
		bool search() const;
		bool insert() const;
		bool remove() const;
		// add an athlete to data structure
		bool operator +=(const BinaryTree & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, BinaryTree & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const BinaryTree & rhs);
	private:
		Node * root;
};

class List
{
	public:
	private:
		Hockey * Hockey_Event[5];
		std::vector<Basketball *> Basketball_Event;
		Soccer * BinaryTree;

};
