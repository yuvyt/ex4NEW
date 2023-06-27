#include "Barfight.h"

Barfight::Barfight()
{
    m_name = "Barfight";
    m_healthPointsLoss = 10;
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
// std::ostream& operator<<(std::ostream& os, const Barfight& barFight) 
// {
//     barFight.printRegularCard(os);
// }