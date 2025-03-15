#pragma  once

#include <vector>
#include "snap.h"

using card_deck = std::vector<Card>;

class Deck {
public:
    static card_deck generateDeck();

    static void shuffleDeck(card_deck &deck);

    static card_deck getDeck(int N);
};

