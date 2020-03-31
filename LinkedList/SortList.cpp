/*
 * Sort a linked-list in O(nlogn) time using constant space complexity.
 *
 * Date: 03/30/2020
 * Author: Wei Du
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        auto mid = getMiddle(head);
        auto next = mid->next;
        mid->next = nullptr;

        auto one = sortList(head);
        auto two = sortList(next);
        auto complete = merge(one, two);
        return complete;
    }

    ListNode* getMiddle(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* one, ListNode* two) {
        ListNode* dummyNode;
        ListNode* dummyEnd;

        dummyNode = one->val < two->val ? one : two;
        if (one->val < two->val) {
            dummyNode = one;
            one = one->next;
        } else {
            dummyNode = two;
            two = two->next;
        }
        dummyEnd = dummyNode;

        while (one && two) {
            if (one->val < two->val) {
                dummyEnd->next = one;
                one = one->next;
            } else {
                dummyEnd->next = two;
                two = two->next;
            }
            dummyEnd = dummyEnd->next;
        }
        if (!one) {  // one is empty
            dummyEnd->next = two;
        } else {
            dummyEnd->next = one;
        }
        return dummyNode;
    }
};


// non recursive way, real constant mem usage;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        int size{0};
        for (auto tmp = head; tmp != nullptr; tmp = tmp->next)
            ++size;
        
        for (int stepSize = 1; stepSize < size; stepSize*=2) {
            ListNode* head0{head};
            ListNode* head1{head};
            ListNode* preSeg{nullptr};
            while (head1) {
                // cut segment
                int counter{stepSize};
                while (counter > 0 && head1) {
                    head1 = head1->next;
                    --counter;
                }
                if (!head1) break;
                // merge
                auto headTail = mergeList(head0, head1);
                if (preSeg) {
                    preSeg->next = headTail.first;
                    preSeg = headTail.second;
                } else {
                    head = headTail.first;
                    preSeg = headTail.second;
                }
                head0 = preSeg ? preSeg->next : nullptr;
                head1 = preSeg ? preSeg->next : nullptr;
            }
        }
        return head;
    }
private:
    // return the head of merged list
    std::pair<ListNode*,ListNode*> mergeList(ListNode* head0, ListNode* head1){
        ListNode* firstTail{head0};
        ListNode* secondTail{head1};
        ListNode* afterTail{nullptr};
        ListNode preHead(0);
        while(firstTail->next != head1 ){ 
            firstTail = firstTail->next;
            if (secondTail->next)
                secondTail = secondTail->next;
        }
        firstTail->next = nullptr;
        afterTail = secondTail->next;
        secondTail->next = nullptr;
        auto tmp{&preHead};
        while (head0 && head1){ 
            if (head0->val < head1->val) {
                tmp->next = head0;
                head0 = head0->next;
            } else {
                tmp->next = head1;
                head1 = head1->next;
            }
            tmp = tmp->next;
        }
        
        // connect to next segment;
        if (head0) {
            tmp->next = head0;
            firstTail->next = afterTail;
            return std::make_pair(preHead.next, firstTail);
        }
        tmp->next = head1;
        secondTail->next = afterTail;
        return std::make_pair(preHead.next, secondTail);
    }
};
