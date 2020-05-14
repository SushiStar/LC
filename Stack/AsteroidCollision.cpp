/*
 * We are given an array asteroids of integers representing asteroids
 * in a row. For each asteroid, the absolute value represents its size,
 * and the sign represents the direction (positive meaning right, negative
 * meaning left). Each asteroid moves at the same speed.
 * Find out the state of asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both
 * will explode. Two asteroids moving in the same direction will never
 * meet.
 *
 * Date: 05/13/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        if (asteroids.size() < 2) return asteroids;
        std::vector<int> stk;
        for (int i = 0; i < asteroids.size(); ++i) {
            while (!stk.empty() && stk.back() > 0 &&
                   stk.back() < -asteroids[i]) {
                stk.pop_back();
            }
            if (!stk.empty() && stk.back() > 0 && asteroids[i] < 0) {
                if (stk.back() + asteroids[i] == 0) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(asteroids[i]);
            }
        }
        return stk;
    }
};
