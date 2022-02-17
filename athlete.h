// Carlos Rivera
// Purpose: the purpose of this file is to hold the athlete class and the data structures classes.
// The athlete class will have a derived class in each object depending on what sport the athelete
// specializes in. The athlete class will be stored in a binary tree, vector, or array data structure.
#include <iostream>
#include <string>
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
		// operators	
	protected:
		char * name;
		std::string * country;
		int ranking;
		Hockey * Data;
		Soccer * Data;
		Basketball * Data;
		// Sport * Data; <- Could be easier to use
};

class BinaryTree
{
	public:
		BinaryTree();
		BinaryTree(const BinaryTree & aBinaryTree);
		~BiaryTree()
		bool display() const;
		bool search() const;
		bool insert() const;
		bool remove() const;
		// operators
	private:
		Athlete * root;
		Athelete * left;
		Athelte * right;
}