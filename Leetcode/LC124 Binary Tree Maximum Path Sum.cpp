class Solution {
public:
    int ans;
    int dfs(TreeNode* root){
        int one=0,two=0;
        if(root->right)
            one = dfs(root->right);
        if(root->left)
            two = dfs(root->left);
        int big = max(one,two);
        ans = max(ans,root->val+big);     
        ans = max(ans,root->val+one+two); // ans can be a path from left + root +  right 
        return  max(root->val,root->val+big); // only can return left or right child path
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        int b = dfs(root);
        return max(b,ans);
    }
};