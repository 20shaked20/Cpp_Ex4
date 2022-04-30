/**
 * @file Ambassador.hpp
 * @author shaked levi
 * @brief header file for the ambassador class role.
 * @version 0.1
 * @date 2022-04-28
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

    class Ambassador : public Player{

        private:

        public:
        
        /**
         * @brief Construct a new Ambassador object
         * 
         * @param game 
         * @param name 
         */
        Ambassador(Game &game, const std::string &name);

        /**
         * @brief Destroy the Ambassador object
         * 
         */
        ~Ambassador();
        
        /**
         * @brief takes one coin from player 'x' and transfers it to player 'y'.
         * 
         */
        void transfer(Player &p1, Player &p2);

        /**
         * @brief allows blocking the theft operation applied by the captain.
         * 
         */
        void block(Player &player);

        /**
         * @brief Returns the Ambassador role in detail.
         * 
         * @return std::string 
         */
        virtual std::string role();
    };

}