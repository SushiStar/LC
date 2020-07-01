/*
 * You are given a doubly linked list which in addition to the next and previous
 * pointers, it could have a child pointer, which may or may not point to a
 * separate doubly linked list. These child lists may have one or more children
 * of their own, and so on, to produce a multilevel data structure, as shown in
 * the example below.
 *
 * Flatten the list so that all the nodes appear in a single-level, doubly
 * linked list. You are given the head of the first level of the list.
 *
 * Date: 07/01/2020
 * Author: Wei Du
 */

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
      if (!head) return nullptr;
      auto nxt = head->next;
      head->next = flatten(head->child);
      if (head->next) head->next->prev = head;
      auto tmp(head);
      while (tmp->next) tmp = tmp->next;
      tmp->next = flatten(nxt);
      if (tmp->next) tmp->next->prev = tmp;
      head->child = nullptr;
      return head;
    }
};
