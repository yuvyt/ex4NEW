#ifndef GREMLIN_H
#define GREMLIN_H

#include "BattleCard.h"

const int HEALTH_POINTS_ON_LOSS = 10;
const int CARD_FORCE = 5;
const int LOOT = 2;

class Gremlin: public BattleCard
{
public:
    /* c'tor for Gremlin, initializaing to the default const values*/
    Gremlin();
    /*overloads the applyEncounter function in Card and
    implements a new version for it specifically when encountering 
    Gremlin card*/
    void applyEncounter(Player& player) const override;
    /*overloads the printCard function in Card and
    implements a new version for it specifically when printing 
    Gremlin card*/
    void printCard(std::ostream& os) const override;
    /*cloning a Gremlin card*/
    BattleCard* clone() const override;
    /*defining the d'tpr as default */
    ~Gremlin() = default;
};

#endif 
