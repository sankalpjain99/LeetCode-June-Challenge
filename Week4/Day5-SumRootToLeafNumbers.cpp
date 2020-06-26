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
    
    void Helper(TreeNode* root,int curr,int& ans){
        if(!root)
            return;
        curr = 10*curr + root->val;
        if(!root->left && !root->right){
            ans+=curr;
            return;
        }
        Helper(root->left,curr,ans);
        Helper(root->right,curr,ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans=0;
        Helper(root,0,ans);
        return ans;
    }
};