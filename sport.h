// Carlos Rivera
// Purpose: The purpose of this file is to store the base class and the derived classes.
// The base class will be the sport class, which will manage the common elements of the derived classess.
// Each derived class is a different sports from the Olympics, such as Soccer, Basketball, & Boxing.
#include <iostream>
// base class
class Sport
{
	public:
		// constructor
		Sport();
		// copy constructor
		Sport(const Sport & aSport);
		// display
		bool display() const;
		// calculate win rate
		int win_rate(const int & games_won, const int & games_played); 
		// calculate loss rate
		int loss_rate(const int & games_lost, const int & games_played);
		// operators
		friend bool operator == (const Sport & lhs, const Sport & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, Sport & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Sport & rhs);
	protected:
		// number of games played
		int game_played;
		// number of games won
		int wins;
		// number of games lost
		int loss;
		// the win rate
		int total_win_rate;
};

// derived class Hockey
class Hockey : public Sport
{
	public:
		// hockey constructor
		Hockey();
		// hockey compare 
		bool compare(const Hockey & aHockey);
		// hockey display 
		bool display() const;
		// add a game to update stats
		bool add_game(const int & num_saves, const int & num_penalties, const int & num_goals);
		// calculate average number of saves per game
		int avg_saves();
		// calculate saves to goals ratio
		int saves_goal_ratio();
		// reset stats
		bool reset();
		// operators
		friend bool operator != (const Hockey & lhs, const Hockey & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, const Hockey & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Hockey & rhs);
	private:
		// number of draws
		int saves;
		// number of penalties
		int penalties;
		// number of goals made
		int goals;
};

// derived class Basketball
class Basketball : public Sport
{
	public:
		// basketball constructor
		Basketball();
		// basketball compare
		bool compare(const Basketball & aBasketball);
		// basketball display
		bool display() const;
		// basketball add game
		bool add_game(const int & num_field_goals, const int & num_three_fg, const int & fouls);
		// calculate avg field goals per game
		int avg_field_goals();
		// calculate 3 point %
		int three_fg_percentage();
		// calulate number of fouls per minute
		int fouls_per_minute();
		// operators
		friend bool operator != (const Basketball & lhs, const Basketball & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, const Basketball & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Basketball & rhs);
	private:
		// amoount of baskets made
		int field_goals;
		// amount of 3 pointers made
		int three_fg;
		// amount of fouls committed
		int fouls;
};

// derived class Soccer
class Soccer : public Sport
{
	public:
		// soccer constructor
		Soccer();
		// soccer compare
		bool compare(const Soccer & aSoccer);
		// soccer display
		bool display() const;
		// soccer add a game
		bool add_game(const int & num_goals, const float & num_possession, const int & num_shots);
		// calculate avg num_goals per game
		int avg_goals();
		// calculate avg possession %
		float avg_possesion();
		// calcultate number of shots on goal per game
		int shots_per_game;
		// != overload
		friend bool operator != (const Soccer & lhs, const Soccer & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, const Basketball & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Basketball & rhs);
	private:
		// amount of goals scored
		int goals;
		// average ball possession %
		float avg_possession;
		// amount of shot taken at the goal
		int shots_on_goal;
};


