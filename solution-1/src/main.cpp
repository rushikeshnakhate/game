
#include "snap.h"
#include "userInput.h"
#include "deck.h"

extern void initializeGame(int &N, int &matchCondition, UserInputHandler &inputHandler);

int main() {
    int number_of_deck, matchCondition;
    UserInputHandler inputHandler;
    initializeGame(number_of_deck, matchCondition, inputHandler);
    auto decideWinner = [](int player1Score, int player2Score) -> int {
        if (player1Score > player2Score) return 1;
        if (player2Score > player1Score) return 2;
        return 0; // Draw
    };
    auto deck = Deck::getDeck(number_of_deck);
    Deck::shuffleDeck(deck);
    auto score = Game::playGame(matchCondition, deck);
    PrintWinner::displayResults(score, decideWinner);
    return 0;
}
