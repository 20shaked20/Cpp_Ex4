/**
 * @file Duke.cpp
 * @author shaked levi
 * @brief this is the Duke class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Duke.hpp"

coup::Duke::Duke(coup::Game &game, const std::string &name){

    this->_name = name;
    this->_game = &game;
    this->_game->_players.push_back(name); /*check for ref*/
    this->_game->_player_count++;
    this->_role = "Duke";
    this->_coins = 0;
}

coup::Duke::~Duke(){}

void coup::Duke::block(Player &player){

    if(player._last_action != "foreign_aid"){

        std::__throw_invalid_argument("Duke can block only the foreign_aid operation");

    }else{
        
        player.is_blocked = true;
        // player.foreign_aid(); 
    }

}

void coup::Duke::tax(){

    this->_coins+=3;
    this->_game->_turn++;

}

std::string coup::Duke::role(){
    return this->_role;
}



