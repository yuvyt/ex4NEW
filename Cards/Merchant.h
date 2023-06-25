#ifndef MERCHANT_H
#define MERCHANT_H




#include "Card.h"
#include "../utilities.h"

class Merchant : public Card
{
    private:
        int m_healthPoints;
        int m_healthPointsPrice;
        int m_forcePoints;
        int m_forcePointsPrice;

    public:
        Merchant();
        void applyEncounter(Player& player) const;
        void applyMerchantHrealthEncounter(Player& player) const;
        void applyMerchantForceEncounter(Player& player) const;

};

#endif 

