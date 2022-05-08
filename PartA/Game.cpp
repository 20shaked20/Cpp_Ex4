/**
 * @file Game.cpp
 * @author shaked levi
 * @brief this is the Game class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Game.hpp"

coup::Game::Game(){

    // std::vector<std::string> _players
    this->_turn = 0;
    this->_player_count = 0;

}

coup::Game::~Game(){}

std::string coup::Game::turn(){

    return this->_players.at((unsigned long)(this->_turn%this->_player_count));

}

std::vector<std::string> coup::Game::players(){ /*check this*/

    return this->_players;

}

std::string coup::Game::winner(){

    if(this->_player_count > 1){
        throw "Game is not over yet...\n";
    }
    else{

        return this->_players.at(0);
    }

}



