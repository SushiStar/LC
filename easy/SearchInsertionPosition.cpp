class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int middle;

        while (start <= end) {
            middle = start + (end-start) /2;
            if (nums[middle] < target) {
                start = middle+1;
            } else {
                end = middle-1;
            }

        }
        return start;
    }
};
