#ifndef MANA_H
#define MANA_H

#include "Card.h"
#include "../utilities.h"

const int HEALTH_POINTS_TO_ADD = 10;

class Mana : public Card {
private:
    int m_healthPoints;

public:
    /* c'tor for Mana, initializaing to the default const values*/
    Mana();
    /*overloads the applyEncounter function in Card and
    implements a new version for it specifically when encountering 
    Mana card*/
    void applyEncounter(Player &player) const override;
    /*cloning a mana card*/
    Card *clone() const override;
    /*defining the d'tpr as default */
    ~Mana() = default;
};

#endif
