#include "Card.h"
#include "Merchant.h"
#include <string>
using std::cout;
using std::cin;

Merchant::Merchant()
{
    m_name = "Merchant";
    m_healthPoints = HEALTH_POINTS_TO_GIVE;
    m_healthPointsPrice = HEALTH_POINTS_PRICE;
    m_forcePoints = FORCE_POINTS_TO_GIVE;
    m_forcePointsPrice = FORCE_POINTS_PRICE;
}


void Merchant::applyMerchantHealthEncounter(Player& player) const
{
    player.pay(m_healthPointsPrice);
    player.heal(m_healthPoints);
}

void Merchant::applyMerchantForceEncounter(Player& player) const
{
    player.pay(m_forcePointsPrice);
    player.buff(m_forcePoints);
}
Card* Merchant::clone() const
{
    return new Merchant(*this);
}
void Merchant::applyEncounter(Player& player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    bool validInput = 0;
    std::string choise;
    int purchaseMode;
    int pay=5;
    while (!validInput) {
        getline(cin, choise);
        try {
            purchaseMode = std::stoi(choise);
        }
        catch (...) {
            printInvalidInput();
            validInput = 0;
            continue;
        }
        if ((purchaseMode != 0) && (purchaseMode != 1) && (purchaseMode != 2)) {
            printInvalidInput();
        } else {
            validInput = 1;
        }
    }
        if (purchaseMode == 1) {
            if (player.getCoins() >= m_healthPointsPrice) {
                applyMerchantHealthEncounter(player);
                printMerchantSummary(std::cout, player.getName(), 1, pay);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), 1, 0);
            }
        } else if (purchaseMode == 2) {
            if (player.getCoins() >= m_forcePointsPrice) {
                applyMerchantForceEncounter(player);
                printMerchantSummary(std::cout, player.getName(), 2, pay*2);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), 2, 0);
            }
        } else if (purchaseMode == 0) {
            printMerchantSummary(std::cout, player.getName(), 0, 0);
        }
    }

