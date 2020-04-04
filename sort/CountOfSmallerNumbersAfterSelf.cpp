/*
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 * Date: 04/03/2020
 * Author: Wei Du
 */

// Inversion Count
// Merge Sort
class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        std::vector<int> result(nums.size(), 0);
        std::vector<int> indices(nums.size(), 0);
        std::iota(indices.begin(), indices.end(), 0);
        if (nums.size() <= 1) {
            return result;
        }
        mergeSort(nums, result, indices, 0, nums.size() - 1);
        return result;
    }

private:
    // [start, end]
    void mergeSort(const std::vector<int> &nums, std::vector<int> &result,
                   std::vector<int> &indices, int start, int end) {
        if (start == end) return;
        int mid((start + end) / 2);
        // #[start,mid] > #[mid+1,end];
        mergeSort(nums, result, indices, start, mid);
        mergeSort(nums, result, indices, mid + 1, end);
        merge(nums, result, indices, start, mid + 1, end);
    }

    void merge(const std::vector<int> &nums, std::vector<int> &result,
               std::vector<int> &indices, int start1, int start2, int end) {
        std::vector<int> firstSeg(indices.begin() + start1,
                                  indices.begin() + start2);
        int idx0{start1}, idx1{0}, idx2{start2}, cutIn{0};
        while (idx1 < firstSeg.size()) {
            if (idx2 > end) {
                indices[idx0] = firstSeg[idx1++];
                result[indices[idx0++]] += cutIn;
            } else {
                if (nums[firstSeg[idx1]] <= nums[indices[idx2]]) {
                    indices[idx0] = firstSeg[idx1++];
                    result[indices[idx0++]] += cutIn;
                } else {
                    indices[idx0++] = indices[idx2++];
                    ++cutIn;
                }
            }
        }
    }
};
