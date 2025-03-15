#include "userInput.h"
#include "snap.h"

using namespace std;


std::pair<int, int> Game::playGame(int matchCondition, vector<Card> &deck) {
    vector<Card> playedCards;
    int player1Score = 0, player2Score = 0;
    int turn = 1;
    cout << "\nGame Start!\n" << endl;
    for (const Card &card: deck) {
        cout << "Player " << turn << " plays: ";
        card.print();
        cout << endl;
        if (!playedCards.empty() && card.isSnap(playedCards.back(), matchCondition)) {
            int winner = (rand() % 2) + 1;
            cout << "SNAP The Player now:" << winner << ":wins this pile!" << endl;
            if (winner == 1) {
                player1Score += playedCards.size() + 1;
            } else {
                player2Score += playedCards.size() + 1;
            }
            playedCards.clear();
        } else {
            playedCards.push_back(card);
        }
        turn = (turn == 1) ? 2 : 1;
    }
    return {player1Score, player2Score};
}

