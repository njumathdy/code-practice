/*******************
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cache_size = capacity;
        p_cache_list_head = new CacheNode();
        p_cache_list_near = new CacheNode();
        p_cache_list_head -> next = p_cache_list_near;
        p_cache_list_head -> pre = nullptr;
        p_cache_list_near -> pre = p_cache_list_head;
        p_cache_list_near -> next = nullptr;
    }
    
    ~LRUCache() {
        CacheNode *p;
        p = p_cache_list_head -> next;
        while(p != nullptr) {
            delete p -> pre;
            p = p -> next;
        }   
        delete p_cache_list_near;
        cache_hash.clear();
    }
    
    int get(int key) {
        if(cache_hash.find(key) != cache_hash.end()) {
            CacheNode *p = cache_hash[key];
            detachNode(p);
            addFirstNode(p);
            
            return p -> val;
        } else
            return -1;
    }
    
    void put(int key, int value) {
        if(cache_hash.find(key) != cache_hash.end()) {
            cache_hash[key] -> val = value;
            detachNode(cache_hash[key]);
            addFirstNode(cache_hash[key]);
            if(cache_hash.size() > cache_size)
                delEndNode();
        } else {
            CacheNode *p = new CacheNode();
            p -> key = key;
            p -> val = value;
            addFirstNode(p);
            cache_hash[key] = p;
            if(cache_hash.size() > cache_size)
                delEndNode();
        }    
    }
    
private:
    typedef struct _Node_ {
        int key;
        int val;
        struct _Node_ *next;
        struct _Node_ *pre;
    } CacheNode;
    
    int cache_size;
    CacheNode *p_cache_list_head;
    CacheNode *p_cache_list_near;
    map<int, CacheNode*> cache_hash;
    
    void detachNode(CacheNode *node) {
        node -> pre -> next = node -> next;
        node -> next -> pre = node -> pre;
    }
    
    void addFirstNode(CacheNode *node) {
        node -> pre = p_cache_list_head;
        if(cache_hash.empty()) {
            node -> next = p_cache_list_near;
            p_cache_list_head -> next = node;
            p_cache_list_near -> pre = node;
        } else {
            node -> next = p_cache_list_head -> next;
            p_cache_list_head -> next -> pre = node;
            p_cache_list_head -> next = node;
        }
    }
    
    void delEndNode() {
        if(!cache_hash.empty()) {
            CacheNode *p = p_cache_list_near -> pre;
            detachNode(p);
            cache_hash.erase(p -> key);
            delete(p);
        }
    }
};

int main() {
    return 0;
}