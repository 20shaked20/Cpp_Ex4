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

coup::Ambassador::Ambassador(coup::Game &game, const std::string &name){

    this->_name = name;
    this->_game = &game;
    this->_game->_players.push_back(name); /*check for ref*/
    this->_game->_player_count++;
    this->_role = "Ambassador";
    this->_coins = 0;
    

}

coup::Ambassador::~Ambassador(){}

void coup::Ambassador::transfer(Player &p1, Player&p2){

    if(p1.coins() == 0){

        throw "player 1 has zero coins, cannot make transfer... \n";
        
    }else{

        p1._coins-=1;
        p2._coins+=1;

    }
    
    this->_game->_turn++;

}

void coup::Ambassador::block(Player &player){

    // Captain *c = (Captain*) &player; 

    if(player._last_action != "steal"){

        std::__throw_invalid_argument ("Ambassador can block only the steal operation");

    }else{
        
        player.is_blocked = true;
        // c->steal(c->player_on_action);
    }

}

std::string coup::Ambassador::role(){

    return this->_role;
    
}



