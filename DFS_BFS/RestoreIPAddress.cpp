/*
 * Given a string containing only digits, restore it by returning all
 * possible valid IP address combinations. A valid IP address consists
 * of exactly four integers (each integer is between 0 and 255) separated
 * by single points.
 *
 * Date: 05/13/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 || s.size() < 4) return std::vector<std::string>();
        return breakDown(s, 0, 4);
    }

private:
    std::vector<std::string> breakDown(const std::string &s, int start,
                                       int segmentsLeft) {
        std::vector<std::string> ret{};
        if (start >= s.size() || (segmentsLeft == 1 && start + 3 < s.size()))
            return ret;
        if (segmentsLeft == 1 && start + 3 >= s.size()) {
            auto currSegment = s.substr(start);
            if ((currSegment.size() == 1 || currSegment[0] != '0') &&
                std::stoi(currSegment) <= 255) {
                ret.push_back(s.substr(start));
            }
        } else {
            for (int i = 1; i <= 3; ++i) {
                auto currSegment = s.substr(start, i);
                if (currSegment.size() > 1 && currSegment[0] == '0') break;
                if (std::stoi(currSegment) <= 255) {
                    auto left = breakDown(s, start + i, segmentsLeft - 1);
                    for (auto s : left) {
                        ret.push_back(currSegment + '.' + s);
                    }
                }
            }
        }
        return ret;
    }
};
