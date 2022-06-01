#pragma once
#include<vector>
#include <iostream>
#include <map>
#include "Team.hpp"
#include "Leauge.hpp"
#include "Game.hpp"
class Schedule
{
private:
    std::map<int, std::vector<Game*>> Leage_games;
    Leauge* league;

public:
    Schedule(/* args */);
    Schedule(Leauge* newleague);
    ~Schedule();
int League_rounds();

Leauge* get_League(){return league;}


    friend std::ostream &operator<<(std::ostream &COUT, Schedule& S1);
};

