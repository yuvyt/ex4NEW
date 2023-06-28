#ifndef WELL_H
#define WELL_H


#include "Card.h"
#include "../utilities.h"

const int HEALTH_POINTS_ON_LOSS = 10;

class Well : public Card
{
private:
    int m_healthPointsLoss;

public:
    /* c'tor for Well, initializaing to the default const values*/
    Well();
    /*overloads the applyEncounter function in Card and
    implements a new version for it specifically when encountering 
    well card*/
    void applyEncounter(Player& player) const override;
    /*cloning a well card*/
    Card* clone() const override;
    /*defining the d'tpr as default */
    ~Well() = default;

};


#endif 
