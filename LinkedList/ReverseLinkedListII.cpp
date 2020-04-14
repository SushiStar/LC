/*
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Date: 04/13/2020
 * Author: Wei Du
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *pre = m > 1 ? head : nullptr;
        ListNode *mark1 = m > 1 ? head->next : head;
        --m;
        ListNode *mark2{head};
        while (m > 1) {
            --m;
            mark1 = mark1->next;
            pre = pre->next;
        }
        while (n > 1) {
            --n;
            mark2 = mark2->next;
        }
        ListNode *after(mark2->next);
        mark2->next = nullptr;
        reverseList(mark1);
        if (pre) {
            pre->next = mark2;
            mark1->next = after;
            return head;
        }
        mark1->next = after;
        return mark2;
    }

private:
    void reverseList(ListNode *head) {
        std::vector<ListNode *> vct;
        while (head) {
            vct.push_back(head);
            head = head->next;
        }
        for (int i = vct.size() - 1; i > 0; --i) {
            vct[i]->next = vct[i - 1];
        }
    }
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *mark1{head};
        ListNode *mark2{head};
        while (m > 1) {
            --m;
            --n;
            mark1 = mark1->next;
            mark2 = mark2->next;
        }
        std::vector<ListNode *> vct{mark2};
        while (n > 1) {
            mark2 = mark2->next;
            vct.push_back(mark2);
            --n;
        }
        int half(vct.size() / 2);
        for (int i = 0; i < half; ++i)
            std::swap(vct[i]->val, vct[vct.size() - i - 1]->val);
        return head;
    }
};
