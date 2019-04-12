/*
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Date: Apr/11/2019
 * Author: Wei Du
 */
#include <list>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        auto hf = getMid(head);
        auto rvs = reverse(hf);
        while (rvs && head) {
            if (rvs->val == head->val) {
                rvs = rvs->next;
                head = head->next;
            } else {
                return false;
            }
        }

        return true;
    }

    ListNode* getMid(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->next;
    }

    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;
        ;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        auto now = head;
        auto nxt = head->next;
        while (now && nxt) {
            now->next = pre;
            pre = now;
            now = nxt;
            nxt = nxt->next;
        }
        now->next = pre;
        delete head->next;
        head->next = nullptr;
        return now;
    }
};

bool isPalindrome(ListNode* head) {
    if (!head) return true;
    std::vector<int> rvs;
    auto ori = head;
    while (head) {
        rvs.push_back(head->val);
        head = head->next;
    }
    int end = (rvs.size() + 1) / 2;
    for (int i = rvs.size() - 1; i >= end; --i) {
        if (ori->val != rvs[i]) return false;
        ori = ori->next;
    }
    return true;
}
