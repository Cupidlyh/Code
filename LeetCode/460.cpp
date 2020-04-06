
//缓存的节点信息
struct Node {
    int key, val, freq;//键，值，使用频率
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}//构造函数用来初始化结构体中的值
};
class LFUCache {
    int minfreq, capacity;//最小使用频率，缓存容量
    //这两个unordered_map类似于二维数组的横纵坐标（官方解的图可以看出）,所以一个改变另一个必将改变
    unordered_map<int, list<Node>::iterator> key_table;//key值为键，iterator为迭代器（所以值的类型是迭代器）
    unordered_map<int, list<Node>> freq_table;//频率为键
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();//清除内容
        freq_table.clear();//清除内容
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);//find函数返回值是指向键等于 key 的元素的迭代器。若找不到这种元素，则返回尾后迭代器
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);//从频率为freq中移除键为key的元素（get操作增加一次访问次数）
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));//从链表的头部加入进去
        key_table[key] = freq_table[freq + 1].begin();//更新
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);//从key_table中删除最近使用最少次数的
                freq_table[minfreq].pop_back();//从freq_table的链表中删除最后一项
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));//新加入的使用频率为1，所以加到1的链表的头部
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
