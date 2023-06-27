#ifndef BARFIGHT_H_H
#define BARFIGHT_H_H



#include "Card.h"
#include "../utilities.h"
const HEALTH_POINTS_ON_LOSS = 10;

class Barfight : public Card
{
private:
    int m_healthPointsLoss;

public:
	
    /* c'tor for barfight, initializaing to the default const values*/
    Barfight();
    /*overloads the applyEncounter function in Card and
    implements a new version for it specifically when encountering 
    barfight card*/
    void applyEncounter(Player& player) const override;
    /*cloning a barfight card*/
    Card *clone() const override;
    ~Barfight() = default;


};

#endif