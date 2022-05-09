/**
 * @file Game.cpp
 * @author shaked levi
 * @brief this is the Game class 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Game.hpp"

coup::Game::Game(){

    // std::vector<std::string> _players
    this->_turn = 0;
    this->_player_count = 0;
    this->is_on = false;

}

coup::Game::~Game(){}

std::string coup::Game::turn(){

    size_t player_at = (size_t)(this->_turn%(int)_players.size());
    while(true){  
      if(this->_players.at(player_at)[0]!='*'){
    
        return this->_players.at(player_at);
      }

      _turn++; /*skip dead people*/
      player_at = (size_t)(this->_turn%(int)_players.size());

    }

}

std::vector<std::string> coup::Game::players(){ /*check this*/

    std::vector<std::string> tmp_player;

    for(std::size_t i = 0; i<_players.size();++i) {

        if((_players.at(i))[0] != '*'){ /*dead player = "*"+name*/

            tmp_player.push_back(_players.at(i)); /*check this for player vector*/ 
        }
    }

    return tmp_player;
}

std::string coup::Game::winner(){

    if(!is_on){
        throw "Game has not started yet";
    }

    if(this->_player_count > 1){
        throw "Game is not over yet...\n";
    }
    for(std::size_t i = 0; i<_players.size();++i) {
        if((_players.at(i))[0] != '*'){ /*dead player = "*"+name*/
            return _players.at(i); /*check this for player vector*/ 
        }
    }
    return "No winner";
}



