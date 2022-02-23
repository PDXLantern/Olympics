// Carlos Rivera
// Purpose: the purpose of this file is to hold the athlete class and the data structures classes.
// The athlete class will have a derived class in each object depending on what sport the athelete
// specializes in. The athlete class will be stored in a binary tree, vector, or array data structure.
#include <iostream>
#include <string>
#include "sport.h"
class Athlete
{
	public:
		Athlete();
		Athlete(const Athlete & aAthlete);
		~Athlete();
		bool compare(const Athlete & aAthlete);
		bool display();
		bool insert();
		bool assign_sport(const int & data);
		// = overload
		bool operator = (const Athlete & rhs);
		// + overload
		bool operator + (const Athlete & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, Athlete & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Athlete & rhs);
	protected:
		char * name;
		std::string * country;
		int ranking;
		Hockey * hockey_data;
		Soccer * soccer_data;
		Basketball * basketball_data;
		// Sport * Data; <- Could be easier to use
};

class BinaryTree
{
	public:
		BinaryTree();
		BinaryTree(const BinaryTree & aBinaryTree);
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
		Athlete * root;
		Athlete * left;
		Athlete * right;
};
