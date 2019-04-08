class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto pos= nums.begin();
        while(nums.end() != nums.begin()) {
            auto buf = pos +1;
            if(nums.end() != buf) {
                if(*buf == *pos) {
                    nums.erase(buf);
                } else {
                    pos = buf; 
                }
            } else {
                return nums.size();
            }
        }
        return nums.size();
    }
};
