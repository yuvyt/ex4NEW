#include "Witch.h"
// using std::cout;

Witch::Witch()
{
    m_name = "Witch";
    m_cardForce = CARD_FORCE;
    m_loot = LOOT;
    m_damage = HEALTH_POINTS_ON_LOSS;
    m_powerLoss = FORCE_POINTS_ON_LOSS;
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
