#include "Player.h"
#include "Warrior.h"


Warrior::Warrior(const std::string& playerName)
{
    m_type = PlayerType::Warrior;
    m_name = playerName;
    m_coins = COINS;
    m_force = FORCE;
    m_healthPoints = MAXHEALTHPOINTS;
    m_level = LEVEL;
    m_maxHealthPoints = MAXHEALTHPOINTS;
}

/*getAttackStrength returns players current strength
* calculated by the sum of his kevek and his force */
int Warrior::getAttackStrength() const
{
    return m_force*2 + m_level;
}

Player* Warrior::clone() const{
    return new Warrior(*this);
}