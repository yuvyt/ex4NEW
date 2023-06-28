#ifndef WARRIOR_H
#define WARRIOR_H



#include "Player.h"


class Warrior : public Player
{
    public:

        /*c'tor for warrior
        @param:playerName: the name of the player */
        Warrior(const std::string& playerName);
        /*getAttackStrength returns players current strength
        * calculated by the sum of his kevek and his force */
        int getAttackStrength() const;
         /*setting the d'tpr to default*/
        ~Warrior() = default;

};


#endif 
