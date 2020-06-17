/*
 * Equations are given in the format A/B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number). Given
 * some queries, return the answers. If the Answer does not exist, return -1.0.
 *
 * Date: 03/27/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        std::vector<double> results{};
        int counter{1};
        std::unordered_map<std::string, int> mp{};
        std::vector<std::vector<double>> lookup(
            equations.size() * 2 + 1,
            std::vector<double>(equations.size() * 2 + 1, -1.0));
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
            lookup[mp[equations[i][1]]][mp[equations[i][0]]] = 1.0 / values[i];
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
            auto a = findTarget(mp, lookup, start, goal);
            auto b = findTarget(mp, lookup, goal, start);
            if (a > 0) {
                results.push_back(a);
            } else {
                results.push_back(1.0 / b);
            }
            lookup[start][goal] = results.back();
            lookup[goal][start] = 1.0 / results.back();
        }
        return results;
    }

private:
    double findTarget(const std::unordered_map<std::string, int> &mp,
                      const std::vector<std::vector<double>> &lookup, int start,
                      int goal) {
        const auto &children = lookup[start];
        for (int i = 0; i != start && i < children.size(); ++i) {
            if (children[i] > 0.0) {
                if (i == goal) return children[i];
                double tmp = findTarget(mp, lookup, i, goal);
                if (tmp > -1.0) {
                    return children[i] * tmp;
                }
                tmp = findTarget(mp, lookup, goal, i);
                if (tmp > -1.0) {
                    return children[i] / tmp;
                }
            }
        }
        return -1.0;
    }
};

// Union Find
// Union Failed, because union doesn't care about the relationship between
// elements in one set, it only cares about if different elements belong to the
// same set.
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        int count{0};
        lookup.resize(equations.size() * 2,
                      std::vector<double>(equations.size() * 2, -1.0));
        for (int i = 0; i < equations.size(); ++i) {
            if (mp.find(equations[i][0]) == mp.end()) {
                element *tmp = new element(equations[i][0], count++);
                mp[equations[i][0]] = tmp;
            }
            if (mp.find(equations[i][1]) == mp.end()) {
                element *tmp = new element(equations[i][1], count++);
                mp[equations[i][1]] = tmp;
            }
            element *el0 = mp[equations[i][0]];
            element *el1 = mp[equations[i][1]];
            auto p0 = findRoot(el0);
            auto p1 = findRoot(el1);
            if (p0 != p1) uni(p0, p1);
            lookup[el0->id][el1->id] = values[i];
            lookup[el1->id][el0->id] = 1.0 / values[i];
            lookup[el0->id][el0->id] = 1.0;
            lookup[el1->id][el1->id] = 1.0;
        }
        std::vector<double> result{};
        for (const auto &query : queries) {
            if (mp.find(query[0]) == mp.end() ||
                mp.find(query[1]) == mp.end()) {
                result.push_back(-1.0);
                continue;
            }
            auto state0 = mp[query[0]];
            auto state1 = mp[query[1]];
            if (lookup[state0->id][state1->id] > -1.0) {
                result.push_back(lookup[state0->id][state1->id]);
                continue;
            }
            auto parent0 = findRoot(state0);
            auto parent1 = findRoot(state1);
            if (parent0 != parent1) {
                result.push_back(-1.0);
            }
            double m0 = multiplyToRoot(state0);
            double m1 = multiplyToRoot(state1);
            result.push_back(m1 / m0);
            lookup[state0->id][state1->id] = result.back();
            lookup[state1->id][state0->id] = 1.0 / result.back();
        }
        return result;
    }

private:
    struct element {
        element(std::string val_, int id_)
            : val(val_), id(id_), parent(nullptr) {}
        std::string val;
        element *parent;
        int id;
    };

    std::unordered_map<std::string, element *> mp;
    std::vector<std::vector<double>> lookup;

    void uni(element *el0, element *el1) {
        auto root0 = findRoot(el0);
        auto root1 = findRoot(el1);
        if (root0 != roott1) {
            root1->parent = root0;
        }
    }

    element *findRoot(element *el) {
        while (el->parent != nullptr) {
            el = el->parent;
        }
        return el;
    }

    double multiplyToRoot(element *el) {
        double result{1.0};
        while (el->parent != nullptr) {
            result *= lookup[el->parent->id][el->id];
            el = el->parent;
        }
        return result;
    }
};
