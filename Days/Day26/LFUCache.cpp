/*
=========================================================
Problem: LFU Cache
Link: https://leetcode.com/problems/lfu-cache/
=========================================================
*/

// ---------------------------
// Method 1 : Frequency Map + Doubly Linked List
// Time Complexity:
// get() -> O(log N)
// put() -> O(log N)
// Space Complexity: O(Capacity)
// ---------------------------

class LFUCache {
private:

    int cap;
    int size;

    // key -> address of {key, value, frequency}
    unordered_map<int, list<vector<int>>::iterator> mp;

    // frequency -> doubly linked list
    map<int, list<vector<int>>> freq;

public:

    LFUCache(int capacity) {

        cap = capacity;
        size = 0;
    }

    // Increase frequency of the key.
    void makeMostFrequentlyUsed(int key) {

        auto &vec = *(mp[key]);

        int value = vec[1];

        int f = vec[2];

        freq[f].erase(mp[key]);

        if(freq[f].empty())
            freq.erase(f);

        f++;

        freq[f].push_front({key, value, f});

        mp[key] = freq[f].begin();
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        auto &vec = (*(mp[key]));

        int value = vec[1];

        makeMostFrequentlyUsed(key);

        return value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            auto &vec = (*(mp[key]));

            vec[1] = value;

            makeMostFrequentlyUsed(key);
        }
        else if(size < cap) {

            size++;

            freq[1].push_front({key, value, 1});

            mp[key] = freq[1].begin();
        }
        else { //Time to remove LFU or LRU if tie

            auto &kaun_sa_list = freq.begin()->second; // least freq used dll selected
            //ordered_map ensures that the begin() will be the least frequency

            int key_delete = (kaun_sa_list.back())[0];  // 0 index pe key hai

            kaun_sa_list.pop_back();

            mp.erase(key_delete);

            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);

            freq[1].push_front({key, value, 1});

            mp[key] = freq[1].begin();
        }
    }
};