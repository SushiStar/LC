/*
 * Implement a data structure supporting the following operations:
 *  1. Inc(Key) - Inserts a new key with value 1. Or increments an existing key
 *  by 1. Key is guaranteed to be a non-empty string.
 *  2. Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise
 *  decrements an existing key by 1. If the key does not exist, this function does 
 *  nothing. Key is guaranteed to be a non-empty string.
 *  3. GetMaxKey() - Returns one of the keys with maximal value. If no elements exists,
 *  return an empty string "".
 *  4. GetMinKey() - Returns one of teh keys with minimal value. If no elements exists, 
 *  return an empty string "".
 *
 *  Challenge: Perform all these actions in O(1) time complexity.
 *
 *  Date: 05/20/2020
 *  Author: Wei Du
 */
#include <functional>
#include <string>
#include <climits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class AllOne {
public:
    AllOne() {}
    
    void inc(string key) {
        if (mapp[key] == 0){
            mapp[key] = 1;
        } else {
            thisCount[mapp[key]].erase(key);
            ++mapp[key];
            thisCount[mapp[key]].insert(key);
            while (!maxq.empty() && thisCount[maxq.top()].empty()) {
                maxq.pop();
            }
            while (!minq.empty() && thisCount[minq.top()].empty()) {
                minq.pop();
            }
        }
        maxq.push(mapp[key]);
        minq.push(mapp[key]);
    }
    
    void dec(string key) {
        if (mapp[key] == 0) return;
        else if (mapp[key] == 1) {
            thisCount[mapp[key]].erase(key);
            mapp[key] = 0;
        } else {
            thisCount[mapp[key]].erase(key);
            --mapp[key];
            thisCount[mapp[key]].insert(key);
        }
        while (!maxq.empty() && thisCount[maxq.top()].empty()) {
            maxq.pop();
        }
        while (!minq.empty() && thisCount[minq.top()].empty()) {
            minq.pop();
        }
        if (mapp[key]) {

            maxq.push(mapp[key]);
            minq.push(mapp[key]);
        }
    }
    
    string getMaxKey() {
        if (!maxq.empty()) {
            return *(thisCount[maxq.top()].begin()); 
        }
        return "";
    }
    
    string getMinKey() {
        if (!minq.empty()) {
            return *(thisCount[minq.top()].begin());
        }
        return "";
    }
private:
    std::unordered_map<std::string, int> mapp;
    std::unordered_map<int, std::unordered_set<std::string>> thisCount;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minq;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxq;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
