/*
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 *
 * Date: May/12/2019
 * Author: Wei Du
 *
 */
#include "../common.h"

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::vector<Node*> vct;
        std::unordered_map<Node*,int> mp;
        int counter(0);
        while (head) {
            vct.push_back(new Node(head->val, nullptr, head->random));
            mp[head] = counter;
            head = head->next;
            ++counter;
        }

        int end(vct.size()-1);
        for (int i = 0; i < end; ++i) {
            vct[i]->next = vct[i+1];
            if (vct[i]->random) {
                vct[i]->random = vct[mp[vct[i]->random]];
            }
        }
        if (vct[end]->random) {
            vct[end]->random = vct[mp[vct[end]->random]];
        }
        return vct[0];
    }
};
