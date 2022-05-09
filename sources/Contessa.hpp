/**
 * @file Contessa.hpp
 * @author shaked levi
 * @brief this is the header file for the Contessa class role.
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

    class Contessa : public Player{

        public:

        /**
         * @brief Construct a new Contessa object
         * 
         * @param game 
         * @param name 
         */
        Contessa(Game &game, const std::string &name);

        /**
         * @brief Destroy the Contessa object
         * 
         */
        ~Contessa();

        /**
         * @brief allows blocking the assassin 'coup' -> Assassin etzio
         * 
         */
        static void block(Player &player);

        /**
         * @brief Returns the Contessa role in detail.
         * 
         * @return std::string 
         */
        virtual std::string role();
        
    };
}