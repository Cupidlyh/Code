/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int bit;//字符串当前遍历到的下标
    TreeNode* buildtree(string& S,int num) {//num是当前节点的深度
        int begin = bit,end = bit;//记录数字开始和结束的位置
        while(S[end] != '-' && end < S.length())
            end++;
        int val = stoi(S.substr(begin, end - begin));//字符串转成数字
        bit = end - 1;
        TreeNode* res = new TreeNode(val);
        int l = 0;//记录下个左节点的深度
        int bitt = bit;//节点深度不对回溯到上一层时下标也要回溯
        for(int i = bit + 1; i < S.length(); i++) {
            if(S[i] == '-')
                l++;
            else {
                bit = i;
                break;
            }
        }
        if(l == num + 1) {//下一节点深度需要是上一节点深度加1
            res -> left = buildtree(S,l);
        }
        else {//否则回溯
            bit = bitt;
            res -> left = nullptr;
            return res;
        }
        int r = 0;//记录下个右节点的深度
        bitt = bit;//节点深度不对回溯到上一层时下标也要回溯
        for(int i = bit + 1; i < S.length(); i++) {
            if(S[i] == '-')
                r++;
            else {
                bit = i;
                break;
            }
        }
        if(r == num + 1) {//下一节点深度需要是上一节点深度加1
            res -> right = buildtree(S,r);
        }
        else {//否则回溯
            bit = bitt;
            res -> right = nullptr;
            return res;
        }
        return res;
    }

    TreeNode* recoverFromPreorder(string S) {
        return buildtree(S,0);
    }
};
