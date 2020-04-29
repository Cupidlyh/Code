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
    //这里使用一个reverse变量搞定升序降序，当升序 reverse=1,否则 reverse=-1
    target *= reverse;  // 全部转为升序查找
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
    // 1.搜索山顶下标，一定存在，因此循环结束，left或right就是山顶下标
    int left = 0, right = length(mountainArr) - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) {
            // 一定在山顶左边
            left = mid + 1;
        } else
            right = mid - 1;
    }
    // 2.左右搜索
    int idx = bisect(mountainArr, 0, left, target, 1);//注意左边原本升序传入 1
    if (idx != -1)
        return idx;
    return bisect(mountainArr, left + 1, length(mountainArr) - 1, target, -1);//右边降序传入-1
}
