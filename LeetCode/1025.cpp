class Solution {
public:
    bool divisorGame(int N) {
        //N Ϊ������ʱ�� Alice�����֣��ذܣ�N Ϊż����ʱ�� Alice ��ʤ
        if(N % 2 == 0)
            return true;
        return false;
    }
};
