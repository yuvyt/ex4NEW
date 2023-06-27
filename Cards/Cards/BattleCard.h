#ifndef BATTLECARD_H
#define BATTLECARD_H

#include "Card.h"
#include <string>

const std::string STRING_DEFAULT = "";
const int INT_DEFAULT = 0;

class BattleCard: public Card
{
protected:
    int m_cardForce;
    int m_loot;
    int m_damage;

public:
	/*
    * coloning a battle card ,should be overridden 
    */
    virtual BattleCard* clone() const=0;
    /*
    * defaul constructor for battke Card
    */
    BattleCard();
    /* overrides the function from Card and expects those inheriting
     from it to implement it
    */
    virtual void applyEncounter(Player& player) const =0;
    /*
    * prints monster card detaiels using a function from utilities.h
    */
    void printMonsterCard(std::ostream& os, bool isDragon) const;

    /*prints card deatails usinf  functoion from utilities
    */
    virtual void printCard(std::ostream& os) const =0;
    /*
    * setting the d'tor to default 
    */
    ~BattleCard() = default;
};

#endif 