/**
 * @file Assassin.cpp
 * @author shaked levi
 * @brief this is the Assassin class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Assassin.hpp"

coup::Assassin::Assassin(coup::Game &game, const std::string &name){

    this->_name = name;
    this->_game = &game;
    this->_game->_players.push_back(name); /*check for ref*/
    this->_game->_player_count++;
    this->_role = "Assassin";
    this->_coins = 0;
}

coup::Assassin::~Assassin(){}

void coup::Assassin::coup(Player &player){

    // this->player_on_action = player;
    
    if(this->coins() >= 7){
        this->_last_action = "coup";
        coup::Player::coup(player);

    }
    else if(this->coins() >= 3 && !this->is_blocked){
        this->_coins+=4; /*in order to avoid code reusment*/
        coup::Player::coup(player);
        this->_last_action = "coup3";
        this->_game->_turn++;

    }else{

        this->_coins+=3; /*return the money to the assassin*/

        for(std::size_t i = 0; i<_game->_players.size();++i) { 
            
            if(_game->_players.at(i) == player.name()){
                _game->_players.at(i) = player.name(); /*check this for player vector*/
                _game->_player_count++;
                break;
            }
        }
        this->_game->_turn++;
    }

}

std::string coup::Assassin::role(){

    return this->_role;
}



