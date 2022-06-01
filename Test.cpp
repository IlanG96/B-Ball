#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "Schedule.hpp"
#include "Leauge.hpp"
#include "Team.hpp"
#include "Game.hpp"
using namespace std;


TEST_CASE("Create a Random League")
{
    Leauge randomL{};
    CHECK_EQ(randomL.get_teams().size(),20);
    Schedule games(&randomL);
    CHECK_EQ(games.League_rounds(),38);
}

TEST_CASE("Create a League with a Schedule class"){
    Schedule test{};
    CHECK_EQ(test.League_rounds(),38);
    CHECK_EQ(test.get_League()->get_teams().size(),20);
    for(int round=1;round<=38;round++){
        for(auto team1: test.get_League()->get_teams()){
            CHECK(team1->is_booked(round)==1);
        }    
    }
}

