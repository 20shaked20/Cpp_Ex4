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

coup::Assassin::Assassin(coup::Game &game, const std::string &name) : Player(game,name){

    this->_role = "Assassin";
    this->player_on_action = NULL;

}

coup::Assassin::~Assassin(){}

void coup::Assassin::coup(Player &player){
    
    this->player_on_action = &player;
    

    if(this->coins() < 3 && !this->is_blocked){
        std::__throw_invalid_argument( "Not enough coins for assassin");
    }

    if(this->coins() >= seven && !this->is_blocked){
        this->_last_action = "coup";
        this->coup::Player::coup(player);

    }
    else if(this->coins() >= three && !this->is_blocked){
        this->_coins+=four; /*in order to avoid code reusment*/
        this->coup::Player::coup(player);
        this->_last_action = "coup3";

    }else if(this->is_blocked){

        // this->_coins+=three; /*return the money to the assassin*/
        
        for(std::size_t i = 0; i<_game->_players.size();++i) { 
            
            if(_game->_players.at(i) == ("*"+player.name())){
                _game->_players.at(i) = player.name(); /*check this for player vector*/
                _game->_player_count++;
                break;
            }
        }
            this->is_blocked = false;
            this->player_on_action->is_alive = true; /*revive player*/        
    }
}

std::string coup::Assassin::role(){

    return this->_role;
}



