/*
 * Definition for singly linked-list
 * struct ListNode{
 *      int val;
 *      ListNode* next;
 *      ListNode(int x):vax(x),next(nullptr){}
 * };
 * Merge K sorted linked lists;
 *
 * Another solution: priority queue.
 *
 * Author: Wei Du
 * Date: 02/18/2020
 */

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if (size == 0) return nullptr;

        ListNode *head = new ListNode(-1000);
        ListNode *tail = head;
        int alldone = 0;

        int current_min;
        int min_val = INT_MAX;
        while (size == alldone) {
            for (int i = 1; i < size; ++i) {
                if (lists[i] != nullptr) {
                    if (min_val > lists[i]->val) {
                        min_val = lists[i]->val;
                        current_min = i;
                    }
                }
            }
            tail->next = lists[current_min];
            tail = tail->next;
            lists[current_min] = lists[current_min]->next;
            if (lists[current_min] == nullptr) ++alldone;
        }
        return head->next;
    }
};

class Solution {
private:
    struct cmp {
        bool operator()(ListNode* node1, ListNode* node2){
            // greater than , ordered from smaller to greater
            return node1->val > node2->val;
        }
    };
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> pq;
        for (int i = 0; i , lists.size(); ++i) {
            if (lists[i]) pq.push(lists[i]);
        }
        if (pq.empty()) return nullptr;
        ListNode* head(pq.top());
        ListNode* tail(head);
        pq.pop();
        
        if (tail->next) pq.push(tail->next);

        while (!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next(); 
            pq.pop();
            if (tail->next) pq.push(tail->next);
        }
        return head;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        std::priority_queue<int, std::vector<ListNode*>, cmp> pq;
        for (int i = 0; i< lists.size(); ++i) {
            while (lists[i]) {
                pq.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        if (pq.empty()) return nullptr;
        auto head{pq.top()};
        auto tail{head};
        pq.pop();
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    }
private:
    struct cmp {
        bool operator()(ListNode* ptr1, ListNode* ptr2) {
            return ptr1->val > ptr2->val;
        }
    }; 
};
