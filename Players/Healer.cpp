#include "Player.h"
#include "Healer.h"


Healer::Healer(const std::string& playerName)
{
    m_type = PlayerType::Healer;
    m_name = playerName;
    m_coins = COINS;
    m_force = FORCE;
    m_healthPoints = MAXHEALTHPOINTS;
    m_level = LEVEL;
    m_maxHealthPoints = MAXHEALTHPOINTS;
}

void Healer::heal(int HealthPointsToAdd)
{
    m_healthPoints += 2*HealthPointsToAdd;
    if (m_healthPoints > m_maxHealthPoints)
    {
        m_healthPoints = m_maxHealthPoints;
    }
}


