class LRUCache {
    unordered_map<int /*key*/, pair<int /*val*/, list<int>::iterator>> m;
    list<int /*key*/> lru;
    int n = 0;

public:
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        // if exists then, need to update the lru as recently used.
        lru.erase(m[key].second);
        lru.push_back(key);
        m[key].second = --lru.end(); // pre-increment
        return m[key].first;
    }

    void put(int key, int value) {
        // Firstly find the key exists or not.
        if (m.find(key) != m.end()) {
            lru.erase(m[key].second);
        } else if (lru.size() == n) {
            int key = lru.front();
            lru.erase(m[key].second);
            m.erase(key);
        }
        // even if update val or new value update the lru and map.
        lru.push_back(key);
        m[key] = {value, --lru.end()}; // pre-increment
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */