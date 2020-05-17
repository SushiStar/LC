/*
 * Given the array favoriteCompanies where favoriteCompanies[i] is the list of
 * favorites companies for the ith person (indexed from 0).  Return the indices
 * of people whose list of favorite companies is not a subset of any other list
 * of favorites companies. You must return the indices in increasing order.
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies) {
        std::vector<std::unordered_set<std::string>> container;
        for (auto &vct : favoriteCompanies) {
            container.push_back(std::unordered_set<std::string>(vct.begin(),vct.end()));
        }
        std::vector<int> superset(container.size(),0);
        std::iota(superset.begin(), superset.end(), 0);
        for (int i = 0; i < container.size(); ++i) {
            for (int j = i+1; j < container.size(); ++j) {
                if (container[i].size() == container[j].size()) continue;
                // do the check;
                int sidx, lidx;
                if (container[i].size() > container[j].size()) {
                    sidx = j;
                    lidx = i;
                } else {
                    sidx = i;
                    lidx = j;
                }
                // smaller size
                auto &set1 = container[sidx];
                // larger size;
                auto &set2 = container[lidx];
                if (superset[sidx] != sidx) continue;   // already a subset no need to compare
                else {
                    bool isSubset(true);
                    for (auto &s : set1) {
                        if (set2.find(s) == set2.end()) {
                            isSubset = false;
                            break;
                        }
                    }
                    if (isSubset) superset[sidx] = lidx;
                }
            }
        }
        std::vector<int> ret{};
        for (int i = 0; i < superset.size(); ++i) {
            if (superset[i] == i) ret.push_back(i);
        }
        return ret;
    }
};
