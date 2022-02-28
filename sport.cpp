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
Sport::Sport(const Sport & rhs) : Sport(rhs.games_played, rhs.wins, rhs.loss)
{

}
// - sport contructor w args
Sport::Sport(const int & from_GP, const int & from_wins, const int & from_loss) : Sport()
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
// - sport add game
bool Sport::add_game(const int & WinOrLoss)
{
    games_played++;
    if(WinOrLoss == 1)
    {
        wins++;
        this->win_rate(this->wins, this->games_played);
        return true;
    }
    loss++;
    this->loss_rate(this->loss, this->games_played);
    return true;
}
// - sport win rate
float Sport::win_rate() const
{
    return total_win_rate;
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
// - sport loss rate
float Sport::loss_rate() const
{
    return total_loss_rate;
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
    // if winrate is a match
    if(lhs.win_rate() == rhs.win_rate())
    {
        // iff loss rate is a match
        if(lhs.loss_rate() == rhs.loss_rate())
            return true;
    }
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
// - hockey copy constructor
Hockey::Hockey(const Hockey & rhs) : Sport(rhs.games_played, rhs.wins, rhs.loss), 
saves(rhs.saves), penalties(rhs.penalties), goals(rhs.goals)
{

}
// - hockey constructor w args
Hockey::Hockey(const int & num_saves, const int & num_penalties, const int & num_goals, const int & from_GP, const int & from_wins, const int & from_loss) : 
saves(num_saves), penalties(num_penalties), goals(num_goals), Sport(from_GP, from_wins, from_loss)
{
    
}
// - hockey compare 
bool Hockey::compare(const Hockey & rhs) const
{
        // check hockey saves
    if(saves_per_game() == rhs.saves_per_game())
    {
        // check goals per game
        if(goals_per_game() == rhs.goals_per_game())
            return true;
    }
    return false;
}
// - hockey display 
bool Hockey::display() const
{
    Sport::display();
    std::cout << "Saves: " << saves << std::endl;
    std::cout << "Penalties: " << penalties << std::endl;
    std::cout << "Goals: " << goals << std::endl;
    std::cout << "Goals Per Game: " << goals_per_game() << std::endl;
    std::cout << "Saves Per Game " << saves_per_game() << std::endl;
    return false;
} 
// - hockey add a game to update stats
bool Hockey::add_game(const int & num_saves, const int & num_penalties, const int & num_goals, const int & WinOrLoss)
{
    saves += num_saves;
    penalties += num_penalties;
    goals += num_goals;
    Sport::add_game(WinOrLoss);
    return true;
} 
// - hockey calculate average number of saves per game
float Hockey::saves_per_game() const
{
    if(saves != 0) 
        return (static_cast<float>(this->saves) / static_cast<float>(games_played) + 0.00);
    return 0;
} 
// - hockey calculate saves to goals ratio
float Hockey::goals_per_game() const
{
    if(goals != 0) 
        return (static_cast<float> (this->goals) / static_cast<float>(games_played)+ 0.00);
    return 0;
} 
// - hockey reset stats
bool Hockey::reset()
{
    this->saves = 0;
    this->penalties = 0;
    this->goals = 0;
    if(saves && penalties && goals == 0)
        return true;
    return false;
} 
// - hockey overload !=
bool operator != (const Hockey & lhs, const Hockey & rhs)
{
    if(lhs.compare(rhs))
        return false;
    return true;
}
// - hockey input overload
std::istream & operator >> (std::istream & input, const Hockey & rhs)
{
    return input;
}
// - hockey output overload
std::ostream & operator << (std::ostream & output, const Hockey & rhs) 
{
    rhs.display();
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
// - basketball copy constructor
Basketball::Basketball(const Basketball & rhs) : Sport(rhs.games_played, rhs.wins, rhs.loss),
field_goals(rhs.field_goals), three_fg(rhs.three_fg), fouls(rhs.fouls)
{

}
// - basketball constructor w args
Basketball::Basketball(const int & num_field_goals, const int & num_three_fg, const int & num_fouls, const int & from_GP, const int & from_wins, const int & from_loss) : 
field_goals(num_field_goals), three_fg(num_three_fg), fouls(num_fouls), Sport(from_GP, from_wins, from_loss)
{

}
// - basketball compare
bool Basketball::compare(const Basketball & rhs) const
{
    //
    if(avg_field_goals() == rhs.avg_field_goals())
    {
        if(three_fg_percentage() == rhs.three_fg_percentage())
            return true;
    }
    return false;
}
// - basketball display
bool Basketball::display() const
{
    // sport display vars
    Sport::display();
    // basketball display vars
    std::cout << "Total Points: " << field_goals << std::endl;
    std::cout << "Average Points Per Game: " << avg_field_goals() << std::endl;
    std::cout << "Total 3 PT: " << three_fg << std::endl;
    std::cout << "3 Point %: " << three_fg_percentage() << " %" << std::endl;
    std::cout << "Total Fouls: " << fouls << std::endl;
    std::cout << "Fouls Per Minutes: " << fouls_per_minute() << std::endl;
    return false;
} 
// - basketball add game
bool Basketball::add_game(const int & num_field_goals, const int & num_three_fg, const int & num_fouls, const int & WinOrLoss)
{
    // basketball vars + 1
    field_goals += num_field_goals;
    three_fg += num_three_fg;
    fouls += num_fouls;
    // sport vars + 1
    Sport::add_game(WinOrLoss);
    return true;
}
// - basketball calculate avg field goals per game
float Basketball::avg_field_goals() const
{
    // check for division by 0
    if(games_played != 0) 
        return static_cast <float> (field_goals) / static_cast <float> (games_played);
    return 0;
}
// - basketball calculate 3 point %
float Basketball::three_fg_percentage() const
{
    // check for division by 0
    if(field_goals)
        return (static_cast <float> (three_fg) / static_cast<float> (field_goals)) * 100.00;
    return 0;
}
// - basketball calulate number of fouls per minute
float Basketball::fouls_per_minute() const
{
    if(games_played != 0)
        return static_cast <float> (fouls) / (static_cast <float>(games_played) * 240.00);
    return 0;
}
// - basketball operators
bool operator != (const Basketball & lhs, const Basketball & rhs)
{
    // call compare function 
    if(lhs.compare(rhs))
    {
        return false;
    }
    return true;
}
// - basketball input overload
std::istream & operator >> (std::istream & input, const Basketball & rhs)
{
    return input;
}
// - basketball output overload
std::ostream & operator << (std::ostream & output, const Basketball & rhs)
{
    rhs.display();
    return output;
}

// soccer class
// - soccer public functions
// - soccer constructor
Soccer::Soccer()
{
    // - soccer amount of goals scored
    total_goals = 0;
    // - soccer average ball possession %
    total_corners = 0;
    // - soccer amount of shot taken at the goal
    total_SOG = 0;
}
// - soccer copy constructor
Soccer::Soccer(const Soccer & rhs) : Sport(rhs.games_played, rhs.wins, rhs.loss),
total_goals(rhs.total_goals), total_corners(rhs.total_corners), total_SOG(rhs.total_SOG)
{

}
// - soccer constructor w args
Soccer::Soccer(const int & num_goals, const int & num_corners, const int & num_SOG, const int & from_GP, const int & from_wins, const int & from_loss) :
total_goals(num_goals), total_corners(num_corners), total_SOG(num_SOG), Sport(from_GP, from_wins, from_loss)
{

}
// - soccer compare
bool Soccer::compare(const Soccer & rhs) const
{
    if(total_goals == rhs.total_goals && total_corners == rhs.total_corners && total_SOG == total_SOG)
    {
        return true;
    }
    return false;
}
// - soccer display
bool Soccer::display() const
{
    Sport::display();
    std::cout << "Total Goals: "<< total_goals << std::endl;
    std::cout << "Average Goals: " << avg_goals() << std::endl;
    std::cout << "Total Corners: " << total_corners << std::endl;
    std::cout << "Average Corners: " << avg_corners() << std::endl;
    std::cout << "Total Shots On Goal: " << total_SOG << std::endl;
    std::cout << "Shots On Goal Per Game: " << shots_per_game() << std::endl;
    return false;
}
// - soccer add a game
bool Soccer::add_game(const int & num_goals, const float & num_corners, const int & num_SOG, const int & WinOrLoss)
{
    total_goals += num_goals;
    total_corners += num_corners;
    total_SOG += num_SOG;
    Sport::add_game(WinOrLoss);
    return false;
}
// - soccer calculate avg num_goals per game
int Soccer::avg_goals() const
{
    if(games_played != 0)
        return total_goals / games_played;
    return 0;
}
// - soccer calculate avg possession %
float Soccer::avg_corners() const
{
    if(games_played != 0)
        return total_corners / games_played;
    return 0.00;
}
// - soccer calcultate number of shots on goal per game
int Soccer::shots_per_game() const
{
    if(games_played != 0)
        return total_SOG / games_played;
    return 0;
}
// - soccer != overload
bool operator != (const Soccer & lhs, const Soccer & rhs)
{
    if(lhs.compare(rhs))
        return false;
    return true;
}
// - soccer input overload
std::istream & operator >> (std::istream & input, const Soccer & rhs) 
{
    return input;
}
// - soccer output overload
std::ostream & operator << (std::ostream & output, const Soccer & rhs)
{
    rhs.display();
    return output;
}
