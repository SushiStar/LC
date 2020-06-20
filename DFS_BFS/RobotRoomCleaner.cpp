/*
 * Given a robot cleaner in a room modeled as a grid.
 * Each cell in the grid can be empty or blocked.
 * The robot cleaner with 4 given APIs can move forward, turn left or turn
 * right. Each turn it made is 90 degrees. When it  tries to move into a blocked
 * cell, its bumper sensor detects the obstacle and it stays on the current
 * cell. Design an algorithm to clean the entire room using only 4 given APIs
 * shown below.
 *
 * Date: 06/18/2020
 * Author: Wei Du
 */

#include <algorithm>
#include <deque>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the
    // current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};
class Solution {
    struct state {
        int x, y;
        bool valid;
    };

public:
    void cleanRoom(Robot &robot) {
        agent = &robot;
        theta = 0;
        mapp[150][150] = new state{150, 150, true};
        curr = mapp[150][150];
        clean();
    }

private:
    Robot *agent;
    int theta; // 0, 1 , 2, -1, -2
    state *curr;
    std::vector<state*> plan;
    state *mapp[300][300];
    state *visited[300][300]; // nullptr unvisited, otherwise visited
    void clean() {
        // initialize the start cell;
        agent->clean();
        while (findNextGoal()) {
            executePlan();
        }
    }

    bool gotoCell(state *nxt) {
        int endDir;
        if (nxt->x == curr->x)
            endDir = nxt->y > curr->y ? 1 : -1;
        else
            endDir = nxt->x > curr->x ? 2 : 0;
        while (endDir > theta) {
            ++theta;
            agent->turnRight();
        }
        while (endDir < theta) {
            --theta;
            agent->turnLeft();
        }
        bool flag = agent->move();
        curr = flag ? nxt : curr;
        return flag;
    }

    // BFS
    // find the first unvisited cell, go there
    // return true if there exists an unvisited cell, false otherwise
    bool findNextGoal() {
        for (int i = 0; i < 300; ++i) {
            std::fill(visited[i], visited[i] + 300, nullptr);
        }
        std::deque<state*> dq{curr};
        visited[curr->x][curr->y] = curr;
        while (!dq.empty()) {
            auto parent = dq.front();
            dq.pop_front();
            if (!visited[parent->x + 1][parent->y]) {
                state *tmp = mapp[parent->x + 1][parent->y];
                if (!tmp) { // existing
                    state *tmp = new state{parent->x + 1, parent->y, true};
                    mapp[parent->x + 1][parent->y] = tmp;
                    visited[tmp->x][tmp->y] = parent;
                    traceBackNewState(tmp);
					return true;
                } else if (tmp->valid && !visited[tmp->x][tmp->y]) {
                    dq.push_back(tmp);
                    visited[tmp->x][tmp->y] = parent;
                }
            }
            if (!visited[parent->x - 1][parent->y]) {
                state *tmp = mapp[parent->x - 1][parent->y];
                if (!tmp) { // existing
                    state *tmp = new state{parent->x - 1, parent->y, true};
                    mapp[parent->x - 1][parent->y] = tmp;
                    visited[tmp->x][tmp->y] = parent;
                    traceBackNewState(tmp);
					return true;
                } else if (tmp->valid && !visited[tmp->x][tmp->y]) {
                    dq.push_back(tmp);
                    visited[tmp->x][tmp->y] = parent;
                }
            }
            if (!visited[parent->x][parent->y + 1]) {
                state *tmp = mapp[parent->x][parent->y + 1];
                if (!tmp) { // existing
                    state *tmp = new state{parent->x, parent->y + 1, true};
                    mapp[parent->x][parent->y + 1] = tmp;
                    visited[tmp->x][tmp->y] = parent;
                    traceBackNewState(tmp);
					return true;
                } else if (tmp->valid && !visited[tmp->x][tmp->y]) {
                    dq.push_back(tmp);
                    visited[tmp->x][tmp->y] = parent;
                }
            }
            if (!visited[parent->x][parent->y - 1]) {
                state *tmp = mapp[parent->x][parent->y - 1];
                if (!tmp) { // existing
                    state *tmp = new state{parent->x, parent->y - 1, true};
                    mapp[parent->x][parent->y - 1] = tmp;
                    visited[tmp->x][tmp->y] = parent;
                    traceBackNewState(tmp);
					return true;
                } else if (tmp->valid && !visited[tmp->x][tmp->y]) {
                    dq.push_back(tmp);
                    visited[tmp->x][tmp->y] = parent;
                }
            }
        }
        return false;
    }

    void traceBackNewState(state *tmp) {
        while (visited[tmp->x][tmp->y] != tmp) {
            plan.push_back(tmp);
            tmp = visited[tmp->x][tmp->y];
        }
        plan.push_back(tmp);
    }

    void executePlan() {
        std::reverse(plan.begin(), plan.end());
        for (int i = 1; i < plan.size(); ++i) {
            if (!gotoCell(plan[i])) {
				plan[i]->valid = false;
                plan.clear();
                return;
            }
        }
        agent->clean();
        plan.clear();
    }
};


