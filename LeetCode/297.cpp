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
        string res = "";//�洢���������л��Ľ��
        if(root) {//��������������ң�
            int val = root -> val;
            if(val < 0) {//�Ը������д���
                res += '-';//����мӸ���
                val *= -1;//�������
            }
            if(val == 0)//ֵΪ0�����
                res += 0 + '0';
            string temp = "";
            while(val) {//��������ת���ַ���
                temp += val % 10 + '0';
                val /= 10;
            }
            reverse(temp.begin(),temp.end());//�ַ�����ת
            res += temp;
            res += ',';//','Ŀ���ǽ����ָ���
            if(root -> left) {
                res += serialize(root -> left);
            }
            else {//'#'Ŀ�����ڷ����л�ʱ�������˴��ǿսڵ�
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

    //������������
    int buildtree(TreeNode** res,string& data,int i) {//iΪdata�ַ���Ӧ�ô����￪ʼ����
        int j,b;
        for(j = i; j < data.length(); j++) {
            if(data[j] == ',')
                continue;
            else if(data[j] == '#') {//'#'�ǿսڵ�
                *res = nullptr;
                return j + 1;
            }
            else {
                int flag = 0;
                if(data[j] == '-')//�Ƿ�Ϊ����
                    flag = 1;
                int begin = j + flag,end = j + flag;//��¼���ֵĿ�ʼ�ͽ���λ��
                while(end < data.length() && data[end] != ',')
                    end++;
                j = end - 1;
                int val = stoi(data.substr(begin, end - begin));//���ַ���ת������
                if(flag) {
                    *res = new TreeNode(-1 * val);
                }
                else {
                    *res = new TreeNode(val);
                }
                int a = buildtree(&(*res)->left,data,j + 1);//�ݹ齨��������
                b = buildtree(&(*res)->right,data,a);//�ݹ齨��������
                break;
            }
        }
        return b;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
