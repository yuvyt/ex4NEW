#ifndef BARFIGHT_H
#define BARFIGHT_H_H



#include "Card.h"
#include "../utilities.h"

class Barfight : public Card
{
    private:
        int m_healthPointsLoss;

    public:
        Barfight();
        void applyEncounter(Player& player) const;
        

};

#endif 
