/*
 * There are a total of n courses you have to take, labled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you
 * have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisites pairs,
 * return the ordering of courses, you should take to finish all courses.
 * [1,2]
 * [3,4]
 * ...
 *
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 *
 * Date: May/12/2019
 * Author: Wei Du
 */
#include <vector>
#include <algorithm>

class Solution {
private:
    struct Node {
        int val;
        int degree;
        std::vector<Node*> child;
        Node(int val_) : val(val_),degree(0) {}
    };

    struct cmp {
        bool operator()(Node* a, Node* b) {
            return a->degree > b->degree;
        }
    };

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> res;
        if (!numCourses) return res;
        std::vector<Node*> courses(numCourses, nullptr);
        // to save all nodes
        for (int i = 0; i < numCourses; ++i) {
            courses[i] = new Node(i);
        }
        // assign edges and degrees to the child
        for (auto& p : prerequisites) {
            courses[p[0]]->child.push_back(courses[p[1]]);
            courses[p[1]]->degree++;
        }

        // build a priority queue and start popping.
        while (!courses.empty()) {
            std::make_heap(courses.begin(), courses.end(), cmp());
            if (courses[0]->degree) {
                res.clear();
                return res;
            }
            int count(0);
            while (count < courses.size() && !courses[count]->degree) {
                res.push_back(courses[count]->val);
                for (auto& pt : courses[count]->child){
                    pt->degree--;
                }
                delete courses[count];
                courses[count] = nullptr;
                ++count;
            }
            courses.erase(courses.begin(), courses.begin()+count);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

