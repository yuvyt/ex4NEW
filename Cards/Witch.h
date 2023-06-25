#ifndef WITCH_H
#define WITCH_H



#include "BattleCard.h"

class Witch: public BattleCard
{
    private:
    int m_powerLoss;
    public:
        Witch();
        void applyEncounter(Player& player) const override;
        void printCard(std::ostream& os) const override;
    
};


#endif 