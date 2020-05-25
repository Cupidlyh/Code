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
        //ʹ��αͷ����αβ���ڵ�
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        size = capacity;

    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        //���key���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
        DLinkedNode* node = cache[key];
        removeNode(node);
        addToHead(node);
        return node -> val;
    }

    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            //���key�����ڣ�����һ���µĽڵ�
            DLinkedNode* node = new DLinkedNode(key, value);
            //��ӽ���ϣ��
            cache[key] = node;
            //�����˫�������ͷ��
            addToHead(node);
            size--;
            if(size < 0) {
                //�������������ɾ��˫�������β���ڵ�
                DLinkedNode* removed = tail -> prev;
                removeNode(removed);
                //ɾ����ϣ���ж�Ӧ����
                cache.erase(removed -> key);
                size++;
            }
        }
        else {
            //���key���ڣ���ͨ����ϣ��λ�����޸�value�����Ƶ�ͷ��
            DLinkedNode* node = cache[key];
            node -> val = value;
            removeNode(node);
            addToHead(node);
        }
    }

    void removeNode(DLinkedNode* node) {//��˫���������Ƴ�һ���ڵ�
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void addToHead(DLinkedNode* node) {//��һ���ڵ�ӵ�ͷ��
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
