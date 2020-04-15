/*
 * N couples sit in 2N seats arranged in a row and want to hold hands.
 * We want to know the minimum numbers of swaps so that every couple
 * is sitting side by side. A swap consists of choosing any two people,
 * then they stand up and switch seats.
 *
 * The people and seats are represented by an integer from 0 to 2N-1, the
 * couples are numbered in order, the first couple being (0,1), the second
 * couple being (2, 3) and so on with the last couple being (2N-2, 2N-1).
 *
 * The couples' initial siting is given by row[i] being the value of the
 * person who is initially siting in the ith seat.
 *
 * Date: 04/14/2020
 * Author: Wei Du
 */
class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        std::unordered_map<int, int> pos;
        for (int i = 0; i < row.size(); ++i)
            pos[row[i]] = i;
        int count{0};
        for (int i = 0; i < row.size(); i += 2) {
            int curr{row[i]};
            int currCp{(curr & 1) ? curr - 1 : curr + 1};
            if (row[i + 1] == currCp) {
                continue;
            } else {
                std::swap(row[pos[currCp]], row[i + 1]);
                pos[row[pos[currCp]]] = pos[currCp];
                row[pos[currCp]] = row[pos[currCp]];
                pos[currCp] = i + 1;
                row[i + 1] = currCp;
                ++count;
            }
        }
        return count;
    }
};
