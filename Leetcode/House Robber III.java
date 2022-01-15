/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 */






class Solution{
    public int rob(TreeNode root) {
        return rob(root, new HashMap<>());
    }

    public int rob(TreeNode root, Map<TreeNode, Integer> map) {
        
        if (root == null) return 0;

        if (map.containsKey(root)) return map.get(root);

        int ans = 0;

        if (root.left != null) {
            ans += rob(root.left.left, map) + rob(root.left.right, map);
        }

        if (root.right != null) {
            ans += rob(root.right.left, map) + rob(root.right.right, map);
        }

        ans = Math.max(ans + root.val, rob(root.left, map) + rob(root.right, map));
        map.put(root, ans);

        return ans;
    }
}

/*
why to use memo when we can have a better solution without it ?

Why was the memoization needed ? Because we were going Top Down and we weren't sure whether to include the root_house at that instance or not .... So , we were making recursion calls for both cases , which led to the complication of situation and we had to cover it up with the map !!
So , instead of going that Top-down way , let's try going the deepest and then while returning back, we will decide whether to choose that house or not !
We will return the Pair here, {case_when_curr_root_is_chosen, case_when_not_chosen} ...
Let's assume any particular node (H), gets the answer from it's left child as {a,b} and right child as{x,y} ....
So , b is the case when H->left was not included and y is the case when H->right was not included... So, if we are gonna rob the House (H) , then total money we can get, p == H->val +y+b
And when House will be not robbed then maximum money robbed, q == max(a,b) + max(c,d)..... and what this node H will return is {p,q}
*/

class Solution {
private:
    pair<int,int> max_money_robbed(TreeNode* root){
        
        if(root==NULL)return {0,0};
        
        pair<int,int>left = max_money_robbed(root->left);
        pair<int,int>right = max_money_robbed(root->right);
        
        int root_house_robbed = left.second + right.second + root->val;
        int root_house_not_robbed = max(left.first,left.second)+ max(right.first,right.second);//bcoz what this needs is the answer of the subproblem of left and right 
        // subtrees which can be claculated by taking the max of the pair respectively
        pair<int,int>ans;
        
        ans.first = root_house_robbed, ans.second = root_house_not_robbed;
        
        return ans;
        
    }
public:
    int rob(TreeNode* root) {
        pair<int,int>result = max_money_robbed(root);
        return max(result.first,result.second);
    }
};

