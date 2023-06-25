#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <iostream>
#include <deque>
#include <memory>
#include "Cards/Card.h"
#include "Players/Player.h"


class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
    Mtmchkin(Mtmchkin&)=delete;
    void operator=(Mtmchkin&)=delete;
private:
    std::deque<std::unique_ptr<Card>> m_cards;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    int m_teamSize;
    int m_numberOfRoundes;
};


#endif /* MTMCHKIN_H_ */