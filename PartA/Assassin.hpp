/**
 * @file Assassin.hpp
 * @author shaked levi
 * @brief header file of the assassin class role.
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

    class Assassin : public Player{

        // public:
        // coup::Player player_on_action;

        public:
        
        /**
         * @brief Construct a new Assassin object
         * 
         * @param game 
         * @param name 
         */
        Assassin(Game &game, const std::string &name);
        
        /**
         * @brief Destroy the Assassin object
         * 
         */
        ~Assassin();

        /**
         * @brief Overrides the Player.coup().
         * this operation costs 3 coins instead of 7 in order to 'kill' a player
         * 
         */
        virtual void coup(Player &player);

        /**
         * @brief Returns the Assassin role in detail.
         * 
         * @return std::string 
         */
        virtual std::string role();

    };
}