/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );//capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/


class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity; 
    }
    
    int get(int key) {
        //check if the key is in the cache 
        auto it = map_.find(key);
        //if not in the cache, return -1 
        if (it == map_.cend()) {
            return -1;
        }
        //if in the cache, move the key to the front of the doubly linked-list
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second; 
    }
    
    void put(int key, int value) {
        //check if the key is in the cache
        auto it = map_.find(key);
        //if in the cache, update the value of the key and move the key to the front of the doubly linked-list
        if (it != map_.cend()) {
            it->second->second = value; 
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        //if not in the cache
        //1. check the capacity is reached, if reached the capacity --> remove the last element in the doubly linked list 
        if (cache_.size() == capacity_) {
            auto& node = cache_.back(); 
            map_.erase(node.first);
            cache_.pop_back();
        }
        //2. insert the key into the front of the doubly linked-list and update the map key and value 
        cache_.emplace_front(key, value);
        map_[key] = cache_.begin();
    }
private: 
    int capacity_; 
    list<pair<int, int>> cache_; 
    unordered_map<int, list<pair<int, int>>::iterator> map_; //key: int, value: the pointer points to the linked-list
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
