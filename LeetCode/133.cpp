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
    //广度优先搜索克隆图
    Node* cloneGraph(Node* node) {
         if (node == nullptr) {
            return node;
        }
        unordered_map<Node*,Node*> s;
        // 将题目给定的节点添加到队列
        queue<Node*> q;
        q.push(node);
        // 克隆第一个节点并存储到哈希表中
        s[node] = new Node(node -> val);
        // 广度优先搜索
        while(!q.empty()) {
            // 取出队列的头节点
            Node* t = q.front();
            q.pop();
            // 遍历该节点的邻居
            for(int i = 0; i < t -> neighbors.size(); i++) {
                if(s.find(t -> neighbors[i]) == s.end()) {
                    // 将邻居节点加入队列中
                    q.push(t -> neighbors[i]);
                     // 如果没有被访问过，就克隆并存储在哈希表中
                    s[t -> neighbors[i]] = new Node(t -> neighbors[i] -> val);
                }
                // 更新当前节点的邻居列表
                s[t] -> neighbors.push_back(s[t -> neighbors[i]]);
            }
        }
        return s[node];
    }
};
