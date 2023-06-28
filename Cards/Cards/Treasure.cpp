#include "Treasure.h"

Treasure::Treasure()
{
    m_name = "Treasure";
    m_treasure = TREASURE_COINS;
}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(m_treasure);
    printTreasureMessage();
}

Card* Treasure::clone() const {
    return new Treasure(*this);
}

