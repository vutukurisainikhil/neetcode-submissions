class LFUCache {
    struct Node {
        int key, value, freq;
    };
    
    int capacity;
    int minFreq; // lowest freq value.
    unordered_map<int, list<Node>::iterator> keyToNode;
    unordered_map<int, list<Node>> freqToList;
    
public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) return -1;
        
        auto it = keyToNode[key];
        int value = it->value;
        touch(key);   // increment freq, move to new bucket
        return value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        // Key already exists: update value and touch.
        if (keyToNode.find(key) != keyToNode.end()) {
            keyToNode[key]->value = value;
            touch(key);
            return; // return as we call of touch(key).
        }
        
        // Evict if at capacity.
        if (keyToNode.size() == capacity) {
            auto& lruList = freqToList[minFreq];
            // pop the back one as less frequent one.
            int evictKey = lruList.back().key;
            lruList.pop_back();
            keyToNode.erase(evictKey);
        }
        
        // Insert new node with freq = 1.
        freqToList[1].push_front({key, value, 1});
        keyToNode[key] = freqToList[1].begin();
        minFreq = 1;
    }
    
private:
    // Increment frequency of `key` and move it to the new frequency's bucket.
    void touch(int key) {
        auto it = keyToNode[key];
        int freq = it->freq;
        int value = it->value;
        
        // Remove from current bucket.
        freqToList[freq].erase(it);
        if (freqToList[freq].empty() && freq == minFreq) {
            minFreq++;
        }
        
        // Add to new bucket (freq + 1), at the front.
        freqToList[freq + 1].push_front({key, value, freq + 1});
        keyToNode[key] = freqToList[freq + 1].begin();
    }
};