/*
 * Given n non-negative integers, where each represents a point at
 * coordinate i with height ai.
 * For two lines which together with x_axis forms a container, such
 * that the container contains the most water.
 *
 * Date: March/02/2019
 *
 * Author: Wei Du
 *
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea(0);

        int size = height.size();
        int left(0);
        int right(size-1);
        while (left < right) {
            int temp = (right-left) * std::min(height.at(left), height.at(right));
            if (height.at(left) < height.at(right)){
                ++left;
            } else {
                --right;
            }
            maxArea = temp>maxArea? temp : maxArea;
        }
        return maxArea;
        
    } // maxArea
}
