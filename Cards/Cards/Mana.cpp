#include "Mana.h"


Mana::Mana()
{
    m_name = "Mana";
    m_healthPoints = HEALTH_POINTS_TO_ADD;
}

void Mana::applyEncounter(Player& player) const
{
    if(player.stringType() == "Healer")
    {
        player.heal(m_healthPoints);
        printManaMessage(true);
    }
    else
    {
        printManaMessage(false);
    }
}

Card* Mana::clone() const {
    return new Mana(*this);
}

