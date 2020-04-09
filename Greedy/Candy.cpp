/*
 * There are N children standing in a line. Each child is assigned a rating
 * value. You are giving candies to these children subjected to the following
 * requirements:
 *      1. Each child must have at least one candy.
 *      2. Children with higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *
 * Date: 04/08/2020
 * Author: Wei Du
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() <= 1) return ratings.size();
        std::vector<int> candies(ratings.size(), 1);
        int len(ratings.size() - 1);

        for (int i = 1; i <= len; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int rlt = std::accumulate(candies.begin(), candies.end(), 0);
        return rlt;
    }
};
