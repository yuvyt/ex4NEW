#include "Well.h"

Well::Well()
{
    m_name = "Well";
    m_healthPointsLoss = HEALTH_POINTS_ON_LOSS;
}

void Well::applyEncounter(Player& player) const
{
    if(player.stringType() == "Ninja")
    {
        printWellMessage(true);

    }
    else
    {
        player.damage(m_healthPointsLoss);
        printWellMessage(false);
    }
}

Card* Well::clone() const {
    return new Well(*this);
}

