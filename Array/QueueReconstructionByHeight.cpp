/*
 * Suppose you have a random list of people standing in a queue.
 * Each person is described by a pair of integers (h, k), where
 * h is the height of the person and k is the number of people
 * in front of this person who have a height greater than or
 * equal ot h. Write an algorithm to reconstruct the queue.
 * The number of people is less than 1100.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty() || people[0].empty()) return people;
        std::vector<std::vector<int>> ret(people.size());
        std::sort(people.begin(), people.end(), cmp());
        for (int i = 0; i < people.size(); ++i) {
            int position{0};
            int count(people[i][1]);
            while (position < people.size() && (count != 0 || !ret[position].empty())) {
                if (ret[position].empty() || ret[position][0] >= people[i][0]) --count;
                ++position;
            } 
            ret[position] = people[i];
        }
        return ret;
    }
private:
    struct cmp {
        bool operator()(std::vector<int> &v1, std::vector<int> &v2) const {
            return v1[0] < v2[0];
        }
    };
};
