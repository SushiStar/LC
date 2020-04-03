/*
 * Given a list of non negative integers, arrange them such that
 * they form the largest number.
 *
 * Date: 04/03/2020
 * Author: Wei Du
 */
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        std::string result{""};
        if (nums.empty()) return result;
        std::priority_queue<std::string, std::vector<std::string>, cmpString>
            pq;
        for (auto n : nums)
            pq.push(std::to_string(n));
        if (pq.top() == "0") {
            result = "0";
        } else {
            while (!pq.empty()) {
                result = result + pq.top();
                pq.pop();
            }
        }
        return result;
    }

private:
    struct cmpString {
        bool operator()(const std::string &s1, const std::string &s2) const {
            int idx1{0}, idx2{0};
            while (idx1 < s1.size() || idx2 < s2.size()) {
                if (idx1 >= s1.size()) idx1 -= s1.size();
                if (idx2 >= s2.size()) idx2 -= s2.size();

                if (s1[idx1] != s2[idx2]) {
                    return s1[idx1] < s2[idx2];
                }
                ++idx1;
                ++idx2;
            }
            return true;
        }
    };
};
