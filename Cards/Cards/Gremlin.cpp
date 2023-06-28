#include "Gremlin.h"


Gremlin::Gremlin()
{
    m_name = "Gremlin";
    m_cardForce = CARD_FORCE;
    m_loot = LOOT;
    m_damage = HEALTH_POINTS_ON_LOSS;
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
