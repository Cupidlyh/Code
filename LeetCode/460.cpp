
//����Ľڵ���Ϣ
struct Node {
    int key, val, freq;//����ֵ��ʹ��Ƶ��
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}//���캯��������ʼ���ṹ���е�ֵ
};
class LFUCache {
    int minfreq, capacity;//��Сʹ��Ƶ�ʣ���������
    //������unordered_map�����ڶ�ά����ĺ������꣨�ٷ����ͼ���Կ�����,����һ���ı���һ���ؽ��ı�
    unordered_map<int, list<Node>::iterator> key_table;//keyֵΪ����iteratorΪ������������ֵ�������ǵ�������
    unordered_map<int, list<Node>> freq_table;//Ƶ��Ϊ��
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();//�������
        freq_table.clear();//�������
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);//find��������ֵ��ָ������� key ��Ԫ�صĵ����������Ҳ�������Ԫ�أ��򷵻�β�������
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);//��Ƶ��Ϊfreq���Ƴ���Ϊkey��Ԫ�أ�get��������һ�η��ʴ�����
        // �����ǰ����Ϊ�գ�������Ҫ�ڹ�ϣ����ɾ�����Ҹ���minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // ���뵽 freq + 1 ��
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));//�������ͷ�������ȥ
        key_table[key] = freq_table[freq + 1].begin();//����
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // ������������Ҫ����ɾ������
            if (key_table.size() == capacity) {
                // ͨ�� minFreq �õ� freq_table[minFreq] �����ĩβ�ڵ�
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);//��key_table��ɾ�����ʹ�����ٴ�����
                freq_table[minfreq].pop_back();//��freq_table��������ɾ�����һ��
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));//�¼����ʹ��Ƶ��Ϊ1�����Լӵ�1�������ͷ��
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // �� get ��������һ�£�������Ҫ���»����ֵ
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
