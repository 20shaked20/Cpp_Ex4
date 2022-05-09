/**
 * @file Ambassador.cpp
 * @author shaked levi
 * @brief this is the Ambassador class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Ambassador.hpp"
#include "Captain.hpp"

coup::Ambassador::Ambassador(coup::Game &game, const std::string &name): Player(game,name){
    this->_role = "Ambassador";
}

coup::Ambassador::~Ambassador(){}

void coup::Ambassador::transfer(Player &p1, Player&p2){
    
    this->is_my_turn();

    if(p1.coins() == 0){

        std::__throw_logic_error( "player 1 has zero coins, cannot make transfer... \n");
        
    }
    p1._coins--;
    p2._coins++;
    
    this->_game->_turn++;

}

void coup::Ambassador::block(Player &player){

    Captain *c = dynamic_cast<Captain*> (&player); 

    if(c->_last_action != "steal"){

        std::__throw_invalid_argument ("Ambassador can block only the steal operation");

    }    
    c->is_blocked = true;
    c->steal(*c->player_on_action);

}

std::string coup::Ambassador::role(){

    return this->_role;
    
}



