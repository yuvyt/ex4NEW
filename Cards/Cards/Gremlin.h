#ifndef GREMLIN_H
#define GREMLIN_H



#include "BattleCard.h"

class Gremlin: public BattleCard
{
public:
    Gremlin();
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    BattleCard* clone() const override;
};

#endif 