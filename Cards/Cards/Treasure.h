#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"
#include "../utilities.h"

const int TREASURE_COINS = 10;

class Treasure : public Card
{
private:
    int m_treasure;

public:
    /* c'tor for Treasure, initializaing to the default const values*/
    Treasure();
    /*overloads the applyEncounter function in Card and
    implements a new version for it specifically when encountering 
    Treasure card*/
    void applyEncounter(Player& player) const override;
    /*cloning a Treasure card*/
    Card* clone() const override;
    /*defining the d'tpr as default */
    ~Treasure() = default;

};


#endif 
