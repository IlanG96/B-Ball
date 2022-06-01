
#include<vector>
#include <iostream>
#include <map>
#include "Schedule.hpp"

using namespace std;

Schedule::Schedule(){
    this->league=new Leauge();
    int round=1;
    cout<<"Size:  "<<this->league->get_teams().size()<<endl;
    for (Team * home_team : this->league->get_teams())
    {
        cout<<"Round "<<round<<endl;
        if(!home_team->is_booked(round)){
        for(Team * away_team: this->league->get_teams()){
            // cout<<*home_team<<" "<<home_team->is_booked(round)<<endl;
            // cout<<"2:  "<<*away_team<<" "<<away_team->is_booked(round)<<endl;
            if(home_team!=away_team&&!away_team->is_booked(round)&&!home_team->is_booked(round)){
                //cout<<"Home: "<<home_team->is_booked(round)<<" Away: "<<away_team->is_booked(round)<<endl;
                Game* home_game= new Game(home_team,away_team);
                Game* away_game= new Game(away_team,home_team);
                home_team->book_match(round,1);
                away_team->book_match(round,1);
                home_team->book_match(18+round,1);
                away_team->book_match(18+round,1);
                this->Leage_games[18+round].push_back(away_game);
                this->Leage_games[round++].push_back(home_game);
            }
            continue;
        }
        }
        else{
            round++;
        }
        if(round==19)
            round=1;
    } 
}

Schedule::Schedule(Leauge* newleague){
    this->league=newleague;
    int round=1;
    for (Team * home_team : this->league->get_teams())
    {
        if(!home_team->is_booked(round)){
        for(Team * away_team: this->league->get_teams()){
            if(home_team!=away_team&&!away_team->is_booked(round)){
                Game* game= new Game(home_team,away_team);
                this->Leage_games[round++].push_back(game);
                home_team->book_match(round,1);
                away_team->book_match(round,1);
            }
        }
        }
        else{
            round++;
        }
        // round=1;
    } 
}

Schedule::~Schedule(){
    for (size_t i = 1; i <= 38; i++)
    {
        for(Game* game : this->Leage_games.at(i)){
            free(game);
        }
    }
    free(this->league);
}

int Schedule::League_rounds(){
    int rounds=0;
    for (auto it=this->Leage_games.cbegin(); it != this->.Leage_games.cend(); ++it)
    {
        rounds++;
    }
    return rounds;
}

std::ostream &operator<<(std::ostream &COUT, Schedule& S1){
    for (auto it=S1.Leage_games.cbegin(); it != S1.Leage_games.cend(); ++it)
    {
        COUT<<"*******************Round "<<it->first<<" Games:******************\n";
        for(auto game:it->second){
        COUT<<game->get_home_team()<<" vs "<<game->get_away_team()<<"\n";
        }
        COUT<<"***************************************\n";
    }
    return COUT;
}