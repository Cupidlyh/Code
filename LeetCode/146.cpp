struct DLinkedNode {
    int key, val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;

    LRUCache(int capacity) {
        //使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        size = capacity;

    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        //如果key存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        removeNode(node);
        addToHead(node);
        return node -> val;
    }

    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            //如果key不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            //添加进哈希表
            cache[key] = node;
            //添加至双向链表的头部
            addToHead(node);
            size--;
            if(size < 0) {
                //如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = tail -> prev;
                removeNode(removed);
                //删除哈希表中对应的项
                cache.erase(removed -> key);
                size++;
            }
        }
        else {
            //如果key存在，先通过哈希表定位，再修改value，并移到头部
            DLinkedNode* node = cache[key];
            node -> val = value;
            removeNode(node);
            addToHead(node);
        }
    }

    void removeNode(DLinkedNode* node) {//从双向链表中移除一个节点
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void addToHead(DLinkedNode* node) {//将一个节点加到头部
        node -> prev = head;
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
