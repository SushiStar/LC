/*
 * Shuffle a set of numbers without duplicates.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    Solution(vector<int> &nums) {
        std::swap(container, nums);
        perm = container;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return container; }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::next_permutation(perm.begin(), perm.end());
        return perm;
    }

private:
    std::vector<int> container;
    std::vector<int> perm;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
