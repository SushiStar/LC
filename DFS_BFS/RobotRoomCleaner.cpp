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

#include <vector>
#include <deque>
#include <unordered_set>
#include <utility>
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
	using ii = std::pair<int,int>;
public:
	void cleanRoom(Robot &robot) {
		agent = &robot;
		theta = 0;
		curr.first = curr.second = 500;
		clean();
	}
private:
	Robot* agent;
	int theta;	//0, 1 , 2, -1, -2
	ii curr, target;
	std::vector<ii> plan;
	// 0 unvisited; 1 visited; -1 obs;
	int mapp[1000][1000];
	std::unordered_set<ii> sett;

	void clean() {
		while (findNextGoal())
			executePlan();
	}

	bool gotoCell(ii &nxt) {
		bool success;
		int turnTimes;
		if (nxt.first == curr.first) {
			// same col
			if (nxt.second > curr.second) {	// go right
				turnTimes =
			} else {	// got left

			}
		} else {
			// same row
			if (nxt.first> curr.first) {	// go down

			} else {	// go up

			}
		}
		mapp[curr.first][curr.second] = success ? 1 : -1;
		return success;
	}

	bool findNextGoal() {

	}

	void executePlan() {
		for (int i = 1; i < plan.size(); ++i) {
			if (!gotoCell(plan[i])) {
				mapp[plan[i].first][plan[i].second] = -1;
				break;
			}
		}
		plan.clear();
	}
};
