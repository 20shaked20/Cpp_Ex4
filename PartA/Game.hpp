/**
 * @file Game.hpp
 * @author shaked levi
 * @brief this is the header file for the game class.
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace coup{

    class Game{

        public:
        std::vector<std::string> _players;
        int _turn;
        int _player_count;

        public:

        /**
         * @brief Construct a new Game object
         * 
         */
        Game();

        /**
         * @brief Destroy the Game object
         * 
         */
        ~Game();

        /**
         * @brief "Prints" the current player turn.
         * 
         * @return std::string the player name.
         */
        std::string turn();

        /**
         * @brief "Prints" the active players in a pretty way : ["Moshe" 
         *                                                       "Shaked"]...
         * 
         * @return std::string
         */
        std::vector<std::string> players();


        /**
         * @brief Can invoke only when there's a winner, othe wise will throw err.
         * 
         * @return std::string -> winners name.
         */
        std::string winner();

    };
}