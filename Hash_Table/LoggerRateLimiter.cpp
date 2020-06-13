/*
 * Design a logger system that receive stream of messages along with its
 * timestamps, each message should be printed if and only if it is not printed
 * in the last 10 seconds. Given a message and a timestamp (in seconds
 * granularity), return true if the message should be printed in the given time
 * stamp, otherwise returns false. It is possible that several messages arrive
 * roughly at the same time.
 *
 * Date: 06/12/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
using namespace std;

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {}

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
		currentTime = timestamp < currentTime ? currentTime : timestamp;
		// new
		if (lastPrintTime.find(message) == lastPrintTime.end()) {
			lastPrintTime[message] = currentTime;
			return true;
		}
		// printed before
		int lastTime{lastPrintTime[message]};
		if (lastTime  <= currentTime-10) {	// out of 10s
			lastPrintTime[message] = currentTime;
			return true;
		}
		return false;
    }
private:
	int currentTime{0};
	std::unordered_map<std::string, int> lastPrintTime;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
