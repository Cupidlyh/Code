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
    //深度优先搜索克隆图
    unordered_map<int,Node*> s;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
        Node* cloneNode = new Node(node -> val);
         // 哈希表存储
        s[node -> val] = cloneNode;
        // 遍历该节点的邻居并更新克隆节点的邻居列表
        for(int i = 0; i < node -> neighbors.size(); i++) {
            // 如果该节点没有被访问过，则继续深度优先搜索
            if(s.find(node -> neighbors[i] -> val) == s.end())
                cloneNode -> neighbors.push_back(cloneGraph(node -> neighbors[i]));
            // 如果该节点已经被访问过，则直接从哈希表中取出对应的克隆节点
            else 
                cloneNode -> neighbors.push_back(s[node -> neighbors[i] -> val]);
        }
        return cloneNode;
    }
};