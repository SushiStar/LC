/*
 * Given a singly linke list L: L0->L1->L2->...->Ln-1->Ln,
 * rorder it to Lo->Ln->L1->Ln-1->L2->Ln-1->...
 * You may not modify the values in the list's nodes, only nodes itself
 * may be changed.
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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        std::deque<ListNode *> dq;
        ListNode *buffer(head);
        while (buffer) {
            dq.push_back(buffer);
            buffer = buffer->next;
        }
        dq.pop_front();
        buffer = head;
        while (!dq.empty()) {
            buffer->next = dq.back();
            buffer = buffer->next;
            dq.pop_back();
            if (!dq.empty()) {
                buffer->next = dq.front();
                buffer = buffer->next;
                dq.pop_front();
            }
        }
        buffer->next = nullptr;
        return;
    }
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        std::vector<ListNode *> vct{};
        ListNode *buffer{head};
        while (buffer) {
            vct.push_back(buffer);
            buffer = buffer->next;
        }
        int i{0}, j{(int)vct.size() - 1};
        while (i < j) {
            vct[i]->next = vct[j];
            vct[j]->next = vct[i + 1];
            ++i;
            --j;
        }
        vct[i]->next = nullptr;
    }
};
