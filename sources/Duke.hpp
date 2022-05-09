/**
 * @file Duke.hpp
 * @author shaked levi
 * @brief header file for the Duke class role.
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
#include "Player.hpp"

namespace coup{

    class Duke : public Player{

        private: 

        public:

        /**
         * @brief Construct a new Duke role
         * 
         * @param game which game to join.
         * @param name the name of the player.
         */
        Duke(Game &game, const std::string &name);

        /**
         * @brief Destroy the Duke object
         * 
         */
        ~Duke();

        /**
         * @brief blocks the chosen player from of using the method "foriegn_aid"
         * the blocked player must return the taken coins to the pile.
         */
        static void block(Player &player);

        /**
         * @brief allows taking 3 coins from the pile without being blocked.
         * 
         */
        void tax();
        
        /**
         * @brief Returns the Duke role in detail.
         * 
         * @return std::string 
         */
        virtual std::string role();

    };
}