#include "../utilities.h"
#include "Player.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;



/* @param: name: name of new player
 * @param: force: force for new player (if not received then default is 5)
 * @param: maxHealthPoints: starting HealthPoints for new player (if not received then default is 100)
 *
 * c'tor for player, making a new player according to the input given
 */
Player::Player(const char *name, int maxHealthPoints, int force)
{
    this->m_name = name;
    if(maxHealthPoints<=0){//default values
        m_maxHealthPoints=MAXHEALTHPOINTS;
        m_healthPoints=MAXHEALTHPOINTS;
    }
    else {
        m_maxHealthPoints=maxHealthPoints;
        m_healthPoints=maxHealthPoints;
    }
    if(force<=0){
        m_force= FORCE;
    }
    m_force=force;
    m_coins = COINS;
    m_level = LEVEL;
}

Player::Player()
{
    m_force= FORCE;
    m_maxHealthPoints=MAXHEALTHPOINTS;
    m_healthPoints=MAXHEALTHPOINTS;
    m_coins = COINS;
    m_level = LEVEL;
}

/* @param: playerToCopy: player To Copy
 *
 *  copy c'tor for player, making a new player according to the input given
 */
Player::Player(const Player& playerToCopy)
{
    m_name = playerToCopy.m_name;
    m_force = playerToCopy.m_force;
    m_level = playerToCopy.m_level;
    m_healthPoints = playerToCopy.m_healthPoints;
    m_maxHealthPoints = playerToCopy.m_maxHealthPoints;
    m_coins = playerToCopy.m_coins;
}




/*upgrades the players level by 1 */
void Player:: levelUp()
{
    if (m_level == MAX_LEVEL)
    {
        return;
    }
    m_level++;
}

/*getLevel returns players current level */
int Player::getLevel() const
{
    return m_level;
}

/*@param: forceToAdd: amount of force to add
*
* buff adds force points according to the input */
void Player::buff(int forceToAdd)
{
    m_force += forceToAdd;
}

/*@param: HealthPointsToAdd: amount of HealthPoints to add
*
* heal adds healing points according to the input */
void Player::heal(int HealthPointsToAdd)
{
    if (HealthPointsToAdd < 0)
    {
        return;
    }
    m_healthPoints += HealthPointsToAdd;
    if (m_healthPoints > m_maxHealthPoints)
    {
        m_healthPoints = m_maxHealthPoints;
    }
}

/*@param: forceToTake: amount of force to deduct
*
* removes force points according to the input */
void  Player::forceDamage(int forceToTake)
{
    m_force = m_force - forceToTake;
    if (m_force < 0)
    {
        m_force = 0;
    }
}

void Player::burn()
{
    m_healthPoints = 0;
}

/*@param: HealthPointsToTake: amount of HP to deduct
*
* removes healing points according to the input */
void Player:: damage(int HealthPointsToTake)
{
    if (HealthPointsToTake < 0)
    {
        return;//  i dont know if this is legal
    }
    m_healthPoints = m_healthPoints - HealthPointsToTake;
    if (m_healthPoints < 0)
    {
        m_healthPoints = 0;
    }

}

/* isKnockedOut checks if the players HealthPoints is at 0
* return true if the are*/
bool Player::isKnockedOut() const
{
    if (m_healthPoints ==0)
    {
        return true;
    }
    return false;
}

/*@param: addCoins: amount of coins to add
*
* heal adds coins according to the input */
void Player::addCoins(int coinsToAdd)
{
    m_coins += coinsToAdd;

}

/*@param: price: amount of coins needed for transaction
*
* pay function attemps to make a purches with the players coins
* if the players has enough coins the function allows the purches,
* deducts the price from the players coins and returns true
* 
*if player doesn't have enough coins the fuctions won't 
*deduct coins and will return false*/
bool Player:: pay(int price)
{
    if (m_coins < price)
    {
        return false;
    }
    m_coins -= price;
    return true;
}

/*getAttackStrength returns players current strength
* calculated by the sum of his kevek and his force */
int Player:: getAttackStrength() const
{
    return (m_force + m_level);
}

std::string Player::stringType() const
{
    if (this->m_type == PlayerType::Healer)
    {
        string type = "Healer";
        return type;
    }
    if (this->m_type == PlayerType::Warrior)
    {
        string type = "Warrior";
        return type;
    }
    if (this->m_type == PlayerType::Ninja)
    {
        string type = "Ninja";
        return type;
    }
    return " ";

}

void Player::printPlayer(std::ostream& os) const
{
    printPlayerDetails(os, this->m_name, this->stringType(), this->m_level, this->m_force, this->m_healthPoints, this->m_coins);
}


std::string Player::getName() const
{
    return this->m_name;
}


int Player::getCoins() const
{
    return m_coins;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.printPlayer(os);
    return os;
}