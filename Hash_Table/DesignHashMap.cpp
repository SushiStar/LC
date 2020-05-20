/*
 * Design a HashMap without using any built-in hash table libraries.
 * To be specific, your design hsould incould these functions:
 *  put(key, value): insert a (key, value) pair into the HashMap. If the key
 *  alreasy exists in the HashMap, update the value.
 *  get(key): Returns the value to which the specified key is mapped, or -1 if 
 *  this map contaiins no mapping for they key.
 *  remove(key): Remove the mapping for the value key if this map contains the
 *  mapping for the key.
 *
 *  Note: All keys and values will be in the range of [0, 1000000].
 *        The number of operations will be in the range of [1, 10000];
 *        Please do not use the built-in HashMap library.
 *
 * Date: 05/19/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : mapp(1000000,-1){

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        mapp[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return mapp[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        mapp[key] = -1;
    }
private:
    std::vector<int> mapp;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
