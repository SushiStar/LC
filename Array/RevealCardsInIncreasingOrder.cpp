/*
 * In a deck of cards, every card has a unique integer. You can order
 * the deck in any order you want.
 * Initially, all the cards start face down (unrevealed) in one deck.
 *
 * Now, you do the following steps repeatedly, until all cards are revealed.
 * 1. Take the top card of the deck, reveal it, and take it out of the deck.
 * 2. If there are still cards in the deck, put the next top card at the
 * bottom of the deck.
 * 3. If there are still unrevealed cards, go back to step 1. Otherwise stop.
 *
 *
 * Return an ordering of the deck that would reveal the cards in increasing
 * order. The first entry in the answer is considered to be the top of the deck.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        if (deck.size() < 2) return deck;
        std::sort(deck.begin(), deck.end(), std::greater<int>());
        std::deque<int> buffer;
        buffer.push_back(deck[0]);
        for (int i = 1; i < deck.size(); ++i) {
            auto bk = buffer.back();
            buffer.pop_back();
            buffer.push_front(bk);
            buffer.push_front(deck[i]);
        }
        return std::vector<int>(buffer.begin(), buffer.end());
    }
};
