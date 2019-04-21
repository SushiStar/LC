/*
 * Suppose you have a random list of people standing in a queue. Each
 * person is described by a pair of integers (h, k), where h is the
 * height of the person and k is the number of people in front of this
 * person who have a height greater than or equal to h. Write an algorithm
 * to reconstruct the queue.
 *
 * Solution: Pick out tallest people and sort them in arrary. Since there's
 * no other groups of people taller than them, therefore, each guy's index
 * will be just as same as its key value
 * For 2nd tallest group, insert each one of them by key value and so on.
 *
 * Note: the number of people is less than 1,100.
 *
 * Date: Apr/18/2019
 * Author: Wei Du
 */
#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    typedef std::pair<int, int> P;
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](P t1, P t2) {
            return t1.first > t2.first ||
                   (t1.first == t2.first && t1.second < t2.second);
        };
        std::sort(people.begin(), people.end(), cmp);
        std::vector<P> res;
        for (auto p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};
