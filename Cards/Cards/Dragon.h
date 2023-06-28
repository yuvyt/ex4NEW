#ifndef DRAGON_H
#define DRAGON_H


const int HEALTH_POINTS_ON_LOSS = 0; //Dragon burns the loser and takes all it's health points
const int CARD_FORCE = 25;
const int LOOT = 1000;

#include "BattleCard.h"

class Dragon: public BattleCard
{
    public:
        /* c'tor for Dragon, initializaing to the default const values*/
        Dragon();
        /*overloads the applyEncounter function in Card and
        implements a new version for it specifically when encountering 
        Dragon card*/
        void applyEncounter(Player& player) const override;
        /*overloads the printCard function in Card and
        implements a new version for it specifically when printing 
        Dragon card*/
        void printCard(std::ostream& os) const override;
        /*defining the d'tpr as default */
        ~Dragon() = default;
};

#endif
