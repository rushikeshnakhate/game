#include "deck.h"

card_deck Deck::generateDeck() {
    card_deck deck;
    constexpr std::array<const char *, 4> SUITS = {"Hearts", "Diamonds", "Clubs", "Spades"};
    constexpr std::array<const char *, 13> FACES = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen",
                                                    "King", "Ace"};

    for (const auto &suit: SUITS) {
        for (const auto &face: FACES) {
            deck.emplace_back(Card{face, suit});
        }
    }
    return deck;
}

void Deck::shuffleDeck(card_deck &deck) {
    std::random_device rd;
    std::default_random_engine g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

card_deck Deck::getDeck(int N) {
    auto decks = generateDeck();
    for (int i = 0; i < N; ++i) {
        card_deck newDeck;
        decks.insert(decks.end(), newDeck.begin(), newDeck.end());
    }
    return decks;
}
