#include "sport.h"
// sport class
// - public functions
// - sport constructor
Sport::Sport()
{
    games_played = 0;
    wins = 0;
    loss = 0;
    total_win_rate = 0.00;
    total_loss_rate = 0.00;
}
// - sport copy constructor
Sport::Sport(const Sport & aSport) : Sport(aSport.games_played, aSport.wins, aSport.loss)
{

}
// - sport contructor w args
Sport::Sport(const int from_GP, const int from_wins, const int from_loss) : Sport()
{
        games_played = from_GP;
        wins = from_wins;
        loss = from_loss;
        this->win_rate(this->wins, this->games_played);
        this->loss_rate(this->loss, this->games_played);
}
// - sport display
bool Sport::display() const
{
    std::cout << "Games Played: " << games_played << std::endl;
    std::cout << "Wins: " << wins << std::endl;
    std::cout << "Loss: " << loss << std::endl;
    std::cout << "Win Rate: " << total_win_rate << " %" << std::endl;
    std::cout << "Loss Rate: " << total_loss_rate << " %" << std::endl;
    return false;
}
// - sport calculate win rate
float Sport::win_rate(const int & games_won, const int & games_played)
{
    if(games_played != 0)
    {
        total_win_rate = (static_cast<float>(games_won) / static_cast<float>(games_played)) * 100.00;
        return total_win_rate;
    }
    return 0;
}
// - sport calculate loss rate
float Sport::loss_rate(const int & games_lost, const int & games_played)
{
    if(games_played != 0)
    {
        total_loss_rate = (static_cast<float> (games_lost) / static_cast<float>(games_played)) * 100.00;
        return total_loss_rate;
    }
    return 0;
}
// - sport overload ==
bool operator == (const Sport & lhs, const Sport & rhs)
{
    return false;
}
// - input overload
std::istream & operator >> (std::istream & input, Sport & rhs)
{
    return input;
}
// - output overload
std::ostream & operator << (std::ostream & output, const Sport & rhs)
{
    rhs.display();
    return output;
}
// private

// hockey class
// - hockey public functions
// - hockey constructor
Hockey::Hockey()
{
    // - hockey number of saves
    saves = 0;
    // - hockey number of penalties
    penalties = 0;
    // - hockey number of goals made
    goals = 0;
}
// - hockey compare 
bool Hockey::compare(const Hockey & aHockey)
{
    return false;
}
// - hockey display 
bool Hockey::display() const
{
    return false;
} 
// - hockey add a game to update stats
bool Hockey::add_game(const int & num_saves, const int & num_penalties, const int & num_goals)
{
    return false;
} 
// - hockey calculate average number of saves per game
int Hockey::avg_saves()
{
    return 0;
} 
// - hockey calculate saves to goals ratio
int Hockey::saves_goal_ratio()
{
    return 0;
} 
// - hockey reset stats
bool Hockey::reset()
{
    return false;
} 
// - hockey overload !=
bool operator != (const Hockey & lhs, const Hockey & rhs)
{
    return false;
}
// - hockey input overload
std::istream & operator >> (std::istream & input, const Hockey & rhs)
{
    return input;
}
// - hockey output overload
std::ostream & operator << (std::ostream & output, const Hockey & rhs) 
{
    return output;
}

// basketball class
// - public functions
// - basketball constructor
Basketball::Basketball()
{
    // - basketball amoount of baskets made
    field_goals = 0;
    // - basketball amount of 3 pointers made
    three_fg = 0;
    // - basketball amount of fouls committed
    fouls = 0;
}
// - basketball compare
bool Basketball::compare(const Basketball & aBasketball)
{
    return false;
}
// - basketball display
bool Basketball::display() const
{
    return false;
} 
// - basketball add game
bool Basketball::add_game(const int & num_field_goals, const int & num_three_fg, const int & fouls)
{
    return false;
}
// - basketball calculate avg field goals per game
int Basketball::avg_field_goals()
{
    return 0;
}
// - basketball calculate 3 point %
int Basketball::three_fg_percentage()
{
    return 0;
}
// - basketball calulate number of fouls per minute
int Basketball::fouls_per_minute()
{
    return 0;
}
// - basketball operators
bool operator != (const Basketball & lhs, const Basketball & rhs)
{
    return false;
}
// - basketball input overload
std::istream & operator >> (std::istream & input, const Basketball & rhs)
{
    return input;
}
// - basketball output overload
std::ostream & operator << (std::ostream & output, const Basketball & rhs)
{
    return output;
}

// soccer class
// - soccer public functions
// - soccer constructor
Soccer::Soccer()
{
    // - soccer amount of goals scored
    goals = 0;
    // - soccer average ball possession %
    avg_possession = 0;
    // - soccer amount of shot taken at the goal
    shots_on_goal = 0;
}
// - soccer compare
bool Soccer::compare(const Soccer & aSoccer)
{
    return false;
}
// - soccer display
bool Soccer::display() const
{
    return false;
}
// - soccer add a game
bool Soccer::add_game(const int & num_goals, const float & num_possession, const int & num_shots)
{
    return false;
}
// - soccer calculate avg num_goals per game
int Soccer::avg_goals()
{
    return 0;
}
// - soccer calculate avg possession %
float Soccer::avg_possesion()
{
    return 0.00;
}
// - soccer calcultate number of shots on goal per game
int Soccer::shots_per_game()
{
    return 0;
}
// - soccer != overload
bool operator != (const Soccer & lhs, const Soccer & rhs)
{
    return false;
}
// - soccer input overload
std::istream & operator >> (std::istream & input, const Soccer & rhs) 
{
    return input;
}
// - soccer output overload
std::ostream & operator << (std::ostream & output, const Soccer & rhs)
{
    return output;
}
