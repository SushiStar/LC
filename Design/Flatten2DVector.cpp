/*
 * Design and implement an iterator to flatten a 2d vector.
 * It should support the following operations: next and hasNext.
 *
 * Please remember to RESET your class variables declared in Vector2D,
 * as static class/variables are persisted across multiple test cases.
 * You may assume that next() call will always be valid, that is,
 * there will be at least a next element in the 2d vector when next()
 * is called.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <vector>

class Vector2D {
public:
    Vector2D(std::vector<std::vector<int>>& v) {
        for (int i = 0; i < v.size(); ++i) 
            if (!v[i].empty()) container.push_back(v[i]);
        itr=container.begin();
        if (itr != container.end())
            itc = (*itr).begin();
    }
    
    int next() {
        int ret = *itc;
        ++itc;
        if (itc == (*itr).end()) {
            ++itr;
            if (itr != container.end())
                itc = (*itr).begin();
        }
        return ret;
    }
    
    bool hasNext() {
        return (itr != container.end());
    }
private:
    std::vector<std::vector<int>> container;
    std::vector<std::vector<int>>::iterator itr;
    std::vector<int>::iterator itc;
};
