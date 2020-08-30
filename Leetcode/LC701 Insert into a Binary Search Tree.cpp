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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *curr = root;
        if(root == NULL)
            root = new TreeNode(val);
        while(curr){
            if(val > curr->val){
                if(curr->right){
                    curr = curr->right;
                }
                else{
                    TreeNode * n = new TreeNode(val);
                    curr->right = n;
                    break;
                }
            }
            else{
                if(curr->left){
                    curr = curr->left;
                }
                else{
                    TreeNode *n = new TreeNode(val);
                    curr->left = n;
                    break;
                }
            }
        }
        return root;
    }
};