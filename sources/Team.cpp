#include"Team.hpp"
#include <iostream>

using namespace std;

Team::Team(std::string name,double skill){
    this->set_team_name(name);
    this->Set_team_skill(skill);
    for (size_t i = 0; i < 38; i++)
    {
        this->match_schedule[i]=0;
    }
    
}

void Team::Set_team_skill(double ns){
    if(ns>100||ns<0){
        throw runtime_error("Team skill is between 0-100");
    }
    team_skill=ns;
    }
void Team::set_team_name(std::string nn){
        this->team_name=nn;
    }

void Team::book_match(int round,int desicson){
    this->match_schedule[round]=desicson;
}

bool Team::is_booked(int round){
    if(this->match_schedule[round]==1){
        return true;
    }
    return false;
}

ostream &operator<<(std::ostream &COUT, Team& T1){
    COUT<<T1.Get_team_name()<<" Skill"<< T1.Get_team_skill()<<"\n";
    return COUT;
}