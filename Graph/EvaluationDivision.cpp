/*
 * Equations are given in the format A/B = k, where A and B are variables represented as strings,
 * and k is a real number (floating point number). Given some queries, return the answers. If the
 * Answer does not exist, return -1.0.
 *
 * Date: 03/27/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::vector<double> results{};
        int counter{1};
        std::unordered_map<std::string, int> mp{};
        std::vector<std::vector<double>> lookup(equations.size()*2+1,std::vector<double>(equations.size()*2+1,-1.0));
        // setup
        for (int i = 0; i < equations.size(); ++i) {
            if (mp[equations[i][0]] == 0) {
                mp[equations[i][0]] = counter;
                ++counter;
            }
            if (mp[equations[i][1]] == 0) {
                mp[equations[i][1]] = counter;
                ++counter;
            }
            lookup[mp[equations[i][0]]][mp[equations[i][1]]] = values[i];
            lookup[mp[equations[i][1]]][mp[equations[i][0]]] = 1.0/values[i];
            lookup[mp[equations[i][0]]][mp[equations[i][0]]] = 1.0;
            lookup[mp[equations[i][1]]][mp[equations[i][1]]] = 1.0;
        }
        
        // do DFS
        for (const auto &eq : queries) {
            auto start = mp[eq[0]];
            auto goal = mp[eq[1]];
            if (start == goal) {
                results.push_back(lookup[start][goal]);
                continue;
            }
            auto a = findTarget(mp,lookup,start, goal);
            auto b = findTarget(mp, lookup, goal, start);
            if (a > 0) {
                results.push_back(a);
            } else {
                results.push_back(1.0/b);
            }
            lookup[start][goal] = results.back();
            lookup[goal][start] = 1.0/results.back();               
        }
        return results;
    }
private:
    double findTarget(const std::unordered_map<std::string,int> &mp,
                  const std::vector<std::vector<double>>& lookup,
                  int start, int goal) {
        const auto& children = lookup[start];
        for (int i = 0; i!=start && i < children.size(); ++i) {
            if (children[i] > 0.0) {
                if (i == goal) return children[i];
                double tmp = findTarget(mp, lookup, i, goal);
                if (tmp > -1.0) {
                    return children[i]*tmp;
                }
                tmp = findTarget(mp, lookup, goal, i);
                if (tmp > -1.0) {
                    return children[i]/tmp;
                }
            }
        }
        return -1.0;
    }
};
