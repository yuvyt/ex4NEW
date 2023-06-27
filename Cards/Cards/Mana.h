#ifndef MANA_H
#define MANA_H


#include "Card.h"
#include "../utilities.h"

class Mana : public Card {
private:
    int m_healthPoints;

public:
    Mana();

    void applyEncounter(Player &player) const override;

    Card *clone() const override;
};

#endif