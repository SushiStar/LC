/*
 * Deisign and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1. put(key, value) - Set or insert the
 * value if the key is not already present. When the cache reached its capacity,
 * it should invalidate the least recently used item before inserting a new
 * item. The cache is initizlized with a positive capacity.
 *
 * Date: 06/04/2020
 * Author: Wei Du
 */

#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        volume = capacity;
        counter = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (!mapp[key]) return -1;
        moveToTail(mapp[key]);
        return mapp[key]->value;
    }

    void put(int key, int value) {
        if (mapp[key]) {
            mapp[key]->value = value;
            moveToTail(mapp[key]);
            return;
        }

        if (volume > counter) {
            ListNode *currNode = new ListNode(key, value);
            mapp[key] = currNode;
            if (counter == 0) {
                tail = head = currNode;
                ++counter;
                return;
            }
            tail->next = currNode;
            currNode->prev = tail;
            tail = currNode;
            ++counter;
            return;
        } // else {    // counter == volume
        if (volume == 1) {
            mapp[head->key] = nullptr;
            head->key = key;
            head->value = value;
            mapp[key] = head;
        } else {
            mapp[head->key] = nullptr;
            mapp[key] = head;
            head->key = key;
            head->value = value;
            moveToTail(head);
        }
    }

private:
    struct ListNode {
        int key;
        int value;
        ListNode *prev;
        ListNode *next;
        ListNode(int key_, int value_)
            : key(key_), value(value_), prev(nullptr), next(nullptr) {}
    };

    int volume;
    int counter;
    ListNode *head;
    ListNode *tail;
    std::unordered_map<int, ListNode *> mapp;

    void moveToTail(ListNode *currNode) {
        if (tail == currNode) return;

        // move the node to the end;
        if (head == currNode) {
            head = currNode->next;
            head->prev = nullptr;
            currNode->next = nullptr;
        } else if (tail != currNode) {
            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;
        }
        tail->next = currNode;
        currNode->prev = tail;
        tail = currNode;
    }
};
