#ifndef WITCH_H
#define WITCH_H



#include "BattleCard.h"

const int HEALTH_POINTS_ON_LOSS = 10; 
const int FORCE_POINTS_ON_LOSS = 1; 
const int CARD_FORCE = 11;
const int LOOT = 2;

class Witch: public BattleCard
{
private:
    int m_powerLoss;
public:
    /* c'tor for Witch, initializaing to the default const values*/
    Witch();
    /*overloads the applyEncounter function in Card and
    implements a new version for it specifically when encountering 
    Witch card
    @param: player: player to apply the encounter on*/
    void applyEncounter(Player& player) const override;
    /*overloads the printCard function in Card and
    implements a new version for it specifically when printing 
    Witch card
    
    @param: os: ostream to print to*/
    void printCard(std::ostream& os) const override;
    /*cloning a Witch card*/
    BattleCard* clone() const override;
    /*defining the d'tpr as default */
    ~Witch() = default;
};


#endif 
