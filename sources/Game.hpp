#pragma once
#include <iostream>
#include "Team.hpp"

class Game
{
private:
    Team* Home_team;
    Team* Away_team;
    int Home_points;
    int Away_points;
public:
    Game(Team* Home, Team* Away);
    bool did_home_won();
    ~Game();
    std::string get_home_team()const {return Home_team->Get_team_name();}
    std::string get_away_team()const{return Away_team->Get_team_name();}
   
};

