/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void build(TreeNode* root,int num){
        if(num < root->val){
            if(root->left != NULL)
                build(root->left,num);
            else{
                TreeNode *node = new TreeNode(num);
                root->left = node;
            }
        }
        else{
            if(root->right != NULL)
                build(root->right,num);
            else{
                TreeNode *node = new TreeNode(num);
                root->right = node;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();++i){
            build(root,preorder[i]);
        }
        
        
        return root;
    }
};