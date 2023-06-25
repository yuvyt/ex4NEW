#include "BattleCard.h"

BattleCard::BattleCard()
{
    m_name ="";
    m_cardForce = 0;
    m_loot= 0;
    m_damage= 0;
}


void BattleCard::printMonsterCard(std::ostream& os, bool isDragon) const
{
    if(!isDragon)
    {
        printCardDetails(os, this->m_name);
        printMonsterDetails(os,this->m_cardForce, this->m_damage,this->m_loot, false);
        printEndOfCardDetails(os);
    }
    else
    {
        printCardDetails(os, this->m_name);
        printMonsterDetails(os,this->m_cardForce, 0 ,this->m_loot, true);
        printEndOfCardDetails(os);
    }
}