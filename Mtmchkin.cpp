#include <iostream>
#include <vector>
#include "Mtmchkin.h"
#include <fstream>
#include <memory>
#include "Players/Player.h"
#include "Exception.h"
#include "Cards/Card.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Merchant.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"

using namespace std;
using std::cout;

bool minimumLines(const std::string &fileName) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        throw DeckFileNotFound();
    }
    string line;
    int lineCount = 0;
    while (std::getline(inputFile, line)) {
        ++lineCount;
        if (lineCount >= 5) {
            inputFile.close();
            return true;
        }
    }
    return false;
}

bool legalCard(const std::string &cardName) {
    if (cardName == "Gremlin"|| cardName == "Witch"||cardName =="Dragon"||cardName=="Merchant"||cardName=="Treasure") {
        return true;
    }
    if(cardName=="Well"||cardName=="Barfight"||cardName=="Mana") {
        return true;
    }
    return false;
    
}

std::unique_ptr<Card> createCard(const std::string &cardName) {
    if (cardName == "Gremlin") {
        return std::unique_ptr<Card>(new Gremlin());
    } else if (cardName == "Witch") {
        return std::unique_ptr<Card>(new Witch());
    } else if (cardName == "Dragon") {
        return std::unique_ptr<Card>(new Dragon());
    } else if (cardName == "Merchant") {
        return std::unique_ptr<Card>(new Merchant());
    } else if (cardName == "Treasure") {
        return std::unique_ptr<Card>(new Treasure());
    } else if (cardName == "Well") {
        return std::unique_ptr<Card>(new Well());
    } else if (cardName == "Barfight") {
        return std::unique_ptr<Card>(new Barfight());
    } else if (cardName == "Mana") {
        return std::unique_ptr<Card>(new Mana());
    }
    return nullptr;  // Invalid card typ
}



int getTeamSize() {
    string input;
    int teamSize;
    bool validInput = false;
    while (!validInput) {
        std::cin >> input;
        try {
            teamSize = stoi(input);//convert string to int
            if (teamSize <= 6 && teamSize >= 2) {
                validInput = true;
            } else {
                validInput = false;
                throw InvalidTeamSize();//i should add this exceptions
            }
        } catch (...) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }
    return teamSize;
}

void createPlayer(const std::string &playerType, const std::string &playerName, deque<unique_ptr<Player>> &players) {//push all the players

    if (playerType == "Ninja") {
        players.push_back(std::unique_ptr<Ninja>(new Ninja(playerName)));
    } else if (playerType == "Healer") {
        players.push_back(std::unique_ptr<Healer>(new Healer(playerName)));
    } else if (playerType == "Warrior") {
        players.push_back(std::unique_ptr<Warrior>(new Warrior(playerName)));
    }
}



bool validPlayerType(const std::string &playerType) {
    if (playerType == "Ninja" || playerType == "Healer" || playerType == "Warrior") {
        return true;
    }
    return false;
}

bool validPlayerName(const std::string &playerName) {
    if (playerName.length() > 15) {
        return false;
    }
    for (char letter: playerName) {//check if okay
        if (letter < 'a' || letter > 'z' || letter < 'A' || letter > 'Z') {
            return false;
        }
    }
    return true;
}

bool isvalidInput(const std::string &input, deque<unique_ptr<Player>> &players) {
    int i = 0;
    while (input[i] == ' ') {
        i++;
    }
    int firstLetter = i;
    while (input[i] != ' ') {
        i++;
    }
    std::string playerName = input.substr(firstLetter, i - firstLetter);
    if (!validPlayerName(playerName)) {
        printInvalidName();
        return false;
    }
    while (input[i] == ' ') {
        i++;
    }
    int typeFirstLetter = i;
    while (input[i] != ' ') {
        i++;
    }
    std::string playerType = input.substr(typeFirstLetter, i - typeFirstLetter);
    if (!validPlayerType(playerType)) {
        printInvalidClass();
        return false;
    }
    createPlayer(playerType, playerName, players);

    return true;
}

bool numOfWords(const std::string &input) {
    int counter = 0;
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (input[i] != ' ') {
            counter++;
            while (input[i] != ' ') {
                i++;
            }
        }
    }
    if (counter != 2) {
        return false;
    }
    return true;
}

void createPlayers(int teamSize, deque<unique_ptr<Player>> &players) {
    string fullName, name, playerType;
    bool isValid = true;
    for (int i = 0; i < teamSize; i++) {
        if (isValid) {
            printInsertPlayerMessage();
        }
        getline(cin, fullName);
        if (!numOfWords(fullName)) {
            printInvalidInput();
            isValid = false;
        } else if (isvalidInput(fullName, players)) {
            isValid = true;
        } else {
            isValid = false;
        }
    }
}

Mtmchkin::Mtmchkin(const std::string &fileName) {
    std::cout << "in the buliding";
    printStartGameMessage();
    if (!minimumLines(fileName)) {
        throw DeckFileInvalidSize();
    }
    ifstream cards;
    cards.open(fileName);
    if (!cards) {
        throw DeckFileNotFound();
    }
    string line;
    int counter = 0;
    while (getline(cards, line)) {
        counter++;
        if (!legalCard(line)) {
            throw DeckFileFormatError(counter);
        }
        unique_ptr<Card> cardPtr = createCard(line);
        if (cardPtr) {
            m_cards.push_back(std::move(cardPtr)); // Push the unique_ptr to the deque   }
        }
    }
    cards.close();
    printEnterTeamSizeMessage();
    m_teamSize = getTeamSize();
    createPlayers(m_teamSize, m_players);
    std::cout << "built it";
}

bool Mtmchkin::isGameOver() const {
    int sizeLosers = m_losers.size();
    int sizeWinners = m_winners.size();

    if (sizeWinners + sizeLosers == m_teamSize) {
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numberOfRoundes;
}


//HERE!
void Mtmchkin::playRound() {
    m_numberOfRoundes++;
    printRoundStartMessage(m_numberOfRoundes);
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        Player &player = *(*it);
        if (player.getLevel() < 10 || !player.isKnockedOut()) {
            printTurnStartMessage(player.getName());
            std::unique_ptr<Card> firstCard = std::move(m_cards.front());
            m_cards.pop_front();
            firstCard->applyEncounter(player);
            m_cards.push_back(std::move(firstCard));
        }
        if (player.getLevel() == 10) {
            std::unique_ptr<Player> winner = std::move(m_players.front());
            m_players.pop_front();
            m_winners.push_back(std::move(winner));
        } else if (player.isKnockedOut()) {
            std::unique_ptr<Player> looser = std::move(m_players.front());
            m_players.pop_front();
            m_winners.push_back(std::move(looser));
        }
    }
    if (isGameOver()) {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const {
    int ranking = 1;
    printLeaderBoardStartMessage();
    for (auto it = m_winners.begin(); it != m_winners.end(); ++it) {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
    }
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
    }
    for (auto it = m_losers.begin(); it != m_losers.end(); ++it) {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
    }
}
