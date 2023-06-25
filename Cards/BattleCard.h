#ifndef BATTLECARD_H
#define BATTLECARD_H

#include "Card.h"

class BattleCard: public Card
{
    protected:
        int m_cardForce;
        int m_loot;
        int m_damage;
    
    public:
        BattleCard();
        virtual void applyEncounter(Player& player) const =0;
        /*
        * prints monster card detaiels using a function from utilities.h
        */
        void printMonsterCard(std::ostream& os, bool isDragon) const;

        /*prints card deatails usinf  functoion from utilities
        */
        virtual void printCard(std::ostream& os) const =0;
};

#endif 