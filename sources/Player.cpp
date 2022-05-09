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

coup::Player::Player(Game &game, std::string const& name){

    this-> _game = &game;
    this->_game->_player_count++;

    if(_game->is_on){

        std::__throw_logic_error("Game already started cannot join");
    }

    if(_game->_player_count > six){

        this->_game->_player_count--;
        std::__throw_logic_error("Game cannot have more than six players");

    }

    this-> is_blocked = false;
    this-> is_alive = true;
    this-> _coins = 0;
    this-> _last_action = "Default";
    this-> _name = name ;
    this-> _role = "Default" ;
    this->_game->_players.push_back(name); /*check for ref*/

}

coup::Player::~Player(){}

void coup::Player::income(){
    
    if(_game->_player_count < two){
        
        std::__throw_logic_error ("Game cannot start with one guy");
    }
    is_my_turn(); 

    if(this->coins() > ten){
        std::__throw_logic_error ("You have more than 10 coins, must coup");
    }

    this->_last_action = "income";  
    this->_coins++;
    this->_game->_turn++;
    this->_game->is_on = true;
    
}

void coup::Player::foreign_aid(){
    
    if(_game->_player_count < two){
        
        std::__throw_logic_error ("Game cannot start with one guy");
    }

    is_my_turn();

    if(this->coins() > ten){
        std::__throw_logic_error ("You have more than 10 coins, must coup");
    }
        
    this->_last_action = "foreign_aid";
    this->_coins+=two;
    /*advance turn*/
    this->_game->_turn++;
    this->_game->is_on = true;
    
}

void coup::Player::coup(Player &player){
    
    is_my_turn();

    if(!player.is_alive){
        std::__throw_logic_error ("Player is dead, cannot coup");
    }
    
    if(this->coins() < seven){
        
        if(this->role() != "Assassin"){

            std::__throw_invalid_argument ("Habibi you dont have enough coins...\n");
        }

    }

    if(this->coins() < three && this->role() == "Assassin"){
        throw "Assassin does not have enough coins...\n";
    }
    
    this->_last_action = "coup";
    this->_coins-=seven; /*erase 7 coins costs to coup*/

    
    for(std::size_t i = 0; i<_game->_players.size();++i) {
            
        if(_game->_players.at(i) == player.name()){
            _game->_players.at(i) = "*"+player.name(); /*check this for player vector*/
            _game->_player_count--;
            break;
        }
    }
    player.is_alive = false;
    this->_game->_turn++;
}

std::string coup::Player::role(){

    return this->_role;

}

std::string coup::Player::name() const {

    return this->_name;

}

int coup::Player::coins() const {

    return this->_coins;

}

bool coup::Player::is_my_turn() const {

    if(_game->turn() != name()){
        std::__throw_invalid_argument("This is not your turn to do this operations.");
    }
    return true;

}



