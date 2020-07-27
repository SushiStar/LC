/*
 * Implement the following operations of a queue using stacks.
 * 	push(x) -- Push element x to the back of queue
 * 	pop() -- Removes the element from in from of queue
 * 	peek() -- Get the front element
 * 	empty() -- Return whether the queue is empty
 *
 * 	You must use only standard operations of the stack -- which means only
 * push to top, peek/pop from top, size, and empty() are valid You may assume
 * all operations are valid.
 *
 * 	Date: 06/29/2020
 * 	Author: Wei Du
 */
#include <stack>
using namespace std;

class MyQueue {
  stack<int> data1, data2;
  void sortData() {
    if (data2.empty()) {
      while (!data1.empty()) {
        data2.push(data1.top());
        data1.pop();
      }
    }
  }

 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { data1.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    sortData();
    int ret{data2.top()};
    data2.pop();
    return ret;
  }

  /** Get the front element. */
  int peek() {
    sortData();
    return data2.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return data1.empty() && data2.empty(); }
};
