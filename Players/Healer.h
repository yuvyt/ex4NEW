#ifndef _H
#define _H

 

#include "Player.h"

class Healer : public Player
{
    public:
        /*c'tor for Healer
        @param:playerName: the name of the player */
        Healer(const std::string& playerName);
        void heal(int HealthPointsToAdd);
};


#endif