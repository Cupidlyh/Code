/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //�������������¡ͼ
    Node* cloneGraph(Node* node) {
         if (node == nullptr) {
            return node;
        }
        unordered_map<Node*,Node*> s;
        // ����Ŀ�����Ľڵ���ӵ�����
        queue<Node*> q;
        q.push(node);
        // ��¡��һ���ڵ㲢�洢����ϣ����
        s[node] = new Node(node -> val);
        // �����������
        while(!q.empty()) {
            // ȡ�����е�ͷ�ڵ�
            Node* t = q.front();
            q.pop();
            // �����ýڵ���ھ�
            for(int i = 0; i < t -> neighbors.size(); i++) {
                if(s.find(t -> neighbors[i]) == s.end()) {
                    // ���ھӽڵ���������
                    q.push(t -> neighbors[i]);
                     // ���û�б����ʹ����Ϳ�¡���洢�ڹ�ϣ����
                    s[t -> neighbors[i]] = new Node(t -> neighbors[i] -> val);
                }
                // ���µ�ǰ�ڵ���ھ��б�
                s[t] -> neighbors.push_back(s[t -> neighbors[i]]);
            }
        }
        return s[node];
    }
};
