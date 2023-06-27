#include "Gremlin.h"
// using std::cout;

Gremlin::Gremlin()
{
    m_name = "Gremlin";
    m_cardForce = 5;
    m_loot = 2;
    m_damage = 10;
}
void Gremlin::applyEncounter(Player& player) const
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
        printLossBattle(player.getName(), m_name);
    }
}

void Gremlin::printCard(std::ostream& os) const
{
    this->printMonsterCard(os, false);
}
BattleCard* Gremlin::clone() const {
    return new Gremlin(*this);
}
// std::ostream& operator<<(std::ostream& os, const Gremlin& gremlin) 
// {
//     gremlin.printMonsterCard(os, false);
// }