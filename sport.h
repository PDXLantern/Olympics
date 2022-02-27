// Carlos Rivera
// Purpose: The purpose of this file is to store the base class and the derived classes.
// The base class will be the sport class, which will manage the common elements of the derived classess.
// Each derived class is a different sports from the Olympics, such as Soccer, Basketball, & Boxing.
#pragma once
#include <iostream>
// base class
class Sport
{
	public:
		// constructor
		Sport();
		// copy constructor
		Sport(const Sport & rhs);
		// constructor w args
		Sport(const int & from_GP, const int & from_wins, const int & from_loss);
		// display
		bool display() const;
		// add game
		bool add_game(const int & WinOrLoss);
		// return win rate
		float win_rate() const;
		// calculate win rate
		float win_rate(const int & games_won, const int & games_played); 
		// return loss rate
		float loss_rate() const;
		// calculate loss rate
		float loss_rate(const int & games_lost, const int & games_played);
		// operators
		friend bool operator == (const Sport & lhs, const Sport & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, Sport & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Sport & rhs);
	protected:
		// number of games played
		int games_played;
		// number of games won
		int wins;
		// number of games lost
		int loss;
		// the win rate
		float total_win_rate;
		// the loss rate
		float total_loss_rate;
};

// derived class Hockey
class Hockey : public Sport
{
	public:
		// hockey constructor
		Hockey();
		// hockey copy constructor
		Hockey(const Hockey & rhs);
		// hockey constructor w args
		Hockey(const int & num_saves, const int & num_penalties, const int & num_goals, const int & from_GP, const int & from_wins, const int & from_loss);
		// hockey compare 
		bool compare(const Hockey & rhs) const;
		// hockey display 
		bool display() const;
		// add a game to update stats
		bool add_game(const int & num_saves, const int & num_penalties, const int & num_goals, const int & WinOrLoss);
		// calculate average number of saves per game
		float saves_per_game() const;
		// calculate saves to goals ratio
		float goals_per_game() const;
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
		// basketball copy constructor
		Basketball(const Basketball & rhs);
		// basketball constructor w args
		Basketball(const int & num_field_goals, const int & num_three_fg, const int & num_fouls, const int & from_GP, const int & from_wins, const int & from_loss);
		// basketball compare
		bool compare(const Basketball & rhs) const;
		// basketball display
		bool display() const;
		// basketball add game
		bool add_game(const int & num_field_goals, const int & num_three_fg, const int & fouls, const int & WinOrLoss);
		// calculate avg field goals per game
		float avg_field_goals() const;
		// calculate 3 point %
		float three_fg_percentage() const;
		// calulate number of fouls per minute
		float fouls_per_minute() const;
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
		// soccer copy contructor
		Soccer(const Soccer & rhs);
		// soccer constructor w args
		Soccer(const int & num_goals, const int & num_AP, const int & num_SOG, const int & from_GP, const int & from_wins, const int & from_loss);
		// soccer compare
		bool compare(const Soccer & rhs) const;
		// soccer display
		bool display() const;
		// soccer add a game
		bool add_game(const int & num_goals, const float & num_AP, const int & num_SOG, const int & WinOrLoss);
		// calculate avg num_goals per game
		int avg_goals() const;
		// calculate avg possession %
		float avg_possesion() const;
		// calcultate number of shots on goal per game
		int shots_per_game() const;
		// != overload
		friend bool operator != (const Soccer & lhs, const Soccer & rhs);
		// input overload
		friend std::istream & operator >> (std::istream & input, const Soccer & rhs);
		// output overload
		friend std::ostream & operator << (std::ostream & output, const Soccer & rhs);
	private:
		// amount of goals scored
		int total_goals;
		// average ball possession %
		float total_AP;
		// amount of shot taken at the goal
		int total_SOG;
};


