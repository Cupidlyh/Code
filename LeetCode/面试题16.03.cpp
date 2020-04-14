class Solution {
public:
    // �ж� (xk, yk) �Ƿ��ڡ��߶Ρ�(x1, y1)~(x2, y2) ��
    // �����ǰ���� (xk, yk) һ���ڡ�ֱ�ߡ�(x1, y1)~(x2, y2) ��
    bool inside(int x1, int y1, int x2, int y2, int xk, int yk) {
        // ���� x ��ƽ�У�ֻ��Ҫ�ж� x �Ĳ���
        // ���� y ��ƽ�У�ֻ��Ҫ�ж� y �Ĳ���
        // ��Ϊ��ͨ�߶Σ���Ҫ�ж�
        return (x1 == x2 || (min(x1, x2) <= xk && xk <= max(x1, x2))) && (y1 == y2 || (min(y1, y2) <= yk && yk <= max(y1, y2)));
    }

    void update(vector<double>& ans, double xk, double yk) {
        // ��һ�������뵱ǰ ans �еĽ�����бȽ�
        // ���������滻
        if (!ans.size() || xk < ans[0] || (xk == ans[0] && yk < ans[1])) {
            ans = {xk, yk};
        }
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int x1 = start1[0], y1 = start1[1];
        int x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1];
        int x4 = end2[0], y4 = end2[1];

        vector<double> ans;
        // �ж� (x1, y1)~(x2, y2) �� (x3, y3)~(x4, y3) �Ƿ�ƽ��
        if ((y4 - y3) * (x2 - x1) == (y2 - y1) * (x4 - x3)) {
            // ��ƽ�У����ж� (x3, y3) �Ƿ��ڡ�ֱ�ߡ�(x1, y1)~(x2, y2) ��
            if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
                // �ж� (x3, y3) �Ƿ��ڡ��߶Ρ�(x1, y1)~(x2, y2) ��
                if (inside(x1, y1, x2, y2, x3, y3)) {
                    update(ans, (double)x3, (double)y3);
                }
                // �ж� (x4, y4) �Ƿ��ڡ��߶Ρ�(x1, y1)~(x2, y2) ��
                if (inside(x1, y1, x2, y2, x4, y4)) {
                    update(ans, (double)x4, (double)y4);
                }
                // �ж� (x1, y1) �Ƿ��ڡ��߶Ρ�(x3, y3)~(x4, y4) ��
                if (inside(x3, y3, x4, y4, x1, y1)) {
                    update(ans, (double)x1, (double)y1);
                }
                // �ж� (x2, y2) �Ƿ��ڡ��߶Ρ�(x3, y3)~(x4, y4) ��
                if (inside(x3, y3, x4, y4, x2, y2)) {
                    update(ans, (double)x2, (double)y2);
                }
            }
            // ��ƽ��ʱ���������������������н���
        }
        else {
            // �������̵õ� t1 �� t2 ��ֵ
            double t1 = (double)(x3 * (y4 - y3) + y1 * (x4 - x3) - y3 * (x4 - x3) - x1 * (y4 - y3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
            double t2 = (double)(x1 * (y2 - y1) + y3 * (x2 - x1) - y1 * (x2 - x1) - x3 * (y2 - y1)) / ((x4 - x3) * (y2 - y1) - (x2 - x1) * (y4 - y3));
            // �ж� t1 �� t2 �Ƿ���� [0, 1] ֮��
            if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0) {
                ans = {x1 + t1 * (x2 - x1), y1 + t1 * (y2 - y1)};
            }
        }
        return ans;
    }
};
