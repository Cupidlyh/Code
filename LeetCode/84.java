package leetcode84;

public class Solution {
	public int largestRectangleArea(int[] heights) {
        int maxarea = 0, minheight;
        for(int i = 0; i < heights.length; i++) {
            minheight = Integer.MAX_VALUE;
            for(int j = i; j < heights.length; j++) {//第i个柱形与后面柱形组成的矩形的最大面积
                minheight = Math.min(minheight,heights[j]);//柱形的高由高度最低的那一个柱形决定的
                maxarea = Math.max(maxarea,minheight * (j - i + 1));
            }
        }
        return maxarea;
    }
}
