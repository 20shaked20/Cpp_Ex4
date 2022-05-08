/**
 * @file Captain.cpp
 * @author shaked levi
 * @brief this is the Captain class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Captain.hpp"

coup::Captain::Captain(coup::Game &game, const std::string &name){

    this->_name = name;
    this->_game = &game;
    this->_game->_players.push_back(name); /*check for ref*/
    this->_game->_player_count++;
    this->_role = "Captain";
    this->_coins = 0;
}

coup::Captain::~Captain(){}

void coup::Captain::steal(Player &player){

    // this->player_on_action = player; /*keeps reference to player we did the action on*/
    
    int stealing = std::min((int)player.coins(),2); /*get the minimum coins the player has*/

    if(!this->is_blocked){
        
        player._coins-=stealing;
        this->_coins+=stealing;

    }else{
        /*fix this to fit the right amount of coins*/
        player._coins+=2;
        this->_coins-=2;
    }
    
    this->_game->_turn++;

}

void coup::Captain::block(Player &player){
    
    // Captain *c = (Captain*) &player;

    if(player._last_action != "steal"){

        std::__throw_invalid_argument("Captain can block only the steal operation");

    }else{
        
        player.is_blocked = true;
        // c->steal(c->player_on_action);
        
    }

}

std::string coup::Captain::role(){

    return this->_role;
}



