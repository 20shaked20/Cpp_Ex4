/**
 * @file Captain.hpp
 * @author shaked levi
 * @brief the header file for the Captain class role.
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

    class Captain : public Player{
        
        // public:
        // coup::Player player_on_action;

        public:

        /**
         * @brief Construct a new Captain object
         * 
         * @param game 
         * @param name 
         */
        Captain(Game &game, const std::string &name);

        /**
         * @brief Destroy the Captain object
         * 
         */
        ~Captain();

        /**
         * @brief Steals two coins from another role player.
         * 
         */
        void steal(Player &player);

        /**
         * @brief allows blocking the 'steal' operation applied by another captain.
         * 
         */
        void block(Player &player);

        /**
         * @brief Returns the Captain role in detail.
         * 
         * @return std::string 
         */
        virtual std::string role();

    };
}