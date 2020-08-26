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
    vector<int> inorderTraversalXXX(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode *cur = root;
        while(cur || !s.empty()){ // cur || !s.empty()
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
                
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                TreeNode* rptr = cur->left;
                while(rptr->right && rptr->right!=cur)
                    rptr = rptr->right;
                if(!rptr->right){ // first time traversal, rptr = parent node
                    rptr->right = cur;
                    cur = cur->left;
                }
                else{ //rptr == parent node, we have done all the left subtree, we should go right
                    rptr->right = NULL;// stop infinite loop
                    //printf("%d ,",cur->val);
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
            else{
                //printf("%d ,",cur->val);
                ans.push_back(cur->val);
                cur = cur->right;
            }
                
        }
        return ans;
    }
};