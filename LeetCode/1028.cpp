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
    int bit;//�ַ�����ǰ���������±�
    TreeNode* buildtree(string& S,int num) {//num�ǵ�ǰ�ڵ�����
        int begin = bit,end = bit;//��¼���ֿ�ʼ�ͽ�����λ��
        while(S[end] != '-' && end < S.length())
            end++;
        int val = stoi(S.substr(begin, end - begin));//�ַ���ת������
        bit = end - 1;
        TreeNode* res = new TreeNode(val);
        int l = 0;//��¼�¸���ڵ�����
        int bitt = bit;//�ڵ���Ȳ��Ի��ݵ���һ��ʱ�±�ҲҪ����
        for(int i = bit + 1; i < S.length(); i++) {
            if(S[i] == '-')
                l++;
            else {
                bit = i;
                break;
            }
        }
        if(l == num + 1) {//��һ�ڵ������Ҫ����һ�ڵ���ȼ�1
            res -> left = buildtree(S,l);
        }
        else {//�������
            bit = bitt;
            res -> left = nullptr;
            return res;
        }
        int r = 0;//��¼�¸��ҽڵ�����
        bitt = bit;//�ڵ���Ȳ��Ի��ݵ���һ��ʱ�±�ҲҪ����
        for(int i = bit + 1; i < S.length(); i++) {
            if(S[i] == '-')
                r++;
            else {
                bit = i;
                break;
            }
        }
        if(r == num + 1) {//��һ�ڵ������Ҫ����һ�ڵ���ȼ�1
            res -> right = buildtree(S,r);
        }
        else {//�������
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
