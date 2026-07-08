/*
=========================================================
Problem: LRU Cache
Link: https://leetcode.com/problems/lru-cache/
=========================================================
*/

// ---------------------------
// Approach-1 (Brute Force)
// Time Complexity:
// get() -> O(N)
// put() -> O(N)
// Space Complexity: O(Capacity)
// ---------------------------

class LRUCache {
public:

    vector<pair<int, int>> cache;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {

        for(int i = 0; i<cache.size(); i++) {

            if(cache[i].first == key) {

                int val = cache[i].second;

                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);

                return val;
            }

        }

        return -1;

    }

    void put(int key, int value) {

        for(int i = 0; i<cache.size(); i++) {

            if(cache[i].first == key) {

                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }

        if(cache.size() == n) {

            cache.erase(cache.begin());
            cache.push_back({key, value});

        } else {

            cache.push_back({key, value});
        }

    }
};


// ---------------------------
// Approach-2 (Optimal)
// Time Complexity:
// get() -> O(log N)
// put() -> O(log N)
// Space Complexity: O(Capacity)
// ---------------------------

class LRUCache {
public:

    // Stores keys in LRU order.
    list<int> dll;

    // key -> (iterator in list, value)
    map<int, pair<list<int>::iterator, int>> mp;

    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Move key to front (Most Recently Used).
    void makeMostRecentlyUsed(int key) {

        dll.erase(mp[key].first);

        dll.push_front(key);

        mp[key].first = dll.begin();
    }

    int get(int key) {

        if(!mp.count(key))
            return -1;

        makeMostRecentlyUsed(key);

        return mp[key].second;
    }

    void put(int key, int value) {

        if(mp.count(key)) {

            mp[key].second = value;

            makeMostRecentlyUsed(key);
        }
        else {

            dll.push_front(key);

            mp[key] = {dll.begin(), value};

            capacity--;
        }

        // Remove Least Recently Used key.
        if(capacity < 0) {

            mp.erase(dll.back());

            dll.pop_back();

            capacity++;
        }
    }
};