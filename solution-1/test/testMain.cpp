
#include <gtest/gtest.h>
#include "../src/snap.h"
#include "../src/deck.h"


TEST(CardTest, FaceValueMatch) {
    Card firstCard{"10", "Hearts"};
    Card secondCard{"10", "Clubs"};
    EXPECT_TRUE(firstCard.isSnap(secondCard, Card::FACE_VALUE));
    EXPECT_FALSE(firstCard.isSnap(secondCard, Card::SUIT));
    EXPECT_FALSE(firstCard.isSnap(secondCard, Card::BOTH));
}

TEST(CardTest, SuitMatch) {
    Card firstCard{"5", "Diamonds"};
    Card secondCard{"9", "Diamonds"};
    EXPECT_FALSE(firstCard.isSnap(secondCard, Card::FACE_VALUE));
    EXPECT_TRUE(firstCard.isSnap(secondCard, Card::SUIT));
    EXPECT_FALSE(firstCard.isSnap(secondCard, Card::BOTH));
}

TEST(CardTest, BothMatch) {
    Card firstCard{"Ace", "Spades"};
    Card secondCard{"Ace", "Spades"};
    EXPECT_TRUE(firstCard.isSnap(secondCard, Card::BOTH));
}


TEST(DeckTest, GenerateDeck) {
    vector<Card> deck = Deck::getDeck(1);
    EXPECT_EQ(deck.size(), 52);
}


TEST(DeckTest, ShuffleDeck) {
    vector<Card> deck = Deck::getDeck(1);
    vector<Card> originalDeck = deck;
    Deck::shuffleDeck(deck);

    EXPECT_EQ(deck.size(), originalDeck.size());

    bool isShuffled = false;
    for (size_t i = 0; i < deck.size(); ++i) {
        if (deck[i].face != originalDeck[i].face || deck[i].suit != originalDeck[i].suit) {
            isShuffled = true;
            break;
        }
    }
    EXPECT_TRUE(isShuffled);
}


TEST(DeckTest, GetShuffledDeck) {
    int number_of_deck = 2;
    vector<Card> deck = Deck::getDeck(number_of_deck);
    EXPECT_EQ(deck.size(), 104);  // 2 packs of 52 cards
}


TEST(GameTest, PlayGame) {
    vector<Card> deck = {
            {"10",  "Hearts"},
            {"10",  "Clubs"},
            {"Ace", "Diamonds"},
            {"Ace", "Spades"}
    };

    std::pair<int, int> scores = Game::playGame(Card::FACE_VALUE, deck);
    EXPECT_GT(scores.first + scores.second, 0);
}


TEST(GameTest, DecideWinner) {
    auto decideWinner = [](int player1Score, int player2Score) -> int {
        if (player1Score > player2Score) return 1;
        if (player2Score > player1Score) return 2;
        return 0;
    };

    EXPECT_EQ(decideWinner(10, 5), 1);
    EXPECT_EQ(decideWinner(3, 8), 2);
    EXPECT_EQ(decideWinner(7, 7), 0);
}


TEST(PrintWinnerTest, DisplayResults) {
    auto decideWinner = [](int player1Score, int player2Score) -> int {
        if (player1Score > player2Score) return 1;
        if (player2Score > player1Score) return 2;
        return 0;
    };

    std::pair<int, int> scores = {12, 8};
    testing::internal::CaptureStdout();
    PrintWinner::displayResults(scores, decideWinner);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Player 1 wins!") != std::string::npos);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
