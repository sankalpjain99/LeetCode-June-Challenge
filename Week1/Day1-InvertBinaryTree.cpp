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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        if(!(root->left) && !(root->right))
            return root;
        
        TreeNode* t1 = root->left;
        TreeNode* t2 = root->right;
        if(t1)
            root->right = invertTree(t1);
        else
            root->right=NULL;
        if(t2)
            root->left = invertTree(t2);
        else
            root->left=NULL;
        return root;
    }
};