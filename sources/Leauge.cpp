
#include<vector>
#include <iostream>
#include <algorithm>
#include"Leauge.hpp"
const int MAX_CAPACITY =20;

using namespace std;

Leauge::Leauge(vector<Team*>teams){

    int slots_left=MAX_CAPACITY-teams.size();
    if(slots_left==0){
        this->League_teams=move(teams);
    }
    else{
        this->League_teams=move(teams);
        for (size_t i = 0; i < slots_left; i++)
        {   
        League_teams.push_back(this->Team_Generator());
        }
    }
}

Leauge::Leauge(){
    for (size_t i = 0; i < MAX_CAPACITY; i++)
    {
        League_teams.push_back(this->Team_Generator());
    }
}

Team* Leauge::Team_Generator(){
    double skill=rand() % (1 - 0 + 1) + 0;
    Team* newteam=new Team(this->rnd_teams_name.back(),skill);
    this->rnd_teams_name.pop_back();
    return newteam;
}