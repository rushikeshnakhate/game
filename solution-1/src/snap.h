
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Card {
    std::string face;
    std::string suit;

    enum SnapCondition {
        FACE_VALUE, SUIT, BOTH
    };

    bool isSnap(const Card &other, int matchCondition) const {
        if (matchCondition == SnapCondition::FACE_VALUE) return face == other.face;         // Match by face value
        if (matchCondition == SnapCondition::SUIT) return suit == other.suit;           // Match by suit
        if (matchCondition == SnapCondition::BOTH) return face == other.face && suit == other.suit; // Match both
        return false;
    }

    void print() const {
        std::cout << face << " of " << suit;
    }
};


class PrintWinner {
public:
    static void displayResults(std::pair<int, int> score, const std::function<int(int, int)> &decideWinner) {
        cout << "\nGame is Over!" << endl;
        cout << "Player 1 Score: " << score.first << " cards" << endl;
        cout << "Player 2 Score: " << score.second << " cards" << endl;
        int winner = decideWinner(score.first, score.second);
        if (winner == 1) {
            cout << "Player 1 wins!" << endl;
        } else if (winner == 2) {
            cout << "Player 2 wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }
    }
};

class Game {
public:
    static std::pair<int, int> playGame(int matchCondition, vector<Card> &deck);
};