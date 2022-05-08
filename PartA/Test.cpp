/**
 * @file Test.cpp
 * @author shaked levi
 * @brief this is the tests for the project
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;


Game the_game{};

Captain captain{the_game, "priv"};
Duke duke{the_game, "gali"};
Assassin assassin{the_game, "shaked"};
Ambassador ambassador{the_game, "dekel"};
Contessa contessa{the_game, "ayelet"};
Captain captain2{the_game, "mutzi"};

std::vector<std::string> players = the_game.players();



TEST_CASE("Good inputs") {
    
    /* Checks if the playing order is correct */
    CHECK((players.at(0)) == "priv"); /*jack sparro*/
	CHECK((players.at(1)) == "gali"); /*duke*/
	CHECK((players.at(2)) == "shaked"); /*etzio*/
	CHECK((players.at(3)) == "dekel"); /* ambassador */
	CHECK((players.at(4)) == "ayelet"); /*contessa*/
	CHECK((players.at(5)) == "mutzi"); /*donkey*/

    /*first turn*/
    captain.income();
    CHECK((captain.coins()) == 1);
	CHECK((duke.coins()) == 0);
    
    /*second turn*/
    CHECK((the_game.turn()) == "gali");
	duke.tax();
	CHECK((duke.coins()) == 3);

    /*third turn*/
	CHECK((the_game.turn()) == "shaked");
	CHECK((assassin.coins()) == 0);
	assassin.foreign_aid();
	CHECK((assassin.coins()) == 2);

    /*fourth turn*/
	CHECK((the_game.turn()) == "dekel");
	CHECK((ambassador.coins()) == 0);
	CHECK((ambassador.role()) == "Can transfer coins between two players, can block the steal command");

    /*fifth turn*/
	CHECK((ambassador.name()) == "ayelet");
	CHECK((contessa.coins()) == 0);
	CHECK((contessa.role()) == "Can block assassinations declared by etzio");

    /*sixth turn*/
	CHECK((captain2.name()) == "mutzi");
    captain2.steal(captain);
    CHECK(captain2.coins() == 1 );

}

TEST_CASE("Bad inputs") {
    CHECK_THROWS(contessa.block(captain2));
    CHECK_THROWS(ambassador.block(duke)); 
}
