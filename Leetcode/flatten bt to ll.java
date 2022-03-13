/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode preT(TreeNode root){
        if(root==null) return null;
        if(root.right!=null){
            TreeNode r= root.right;
            root.right=preT(root.left);
            root.left=null;
            TreeNode temp = root;
            while(temp.right!=null){
                temp=temp.right;
            }
            temp.right=preT(r);
        }
         else{
             if(root.left!=null)
                root.right=preT(root.left);
             root.left=null;
         }
        return root;
    }
    public void flatten(TreeNode root) {
        if(root==null) return;
        preT(root);
    }
}
