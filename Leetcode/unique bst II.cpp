class Solution {
public:
vector<TreeNode*> helper(int start,int end) {
vector<TreeNode*> ans;
    if(start>end){
        ans.push_back(NULL);
        return ans;
    }
    for(int i=start;i<=end;i++){
        vector<TreeNode*> l= helper(start,i-1);
        vector<TreeNode*> r= helper(i+1,end);
        for(auto x:l){
            for(auto y:r){
                Treenode * newNode= new Treenode(i,x,y);
                ans.push_back(newNode);
            }
        }
        
        
    }
return ans;
}

vector<TreeNode*> generateTrees(int n) {
if(n == 0)
return vector<TreeNode*>();
auto ans = helper(1,n);
return ans;
}
};
