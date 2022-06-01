#pragma once
#include <iostream>

class Team
{
private:
    std::string team_name;
    double team_skill;
    int longest_win_streak;
    int longest_lose_steak;
    int match_schedule[38];
    // int scored;
    // int 
public:
    Team(std::string name,double skill);
    ~Team();
    std::string Get_team_name(){return team_name;}
    double Get_team_skill(){return team_skill;}
    void Set_team_skill(double ns);
    void set_team_name(std::string nn);
    bool is_booked(int round);
    void book_match(int round,int desicson);
    friend std::ostream &operator<<(std::ostream &COUT, Team& T1);

};
