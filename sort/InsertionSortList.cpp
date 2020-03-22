/*
 * Sort a linked list using insertion sort.
 * Definition for Singly-linked list:
 * struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL){}
 * };
 *
 * Date: 03/22/2020
 * Author: Wei Du
 */

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode *pre{nullptr}, *current{nullptr}, *next{nullptr};
        std::vector<ListNode *> result{head};
        current = head->next;
        while (current) {
            if (current->val < result.back()->val) {
                if (result[0]->val >= current->val) {
                    result.insert(result.begin(), current);
                } else {
                    for (int i = result.size() - 1; i >= 0; --i) {
                        if (result[i]->val < current->val) {
                            result.insert(result.begin() + i + 1, current);
                            break;
                        }
                    }
                }
            } else {
                result.push_back(current);
            }
            current = current->next;
        }
        for (int i = 0; i < result.size() - 1; ++i) {
            result[i]->next = result[i + 1];
        }
        result.back()->next = nullptr;
        return result[0];
    }
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode *pre{head}, *curr{head->next}, *nxt{nullptr};
        while (curr) {
            nxt = curr->next;
            if (curr->val < pre->val) {
                auto p = findInsertionPlace(head, curr->val);
                if (!p) {
                    curr->next = head;
                    head = curr;
                } else {
                    curr->next = p->next;
                    p->next = curr;
                }
                pre->next = nxt;
                curr = pre;
            } else {
                pre = curr;
            }
            curr = nxt;
        }
        return head;
    }

private:
    /// \ return the pointer next to which the target should be inserted
    ListNode *findInsertionPlace(ListNode *head, int target) {
        ListNode *pre{nullptr}, *curr{head};
        while (curr && target > curr->val) {
            pre = curr;
            curr = curr->next;
        }
        return pre;
    }
};
