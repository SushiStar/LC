/*
 * Design a data structure that supports all following operations
 * in average O(1) time.
 * 1. insert(val): Inserts an item val to the set if not already present.
 * 2. remove(val): Removes an item val from the set if present.
 * 3. getRamdom: Returns a random element from current set of elements.
 *    Each element must have the same probability of being returned.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() { std::srand(std::time(0)); }

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        mp[val] = vct.size();
        vct.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        vct[mp[val]] = vct.back();
        mp[vct.back()] = mp[val];
        mp.erase(val);
        vct.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() { return vct[std::rand() % vct.size()]; }

private:
    std::unordered_map<int, int> mp;
    std::vector<int> vct;
};
