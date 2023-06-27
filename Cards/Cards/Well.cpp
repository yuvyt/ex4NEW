#include "Well.h"

Well::Well()
{
    m_name = "Well";
    m_healthPointsLoss = 10;
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

// std::ostream& operator<<(std::ostream& os, const Well& well) 
// {
//     well.printRegularCard(os);
// }