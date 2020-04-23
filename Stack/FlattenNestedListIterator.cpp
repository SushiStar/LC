/*
 * Given a nested list of integers, implement an iterator to flatten it.
 * Each element is either an integer, or a list -- whose elements may
 * also be integers or other lits.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (nestedList.empty()) return;
        decodeList(nestedList);
    }

    int next() {
        auto ret{container.top()};
        container.pop();
        return ret;
    }

    bool hasNext() { return !container.empty(); }

private:
    std::stack<int> container;
    void decodeList(const std::vector<NestedInteger> &nestedList) {
        std::stack<NestedInteger> stk;
        for (int i = 0; i < nestedList.size(); ++i)
            stk.push(nestedList[i]);
        while (!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            if (tmp.isInteger()) {
                container.push(tmp.getInteger());
            } else {
                auto lst = tmp.getList();
                for (int i = 0; i < lst.size(); ++i)
                    stk.push(lst[i]);
            }
        }
    }
};
