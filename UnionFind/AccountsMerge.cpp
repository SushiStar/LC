/*
 * Given a list accounts, each element accounts[i] is a list of strings, where
 * the first element accounts[i][0] is a name, and rest of the elements are
 * emails representing emails of the account.
 *
 * Now, we would like to merge these accounts. Two accounts definitely belong to
 * the same person if there is some email that is common to both accounts. Note
 * that even if two accounts have the same name, they may belong to differnt
 * people as people could have the same name. A person can have any number of
 * accounts initially, but all of their accounts definitely have the same name.
 *
 * After merging the accounts, return the accounts in the following format: the
 * first element of each account is the name, and the rest of the elements are
 * emails in sorted order. The accounts themselves can be returned in any order.
 *
 * Date: 04/14/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        parent.resize(accounts.size(), 0);
        std::iota(parent.begin(), parent.end(), 0);
        std::unordered_map<std::string, int> em2idx;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (em2idx.find(accounts[i][j]) == em2idx.end()) {
                    em2idx[accounts[i][j]] = i;
                } else if (em2idx[accounts[i][j]] != i) {
                    uni(em2idx[accounts[i][j]], i);
                }
            }
        }
        std::vector<int> position(accounts.size(), -1);
        std::unordered_set<std::string> inserted;
        std::vector<std::vector<std::string>> rlt{};
        for (auto &pr : em2idx) {
            int parent = find(pr.second);
            if (position[parent] == -1) {
                position[parent] = rlt.size();
                rlt.push_back(std::vector<std::string>{accounts[parent][0]});
            }
            if (inserted.find(pr.first) == inserted.end()) {
                rlt[position[parent]].push_back(pr.first);
                inserted.insert(pr.first);
            }
        }
        for (auto &acc : rlt) {
            std::sort(acc.begin(), acc.end());
        }
        return rlt;
    }

private:
    std::vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }
    void uni(int a, int b) {
        int pa{find(a)};
        int pb{find(b)};
        if (pa != pb) {
            parent[pb] = pa;
        }
    }
};
