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
    void traverse(TreeNode* root,vector<int>&p){
        if(root==NULL) return;
        p.push_back(root->val);
        traverse(root->left,p);
        traverse(root->right,p);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        
        traverse(root,preorder);
        return preorder;
    }
};