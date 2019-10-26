package leetcode84;

public class Solution {
	public int largestRectangleArea(int[] heights) {
        int maxarea = 0, minheight;
        for(int i = 0; i < heights.length; i++) {
            minheight = Integer.MAX_VALUE;
            for(int j = i; j < heights.length; j++) {//��i�����������������ɵľ��ε�������
                minheight = Math.min(minheight,heights[j]);//���εĸ��ɸ߶���͵���һ�����ξ�����
                maxarea = Math.max(maxarea,minheight * (j - i + 1));
            }
        }
        return maxarea;
    }
}
