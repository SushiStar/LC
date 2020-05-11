/*
 * Given a nested list of integers, return the sum of all integers in the
 * list weighted by their depth.
 * Each element is either an integer, or a list -- whose elements may also
 * be integers or other lists.
 * Different from the previous question where weight is increasing from root
 * to leaf, now the weight is defined from bottom up. i.e., the leaf level 
 * integers have weight 1, and the root level integers have the largest weight.
 *
 * Date: 05/10/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        NestedInteger root;
        for (auto &i : nestedList)
            root.add(i);
        depth = maxDepth(root);
        auto ret = depthAndSum(root, 1);
        return ret[0];
    }
private:
    int depth;
    int* depthAndSum(const NestedInteger& nestedList, int currDepth) {
        int* ret = new int[2];
        ret[0] = 0;
        ret[1] = 1;
        int sumThisLevel(0);
        if (nestedList.isInteger()) {
            ret[0] = nestedList.getInteger();
        } else {
            auto lst = nestedList.getList();
            for (int i = 0; i < lst.size(); ++i) { 
                if (lst[i].isInteger()) {
                    sumThisLevel += lst[i].getInteger();
                } else {
                    auto tmpRet = depthAndSum(lst[i], currDepth+1);
                    ret[0] += tmpRet[0];
                    ret[1] = std::max(ret[1], tmpRet[1]+1);
                    delete [] tmpRet;
                }
            }
        }
        ret[0] = ret[0] + sumThisLevel * (depth - currDepth);
        return ret;
    }
    int maxDepth(const NestedInteger& itg) {
        int ret{1};
        if (!itg.isInteger()){
            auto lst = itg.getList();
            for (int i = 0; i < lst.size(); ++i) {
                ret = std::max(ret, maxDepth(lst[i])+1);
            }
        }
        return ret;
    }
};

// could also do with BFS, which might be more efficient.
