/*
 * Disign and implement a data structure for Least Frequently Used (LFU)
 * cache. It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the
 * key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already
 * present. When the cache reaches its capacity, it should invalidate the
 * least frequently used item before inserting a new item. For the purpose
 * of this problem, when there is a tie (i.e., two or more keys that have
 * the same frequency), the least recently used key would be evicted.
 * Note that the number of times an itme is used is the number of calls
 * to the get and put functions for that item since it was inserted. This
 * number is set to zero when the item is removed.
 *
 * Could you do both operations in O(1) time complexity?
 *
 * Date: 05/13/2020
 * Author: Wei Du
 */
#include <unordered_map>
#include <queue>

class LFUCache {
public:
    LFUCache(int capacity) : volume(capacity) {
        time_stamp = 0;
    }

    int get(int key) {
        if (mapp.find(key) == mapp.end()) 
            return -1;
        ++time_stamp;
        data* visit = mapp[key];
        visit->freq +=1;
        visit->stamp = time_stamp;
        if (pq.top() == visit) {
            pq.pop();
            pq.push(visit);
        }
        return visit->value;
    }

    void put(int key, int value) {
        ++time_stamp;
        if (mapp.find(key) == mapp.end()) {
            data* curr = new data(key, value, time_stamp);
            mapp[key] = curr;
            pq.push(curr);
            if (pq.size() > volume) {
                auto evict = pq.top();
                mapp.erase(evict->key);
                pq.pop();
                delete evict;
            }
            return;
        }

        ++mapp[key]->freq;
        mapp[key]->stamp = time_stamp;
        mapp[key]->value = value;
        if (mapp[key] == pq.top()) {
            pq.pop();
            pq.push(mapp[key]);
        }
    }

private:
    struct data;
    struct dataCmp;

    std::size_t time_stamp;
    int volume;
    std::unordered_map<int, data*> mapp;
    std::priority_queue<data*, std::vector<data*>, dataCmp> pq;
    struct data {
        data(int key_, int value_, size_t stamp_) : key(key_), value(value_), freq(1), stamp(stamp_) {}
        int key;
        int value;
        int freq;
        std::size_t stamp;
    };
    struct dataCmp {
        bool operator() (data* lhs, data* rhs) const {
            if (lhs->freq> rhs->freq) return true;
            else if (lhs->freq== rhs->freq) return lhs->stamp > rhs->stamp;
            return false;
        }
    };
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> m; //key to {value,freq};
    unordered_map<int, list<int>::iterator> mIter; //key to list iterator;
    unordered_map<int, list<int>>  fm;  //freq to key list;
public:
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    int get(int key) {
        if(m.count(key)==0) return -1;
        
        fm[m[key].second].erase(mIter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        mIter[key]=--fm[m[key].second].end();
        
        if(fm[minFreq].size()==0 ) 
              minFreq++;
        
        return m[key].first;
    }
    
   void set(int key, int value) {
        if(cap<=0) return;
        
        int storedValue=get(key);
        if(storedValue!=-1)
        {
            m[key].first=value;
            return;
        }
        
        if(size>=cap )
        {
            m.erase( fm[minFreq].front() );
            mIter.erase( fm[minFreq].front() );
            fm[minFreq].pop_front();
            size--;
        }
        
        m[key]={value, 1};
        fm[1].push_back(key);
        mIter[key]=--fm[1].end();
        minFreq=1;
        size++;
    }
};
