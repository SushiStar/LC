/*
 * Design a HashSet without using any built-in hash table libraries.
 *
 * To be specific, your design should include these functions:
 * add(value): Insert a value into the HashSet.
 * contains(value) : Return whether the value exists in the HashSet or not.
 *
 * remove(value): Remove a value in the HashSet.
 *
 * If the value does not exist in the HashSet, do nothing.
 *
 * Date: 08/02/2020
 * Author: Wei Du
 */
#include "../common.h"

class MyHashSet {
  static const int MOD = 10007;
  list<int> container[MOD];

 public:
  /** Initialize your data structure here. */
  MyHashSet() {}

  void add(int key) {
    if (contains(key)) return;
    container[key%MOD].push_back(key);
  }

  void remove(int key) {
    std::list<int>::iterator it{container[key%MOD].begin()};
    std::list<int>::iterator end{container[key%MOD].end()};
    while (it != end) {
      if (*it == key) {
        container[key%MOD].erase(it);
        break;
      }
      ++it;
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    std::list<int>::iterator it{container[key%MOD].begin()};
    std::list<int>::iterator end{container[key%MOD].end()};
    while (it != end) {
      if (*it == key) return true;
      ++it;
    }
    return false;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
