#include "Game.hpp"
#include <iostream>

const int MAX_SCORE =100;
const int MIN_AWAY_SCORE=50;
const int MIN_HOME_SCORE=55;

Game::Game(Team* Home, Team* Away){
    this->Home_team=Home;
    this->Away_team=Away;
    this->Home_points = rand() % (MAX_SCORE - MIN_HOME_SCORE + 1) + MIN_HOME_SCORE;
    this->Away_points=rand() % (MAX_SCORE - MIN_AWAY_SCORE + 1) + MIN_AWAY_SCORE;
    if(this->Home_team->Get_team_skill()>this->Away_team->Get_team_skill()){
        this->Home_points +=rand() % (10 - 0 + 1) + 0;
    }
    else{
        this->Away_points+=rand() % (10 - 0 + 1) + 0;
    }
}

bool Game::did_home_won(){
    if (this->Home_points>this->Away_points)
    {
        return true;
    }
    return false;
    
}
