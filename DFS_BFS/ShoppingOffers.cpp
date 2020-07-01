/*
 * In LeetCode Store, there are some kinds of items to sell. Each item has a
 * price. However, there are some special offers, and a special offer consists
 * of  one or more different kinds of items with a sale price.
 *
 * your are given the each item's price, a set of special offers, and the number
 * we need to buy for each item. The job is to output the lowest price you have
 * to pay for exactly certain items as given, where you could make optimal use
 * of the special offers.
 *
 * Each special offer is represented in the form of an array, the last number
 * represents the price you need to pay for this special offer, other numbers
 * represents who many specific items you could get if you buy this offer.
 *
 * You could use any of special offers as many times as you want.
 *
 * There are at most 6 kinds of items, 100 special offers.
 * For each item, you need to buy at most 6 of them.
 * You are not allowed to buy more items than you want, even if that would lower
 * the overall price.
 *
 * Date: 06/29/2020
 * Author: Wei Du
 */

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int shoppingOffers(vector<int>& price_, vector<vector<int>>& special_,
                     vector<int>& needs) {
    numTypes = needs.size();
    for (int i =0 ; i < price_.size(); ++i) {
      vector<int> tmp(numTypes+1, 0);
      tmp[i] = 1;
      tmp[numTypes] = price_[i];
      special_.push_back(tmp);
    }
    special = std::move(special_);
    std::vector<int> tmp(needs.size(), 0);
    for (int i = 0; i <= special.size(); ++i)
      memo[getKey(tmp, i)] = 0;
    return buy(needs, 0);
  }

 private:
  int numTypes;
  vector<vector<int>> special;
  unordered_map<size_t, int> memo;

  int buy(std::vector<int> &needs, int start) {
    size_t key = getKey(needs,start);
    if (memo.find(key) != memo.end()) return memo[key];
    int ret{INT_MAX};

    for (int i = start; i < special.size(); ++i) {
      //choose j x special[i]
      for (int j = 1; j < 7; ++j) {
        // check validity
        int k = 0;
        while (k < numTypes && needs[k] >= special[i][k]*j) ++k;
        if (k == numTypes) {
          auto tmp(needs);
          for (k = 0; k < numTypes; ++k) tmp[k] -= special[i][k]*j;
          int tmpRet = buy(tmp, i+1);
          if (tmpRet < INT_MAX)
            ret = std::min(ret, buy(tmp, i+1)+special[i].back()*j);
        } else {
          break;
        }
      }
    }

    memo[key] = ret;
    return ret;
  }

  size_t getKey(vector<int> &needs, int start) {
    std::string s;
    for (int i : needs) s.push_back(i);
    s.push_back(start);
    return std::hash<string>()(s);
  }
};
