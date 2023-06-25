#include "Card.h"
#include "Merchant.h"
#include <string>
using std::cout;
using std::cin;

Merchant::Merchant()
{
    m_name = "Merchant";
    m_healthPoints = 1;
    m_healthPointsPrice = 5;
    m_forcePoints = 1;
    m_forcePointsPrice = 10;
}

void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    bool validInput = 0;
    std::string choise;
    int purchaseMode;
    while (!validInput)
    {
        getline(cin, choise);
        purchaseMode = std::stoi(choise);
        if ((purchaseMode !=0) && (purchaseMode !=1) && (purchaseMode !=2))
        {
            printInvalidInput();
        }
        else
        {
            validInput = 1;
        }

    }
    if (purchaseMode == 1)
    {
        if (player.getCoins() >= m_healthPointsPrice)
        {
            applyMerchantHrealthEncounter(player);
            printMerchantSummary(std::cout, player.getName(), 1, m_healthPointsPrice);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }

    if(purchaseMode == 2)
    {
        if (player.getCoins() >= m_forcePointsPrice)
        {    
            applyMerchantForceEncounter(player);
            printMerchantSummary(std::cout, player.getName(), 2, m_forcePointsPrice);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }

    if(purchaseMode ==0)
    {
        printMerchantSummary(std::cout, player.getName(), 0, m_forcePointsPrice);
    }
    
    

}


void Merchant::applyMerchantHrealthEncounter(Player& player) const 
{
    player.pay(m_healthPointsPrice);
    player.heal(m_healthPoints);
}

void Merchant::applyMerchantForceEncounter(Player& player) const 
{
    player.pay(m_forcePointsPrice);
    player.buff(m_forcePoints);
}

// std::ostream& operator<<(std::ostream& os, const Merchant& merchant) 
// {
//     merchant.printRegularCard(os);
// }