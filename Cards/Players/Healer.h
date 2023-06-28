#ifndef _H
#define _H



#include "Player.h"

class Healer : public Player
{
public:
    /*c'tor for Healer
    @param:playerName: the name of the player */
    Healer(const std::string& playerName);
    /*overloding the heal function from player, so it
    will heal the healer more
    @param:HealthPointsToAdd: amount of original health point to add */
    void heal(int HealthPointsToAdd) override;
    /*cloning the player*/
    Player* clone() const override;
    /*setting the d'tpr to default*/
    ~Healer() = default;
};


#endif
