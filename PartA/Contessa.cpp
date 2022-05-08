/**
 * @file Contessa.cpp
 * @author shaked levi
 * @brief this is the Contessa class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Contessa.hpp"
#include "Assassin.hpp"

coup::Contessa::Contessa(coup::Game &game, const std::string &name){

    this->_name = name;
    this->_game = &game;
    this->_game->_players.push_back(name); /*check for ref*/
    this->_game->_player_count++;
    this->_role = "Contessa";
    this->_coins = 0;
}

coup::Contessa::~Contessa(){}

void coup::Contessa::block(Player &player){

    // Assassin *a = (Assassin*) &player;

    if(player._last_action != "coup3"){

        std::__throw_invalid_argument("Contessa can block only the coup3 operation");

    }else{
        
        player.is_blocked = true;
        // a->coup(a->player_on_action);
    }

}

std::string coup::Contessa::role(){
    return this->_role;
}



