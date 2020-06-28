/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";//存储二叉树序列化的结果
        if(root) {//先序遍历（根左右）
            int val = root -> val;
            if(val < 0) {//对负数进行处理
                res += '-';//结果中加负号
                val *= -1;//变成正数
            }
            if(val == 0)//值为0的情况
                res += 0 + '0';
            string temp = "";
            while(val) {//将正整数转成字符串
                temp += val % 10 + '0';
                val /= 10;
            }
            reverse(temp.begin(),temp.end());//字符串翻转
            res += temp;
            res += ',';//','目的是将数字隔开
            if(root -> left) {
                res += serialize(root -> left);
            }
            else {//'#'目的是在反序列化时告诉它此处是空节点
                res += '#';
            }
            if(root -> right) {
                res += serialize(root -> right);
            }
            else {
                res += '#';
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* res = nullptr;
        int temp = buildtree(&res,data,0);
        return res;
    }

    //先序建立二叉树
    int buildtree(TreeNode** res,string& data,int i) {//i为data字符串应该从哪里开始遍历
        int j,b;
        for(j = i; j < data.length(); j++) {
            if(data[j] == ',')
                continue;
            else if(data[j] == '#') {//'#'是空节点
                *res = nullptr;
                return j + 1;
            }
            else {
                int flag = 0;
                if(data[j] == '-')//是否为负数
                    flag = 1;
                int begin = j + flag,end = j + flag;//记录数字的开始和结束位置
                while(end < data.length() && data[end] != ',')
                    end++;
                j = end - 1;
                int val = stoi(data.substr(begin, end - begin));//将字符串转成数字
                if(flag) {
                    *res = new TreeNode(-1 * val);
                }
                else {
                    *res = new TreeNode(val);
                }
                int a = buildtree(&(*res)->left,data,j + 1);//递归建立左子树
                b = buildtree(&(*res)->right,data,a);//递归建立右子树
                break;
            }
        }
        return b;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
