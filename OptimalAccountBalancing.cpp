/*
 * A group of friends went on holiday and sometimes lent each other
 * money. For example, Alice paid for Bill's lunch for $10. Then later
 * chris gave Alice $5 for a taxi ride. We can model each transaction as
 * a tuple (x, y, z) which means person gave person y $z. Assuming 
 * Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are
 * the person's ID), the transaction can be represented as [[0, 1, 10]], 
 * [2, 0, 5]].
 * Given a list of transactions between a group of people, return the 
 * minimum number of transactions required to settle the debt.
 *
 * A transaction will be given as a tuple (x, y, z). x!=y and z > 0
 * Personal's IDs may not be linear, e.g. we could have the persons 0,
 * 1, 2 or we could also have the persons 0, 2, 6. 
 *
 * Date: 05/22/20202
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        if (transactions.empty()) return 0;
        std::unordered_map<int, int> balance;
        for (auto &tup : transactions) {
            balance[tup[0]] -= tup[2];
            balance[tup[1]] += tup[2];
        }
        for (auto &pr : balance) {
            // leave out those have a balance 0
            if (pr.second > 0) {
                creditor.push_back(pr.second);
            } else if (pr.second < 0) {
                debtor.push_back(-pr.second);
            }
        }
        letsPayback(0, 0);
        return ret;
    }

private:
    int ret{INT_MAX};
    std::vector<int> creditor;
    std::vector<int> debtor;

    void letsPayback(int creditorIdx, int numOperations) {
        if (creditorIdx >= creditor.size()) {
            ret = std::min(ret, numOperations);
            return;
        }
        // else return money for cerdotorIdx;
        // debtor i pay back the money to creditor creditorIdx;
        for (int i = 0; i < debtor.size(); ++i) {
            if (debtor[i] == 0) continue;
            int tmp(debtor[i]);

            // pay off
            if (creditor[creditorIdx] <= debtor[i]) {
                debtor[i]-=creditor[creditorIdx];
                creditor[creditorIdx] = 0; 
                // move on to the next creditor
                letsPayback(creditorIdx+1, numOperations+1);
            } else {    // half pay
                creditor[creditorIdx] -= debtor[i];
                debtor[i] = 0;
                // continue to pay for the rest to creditorIdx
                letsPayback(creditorIdx, numOperations+1);

                // backtrack creditor arary for the use of next variation
                creditor[creditorIdx] += tmp;
            }

            // backtrack debtor array
            debtor[i] = tmp;
        }
    }
};
