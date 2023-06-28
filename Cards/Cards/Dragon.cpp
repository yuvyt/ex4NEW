#include "Dragon.h"


Dragon::Dragon()
{
    m_name = "Dragon";
    m_cardForce = CARD_FORCE;
    m_loot = LOOT;
    m_damage = HEALTH_POINTS_ON_LOSS;
}
void Dragon::applyEncounter(Player& player) const
{
    
    if(player.getAttackStrength() >= m_cardForce)
        {
            player.levelUp();
            player.addCoins(m_loot);
            printWinBattle(player.getName(), m_name);
        }
        else
        {
            player.burn();
            printLossBattle(player.getName(), m_name);
        }
}

void Dragon::printCard(std::ostream& os) const 
{
    this->printMonsterCard(os, true);
}


