package leetcode;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int parentval = root.val, pval = p.val, qval = q.val;
        if(pval > parentval && qval > parentval)
            return lowestCommonAncestor(root.right,p,q);
        else if(pval < parentval && qval < parentval)
            return lowestCommonAncestor(root.left,p,q);
        else
            return root;
    }
}
