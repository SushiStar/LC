/*
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 *
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 *
 * Date: 08/12/2020
 * Author: Wei Du
 */
#include "../common.h"

class KthLargest {
  int topK;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

public:
  KthLargest(int k, vector<int> &nums) : topK{k} {
    for (int num : nums) {
      pq.push(num);
      if (pq.size() > topK)
        pq.pop();
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > topK)
      pq.pop();
    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
