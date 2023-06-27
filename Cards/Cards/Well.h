#ifndef WELL_H
#define WELL_H


#include "Card.h"
#include "../utilities.h"

class Well : public Card
{
private:
    int m_healthPointsLoss;

public:
    Well();
    void applyEncounter(Player& player) const override;
    Card* clone() const override;

};


#endif 