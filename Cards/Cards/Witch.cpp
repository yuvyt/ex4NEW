#include "Witch.h"
// using std::cout;

Witch::Witch()
{
    m_name = "Witch";
    m_cardForce = 11;
    m_loot = 2;
    m_damage = 10;
    m_powerLoss = 1;
}
void Witch::applyEncounter(Player& player) const
{

    if(player.getAttackStrength() >= m_cardForce)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_name);
    }
    else
    {
        player.damage(m_damage);
        player.forceDamage(m_powerLoss);
        printLossBattle(player.getName(), m_name);
    }
}

void Witch::printCard(std::ostream& os) const
{
    this->printMonsterCard(os, false);
}

BattleCard* Witch::clone() const {
    return new Witch(*this);
}
// std::ostream& operator<<(std::ostream& os, const Witch& witch) 
// {
//     witch.printMonsterCard(os, false);
// }