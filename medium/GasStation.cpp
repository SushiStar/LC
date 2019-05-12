/*
 * There are N gas stations along a circular route, where the amount
 * of gas at station i is gas[i]].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of
 * gas to travel from station i to its next station i+1. You begin the
 * journey with an empty tank at one of the stations.
 * Return the starting gas station's index if you can travel around the
 * circuit once in the clockwise direction, otherwise return -1.
 *
 * If there exists an solution, it is guaranteed to be unique.
 * Both input arrays are non-empty and have the same length.
 * Each element in the input arrays is a non-negative integer.
 *
 * Date: May/12/2019
 * Author: Wei Du
 */
#include <vector>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int counter(0), gasc(0), costc(0), start(0);
        int curr(0), num(gas.size());
        while (counter < num &&start < num) {
            gasc += gas[curr];
            costc += cost[curr];
            ++counter;
            ++curr;
            curr = curr < num ? curr : curr - num;
            while (gasc < costc && start < num) {
                gasc -= gas[start];
                costc -= cost[start];
                --counter;
                ++start;
            }
        }
        return counter < num  ? -1 : start;
    }
};


