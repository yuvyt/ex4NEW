#ifndef NINJA_H
#define NINJA_H



#include "Player.h"


class Ninja : public Player
{
    public:
        /*c'tor for Ninja
        @param:playerName: the name of the player */
        Ninja(const std::string& playerName);
        /* heal adds coins according to the input */
        void addCoins(int coinsToAdd);

        /* removes healing points according to the input */
        void damage(int HPToTake);

        
};


#endif 