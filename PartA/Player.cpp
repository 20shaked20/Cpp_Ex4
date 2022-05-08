/**
 * @file Player.cpp
 * @author shaked levi
 * @brief this is the player class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Player.hpp"
#include <string.h>

coup::Player::Player(){

    this->_name = "Default";
    this->_role = "Default";
    this->_coins = 0;

}

coup::Player::~Player(){}

void coup::Player::income(){
    
    is_my_turn();   
    this->_coins+=1;
    this->_game->_turn++;
    
}

void coup::Player::foreign_aid(){
    
    is_my_turn();
    
    this->_last_action = "foreign_aid";

    if(!is_blocked){
        this->_coins+=2;
    }else{
        this->_coins-=2;
    }
    /*advance turn*/
    this->_game->_turn++;
}

void coup::Player::coup(Player &player){
    
    is_my_turn();

    this->_last_action = "coup";
    
    if(player.coins() < 7){

        throw "Habibi you dont have enough coins...\n";

    }else{
        this->_coins-=7; /*erase 7 coins costs to coup*/

        // auto itr = std::find( _game->_players.begin(),_game->_players.end(), player.name()); /*find the player name*/

        // /*erases him from the game if exists*/
        // if (itr != _game->_players.end()) {
        //     _game->_players.erase(itr);
        // }
        // player.~Player();

        for(std::size_t i = 0; i<_game->_players.size();++i) {
            
            if(_game->_players.at(i) == player.name()){
                _game->_players.at(i) = "*"+player.name(); /*check this for player vector*/
                _game->_player_count--;
                break;
            }
        }
    }
    this->_game->_turn++;
}

std::string coup::Player::role(){

    return this->_role;

}

const std::string coup::Player::name(){

    return this->_name;

}

const int coup::Player::coins() const {

    return this->_coins;

}

bool coup::Player::is_my_turn(){

    if(_game->turn() != name()){
        std::__throw_invalid_argument("This is not your turn to do this operations.");
    }
    return true;

}



