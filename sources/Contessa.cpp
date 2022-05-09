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

coup::Contessa::Contessa(coup::Game &game, const std::string &name): Player(game,name){

    this->_role = "Contessa";

}

coup::Contessa::~Contessa(){}

void coup::Contessa::block(Player &player){

    Assassin *a = dynamic_cast<Assassin*> (&player);

    if(player._last_action != "coup3"){

        std::__throw_invalid_argument("Contessa can block only the coup3 operation");

    }else{
        
        a->is_blocked = true;
        a->coup(*a->player_on_action);
    }

}

std::string coup::Contessa::role(){
    return this->_role;
}



