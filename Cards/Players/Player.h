#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

const int FORCE = 5;
const int MAXHEALTHPOINTS = 100;
const int COINS = 10;
const int LEVEL = 1;
const int MAX_LEVEL = 10;

enum class PlayerType {
    Ninja, Healer, Warrior
};


class Player {
public:
    virtual Player* clone() const=0;
    /* @param: name: name of new player
 * @param: force: force for new player (if not received then default is 5)
 * @param: maxHealthPoints: starting HealthPoints for new player (if not received then default is 100)
 *
 * c'tor for player, making a new player according to the input given
 */
    Player(const char *name, int maxHealthPoints = MAXHEALTHPOINTS, int force = FORCE);

/*default constructor */
    Player();

    /* @param: playerToCopy: player To Copy
 *
 *  copy c'tor for player, making a new player according to the input given
 */
    Player(const Player &playerToCopy);

    /*default constructor */
    // Player () = default;

    /*defaulted destructor*/
    virtual ~Player() = default; 

    /*printInfo prints all the uniqe information the player posses */
    void printInfo() const;

    /*upgrades the players level by 1 */
    void levelUp();

    /*getLevel returns players current level */
    int getLevel() const;

    /*@param: forceToAdd: amount of force to add
*
* buff adds force points according to the input */
    void buff(int forceToAdd);

/*@param: forceToTake: amount of force to deduct
*
* removes force points according to the input */
    void forceDamage(int forceToTake);

    /*@param: HealthPointsToAdd: amount of HealthPoints to add
*
* heal adds healing points according to the input */
    virtual void heal(int HealthPointsToAdd);

    /*@param: HealthPointsToTake: amount of HealthPoints to deduct
*
* removes healing points according to the input */
    void damage(int HealthPointsToTake);

    /*
* removes all the healing points of a player */
    void burn();

    /* isKnockedOut checks if the players HealthPoints is at 0
* return true if the are*/
    bool isKnockedOut() const;

    /*@param: coinsToAdd: amount of coins to add
*
* addCoins adds coins according to the input */
    virtual void addCoins(int coinsToAdd);

    /*@param: price: amount of coins needed for transaction
*
* pay function attemps to make a purches with the players coins
* if the players has enough coins the function allows the purches,
* deducts the price from the players coins and returns true
*
*if player doesn't have enough coins the fuctions won't
*deduct coins and will return false*/
    bool pay(int price);

    /*getAttackStrength returns players current strength
* calculated by the sum of his kevek and his force */
    virtual int getAttackStrength() const;

    /*copy assignment operator*/
    Player &operator=(const Player &) = default;

    /* returns players type as a string.*/
    std::string stringType() const;

    /* returns players name as a string.*/
    std::string getName() const;

    /* returns amount of coins a player has.*/
    int getCoins() const;

    /* prints Players deatails.*/
    void printPlayer(std::ostream &os) const;


protected:
    PlayerType m_type;
    std::string m_name;
    int m_maxHealthPoints;
    int m_healthPoints;
    int m_level;
    int m_force;
    int m_coins;

};

/*overloads << operator and prints Players deatails.*/
std::ostream &operator<<(std::ostream &os, const Player &player);


#endif // PLAYER_H
