#include "Barfight.h"

Barfight::Barfight()
{
    m_name = "Barfight";
    m_healthPointsLoss = HEALTH_POINTS_ON_LOSS;
}

void Barfight::applyEncounter(Player& player) const
{
    if(player.stringType() == "Warrior")
    {
        printBarfightMessage(true);
    }
    else
    {
        player.damage(m_healthPointsLoss);
        printBarfightMessage(false);
    }
}

Card* Barfight::clone() const {
    return new Barfight(*this);
}
