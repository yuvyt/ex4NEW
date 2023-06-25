#ifndef DRAGON_H
#define DRAGON_H


 

#include "BattleCard.h"

class Dragon: public BattleCard
{
    public:
        Dragon();
        void applyEncounter(Player& player) const override;
        void printCard(std::ostream& os) const override;
};

#endif