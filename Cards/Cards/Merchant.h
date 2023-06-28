#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"
#include "../utilities.h"

const int HEALTH_POINTS_TO_GIVE = 1;
const int HEALTH_POINTS_PRICE = 5;  
const int FORCE_POINTS_TO_GIVE = 1;
const int FORCE_POINTS_PRICE = 10;



class Merchant : public Card
{
private:
    int m_healthPoints;
    int m_healthPointsPrice;
    int m_forcePoints;
    int m_forcePointsPrice;

public:
    /* c'tor for Merchant, initializaing to the default const values*/
    Merchant();
    /*overloads the applyEncounter function in Card and
    implements a new version for it specifically when encountering 
    MERCHENT card*/
    void applyEncounter(Player& player) const override;
    /*function to implement the process of buing a health point*/
    void applyMerchantHealthEncounter(Player& player) const;
    /*function to implement the process of buing a force point*/
    void applyMerchantForceEncounter(Player& player) const;
    /*cloning a Merchant card*/
    Card* clone() const override;
    /*defining the d'tpr as default */
    ~Merchant() = default;
};

#endif
