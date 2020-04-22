/*
 * Write a program to find the n-the ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 1 is typically treated as an ugly nubmer.
 *
 * Date: 04/22/2020
 * Author: Wei Du
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 2) return 1;
        int ret{1};
        int count{1};
        std::deque<long> buffer[3];
        buffer[0].push_back(2);
        buffer[1].push_back(3);
        buffer[2].push_back(5);
        while (count < n) {
            int idx = buffer[0].front() <= buffer[1].front() ? 0 : 1;
            idx = buffer[idx].front() <= buffer[2].front() ? idx : 2;
            long curr = buffer[idx].front();
            buffer[idx].pop_front();
            if (curr <= ret) continue;
            ret = curr;
            ++count;
            buffer[0].push_back(curr * 2);
            buffer[1].push_back(curr * 3);
            buffer[2].push_back(curr * 5);
        }
        return ret;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res{1};
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < n; i++) {
            int p = min(res[p1] * 2, min(res[p2] * 3, res[p3] * 5));
            if (p == res[p1] * 2) p1++;
            if (p == res[p2] * 3) p2++;
            if (p == res[p3] * 5) p3++;
            res.push_back(p);
        }
        return res[n - 1];
    }
};
