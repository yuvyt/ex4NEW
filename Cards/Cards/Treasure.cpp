#include "Treasure.h"

Treasure::Treasure()
{
    m_name = "Treasure";
    m_treasure =10;
}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(m_treasure);
    printTreasureMessage();
}

Card* Treasure::clone() const {
    return new Treasure(*this);
}

// std::ostream& operator<<(std::ostream& os, const Treasure& treasure) 
// {
//     treasure.printRegularCard(os);
// }

// std::ostream& operator<<(std::ostream& os, const Well& well) 
// {
//     well.printRegularCard(os);
// }