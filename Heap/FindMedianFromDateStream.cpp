/*
 * Median is the middle value in an ordered integer list. If the sizej of
 * the list is even, there is no middle value. So the median is the mean
 * of the two middle value.
 *
 * Design a data structure that supports the following two operations:
 *
 *  void addNum(int num) - Add an integer number from the data stream to the
 *  data structure.
 *  double findMedian() - Return the median of all elements so far.
 *
 *  Date: 04/13/2020
 *  Author: Wei Du
 */

#include <queue>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (!pq1.empty() && num > pq1.top()) {
            pq2.push(num);
        } else {
            pq1.push(num);
        }
        // must be pq1.size() >= pq2.size();
        if (pq1.size() < pq2.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
        if (pq1.size() - 1 > pq2.size()) {
            pq2.push(pq1.top());
            pq1.pop();
        }
    }

    double findMedian() {
        if (pq1.size() > pq2.size()) return pq1.empty() ? 0 : pq1.top();
        return ((pq1.top() + pq2.top()) / 2.0);
    }

private:
    // max heap
    std::priority_queue<int, std::vector<int>, std::less<int>> pq1;
    // min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;
};
