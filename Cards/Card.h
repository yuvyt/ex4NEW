#ifndef CARD_H
#define CARD_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum class CardType {Battle, Buff, Heal, Treasure}; // The type of the Card

class Card {
public:


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const =0;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card()= default;
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;


    /*
     * prints card detaiels using a function from utilities.h
    */
    virtual void printCard(std::ostream& os) const;
    

protected:
    std::string m_name;
    
    //CardType m_effect;
    //CardStats m_stats;

};

std::ostream& operator<<(std::ostream& os, const Card& card);


#endif 