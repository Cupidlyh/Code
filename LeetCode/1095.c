/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */

int bisect(MountainArray* mountainArr, int left, int right, int target, int reverse) {
    //����ʹ��һ��reverse�����㶨�����򣬵����� reverse=1,���� reverse=-1
    target *= reverse;  // ȫ��תΪ�������
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = reverse * get(mountainArr, mid);
        if (res == target) {
            return mid;
        } else if (res < target) {
            left = mid + 1;
        } else
            right = mid - 1;
    }
    return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    // 1.����ɽ���±꣬һ�����ڣ����ѭ��������left��right����ɽ���±�
    int left = 0, right = length(mountainArr) - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) {
            // һ����ɽ�����
            left = mid + 1;
        } else
            right = mid - 1;
    }
    // 2.��������
    int idx = bisect(mountainArr, 0, left, target, 1);//ע�����ԭ�������� 1
    if (idx != -1)
        return idx;
    return bisect(mountainArr, left + 1, length(mountainArr) - 1, target, -1);//�ұ߽�����-1
}
