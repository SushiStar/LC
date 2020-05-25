/*
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 * Note: If the two linked lists have no intersection at all, return null.
 *       The linked lists must retain their original structure after the
 *          function returns;
 *       You may assume there are no cycles anywhere in the entire linked
 * structure. Your code should preferably run in O(n) time and O(1) memory.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        auto tmp1(headA), tmp2(headB);
        int counter1{0}, counter2{0};
        while (tmp1->next) {
            tmp1 = tmp1->next;
            ++counter1;
        }
        while (tmp2->next) {
            tmp2 = tmp2->next;
            ++counter2;
        }
        if (tmp1 != tmp2) return nullptr;
        ;
        tmp1 = headA;
        tmp2 = headB;
        while (counter1 > counter2) {
            tmp1 = tmp1->next;
            --counter1;
        }
        while (counter2 > counter1) {
            tmp2 = tmp2->next;
            --counter2;
        }
        while (tmp1 != tmp2) {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return tmp1;
    }
};
