#include "Player.h"
#include "Ninja.h"


Ninja::Ninja(const std::string& playerName)
{
    m_type = PlayerType::Ninja;
    m_name = playerName;
    m_coins = COINS;
    m_force = FORCE;
    m_healthPoints = MAXHEALTHPOINTS;
    m_level = LEVEL;
    m_maxHealthPoints = MAXHEALTHPOINTS;
}

void Ninja::addCoins(int coinsToAdd)
{
    m_coins += coinsToAdd*2;
}

