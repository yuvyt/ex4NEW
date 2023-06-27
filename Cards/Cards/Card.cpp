#include "../utilities.h"
#include "Card.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;



// should this stay?

void Card::printCard(std::ostream& os) const
{
    printCardDetails(os,this->m_name);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printCard(os);
    return os;
}

