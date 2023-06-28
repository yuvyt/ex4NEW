#include "BattleCard.h"

BattleCard::BattleCard()
{
    m_name =STRING_DEFAULT;
    m_cardForce = INT_DEFAULT;
    m_loot= INT_DEFAULT;
    m_damage= INT_DEFAULT;
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
