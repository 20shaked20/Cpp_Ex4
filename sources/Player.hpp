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

int const seven = 7;
int const four = 4;
int const two = 2;
int const three = 3;
int const six = 6;
int const ten = 10;

namespace coup{
    // class game; /*check this*/
    class Player{
        
        public:
        bool is_blocked;
        bool is_alive;
        int _coins;
        std::string _last_action;
        std::string _name;
        std::string _role;
        Game *_game;

        public:

        /**
         * @brief Construct a new Player object
         * 
         * @param name a user name
         */
        Player(Game &game,std::string const& name);

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
        std::string name() const;

        /**
         * @brief Returns the amount of coins the player has at the moment.
         * 
         * @return unsigned int 
         */
        int coins() const;
        
        /**
         * @brief method to check if the current turn represent a player turn.
         * 
         * @return true 
         * @return false 
         */
        bool is_my_turn() const;


    };

}