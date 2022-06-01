#pragma once
#include<vector>
#include <iostream>
#include "Team.hpp"


class Leauge
{
private:
    std::vector<Team*>League_teams;
    std::vector<std::string> rnd_teams_name={"Los Angeles Clippers","San Antonio Spurs","Sacramento Kings","Cleveland Cavaliers","Brooklyn Nets","Denver Nuggets","Chicago Bulls","Minnesota Timberwolves","New York Knicks","Detroit Pistons","Houston Rockets","Golden State Warriors","Memphis Grizzlies","Boston Celtics","Oklahoma City Thunder","Toronto Raptors","Charlotte Hornets","Orlando Magic","Dallas Mavericks","Atlanta Hawks"};
public:
    Leauge(std::vector<Team*>teams);
    Leauge();
    ~Leauge();
    std::vector<Team*> get_teams(){return League_teams;}
    Team* Team_Generator();
};

