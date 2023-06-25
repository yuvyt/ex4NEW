#include "Barfight.h"

Barfight::Barfight()
{
    m_name = "Barfight";
    m_healthPointsLoss = 8;
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

// std::ostream& operator<<(std::ostream& os, const Barfight& barFight) 
// {
//     barFight.printRegularCard(os);
// }