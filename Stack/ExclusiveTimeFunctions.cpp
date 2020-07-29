/*
 * On a single threaded CPU, we execute some functions.  Each function has a
 * unique id between 0 and N-1.
 *
 * We store logs in timestamp order that describe when a function is entered or
 * exited.
 *
 * Each log is a string with this format: "{function_id}:{"start" |
 * "end"}:{timestamp}".  For example, "0:start:3" means the function with id 0
 * started at the beginning of timestamp 3.  "1:end:2" means the function with
 * id 1 ended at the end of timestamp 2.
 *
 * A function's exclusive time is the number of units of time spent in this
 * function.  Note that this does not include any recursive calls to child
 * functions.
 *
 * The CPU is single threaded which means that only one function is being
 * executed at a given time unit.
 *
 * Return the exclusive time of each function, sorted by their function id.
 *
 * Date: 07/29/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  using ii = pair<int, int>;

 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    std::vector<int> ret(n, 0);
    std::stack<ii> events;
    std::stack<int> interrupt_time;
    interrupt_time.push(0);
    for (string& log : logs) {
      size_t colon1 = log.find(':');
      size_t colon2 = log.find(':', colon1 + 1);
      ii e{std::stoi(log.substr(0, colon1)), std::stoi(log.substr(colon2 + 1))};
      if (colon2 - colon1 > 5) {  // start
        events.push(e);
        interrupt_time.push(0);
      } else {  // end
        ret[e.first] +=
            e.second - events.top().second + 1 - interrupt_time.top();
        interrupt_time.pop();
        int tmpinter =
            interrupt_time.top() + e.second - events.top().second + 1;
        events.pop();
        interrupt_time.pop();
        interrupt_time.push(tmpinter);
      }
    }
    return ret;
  }
};
