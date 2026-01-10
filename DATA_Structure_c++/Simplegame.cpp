#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef stack<string> Deck;
typedef list<string> Players;

Deck createShuffledDeck() {
    vector<string> cards;

    for (int i = 0; i < 22; ++i) cards.push_back("Safe");
    for (int i = 0; i < 3; ++i) cards.push_back("Bomb");

    srand(time(0));  // Seed rand()

    // Fisher-Yates shuffle
    for (int i = cards.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(cards[i], cards[j]);
    }

    Deck deck;
    for (const auto& card : cards) deck.push(card);
    return deck;
}

bool drawCard(Deck& deck, const string& player) {
    cout << player << ", press Enter to draw a card...";
    cin.get();  // Wait for user input

    if (deck.empty()) {
        cout << "The deck is empty! No more cards to draw.\n";
        return false;
    }

    string card = deck.top();
    deck.pop();
    cout << player << " drew: " << card << "\n";
    return card != "Bomb";
}

int main() {

    
    
    
    
    

    const int numPlayers = 4;
    Players players;
    string name;

    for (int i = 1; i <= numPlayers; ++i) {
        cout << "Enter the name of Player " << i << ": ";
        getline(cin, name);
        players.push_back(name);
    }

    Deck deck = createShuffledDeck();
    cout << "\nGame starts! The last player standing wins!\n\n";

    Players::iterator currentPlayer = players.begin();
    while (players.size() > 1) {
        cout << "Cards remaining: " << deck.size() << "\n";

        if (deck.empty()) {
            cout << "The deck is empty! No winner this round.\n";
            return 0;
        }

        if (!drawCard(deck, *currentPlayer)) {
            cout << *currentPlayer << " has been eliminated!\n";
            currentPlayer = players.erase(currentPlayer);
        } else {
            ++currentPlayer;
        }

        if (currentPlayer == players.end()) {
            currentPlayer = players.begin();
        }
    }

    cout << "\nCongratulations " << players.front() << "! You are the winner!\n";
    return 0;
}
