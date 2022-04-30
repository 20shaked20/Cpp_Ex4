/**
 * @file Player.hpp
 * @author shaked levi
 * @brief this is the header file for the player class 
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
#include "Game.hpp"

namespace coup{

    class Player{
        
        private:
        unsigned int _coins = 0;
        std::string _name;
        Game _game;

        public:

        /**
         * @brief Construct a new Player object
         * 
         * @param name a user name
         */
        Player();

        /**
         * @brief Destroy the Player object
         * 
         */
        ~Player();
        
        /**
         * @brief Takes one coin from the pile.
         * this operand cannot be countered and costs nothing.
         */
        void income();

        /**
         * @brief Takes two coins from the pile.
         * this operand can be blocked via other roles, in case the player is blocked his turn ends immediatly.
         */
        void foreign_aid();

        /**
         * @brief Kicks a player from the game.
         * it costs 7 coins to initate, cannotc be blocked.
         */
        virtual void coup(Player &player);

        /**
         * @brief Returns the players role in detail.
         * 
         * @return std::string 
         */
        virtual std::string role();

        /**
         * @brief returns the name of the player.
         * 
         * @return std::string 
         */
        const std::string name();

        /**
         * @brief Returns the amount of coins the player has at the moment.
         * 
         * @return unsigned int 
         */
        const unsigned int coins();


    };

}