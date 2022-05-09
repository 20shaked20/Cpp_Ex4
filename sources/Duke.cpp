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

coup::Duke::Duke(coup::Game &game, const std::string &name) : Player(game,name) {
    this->_role = "Duke";
}

coup::Duke::~Duke(){}

void coup::Duke::block(Player &player){

    if(player._last_action != "foreign_aid"){

        std::__throw_invalid_argument("Duke can block only the foreign_aid operation");

    }else{
        
        // player.is_blocked = true;
        player._coins-=2;
    }

}

void coup::Duke::tax(){
    
    this->is_my_turn();
    
    this->_coins+=three;
    this->_game->_turn++;

}

std::string coup::Duke::role(){
    return this->_role;
}



