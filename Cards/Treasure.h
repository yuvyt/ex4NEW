#ifndef TREASURE_H
#define TREASURE_H



#include "Card.h"
#include "../utilities.h"

class Treasure : public Card
{
    private:
        int m_treasure;

    public:
        Treasure();
        void applyEncounter(Player& player) const;
        

};


#endif 