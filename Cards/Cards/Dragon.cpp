#include "Dragon.h"


Dragon::Dragon()
{
    m_name = "Dragon";
    m_cardForce = 25;
    m_loot = 1000;
    m_damage = 0;
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

BattleCard* Dragon::clone() const {
    return new Dragon(*this);
}

// std::ostream& operator<<(std::ostream& os, const Dragon& dragon) 
// {
//     dragon.printMonsterCard(os, true);
// }