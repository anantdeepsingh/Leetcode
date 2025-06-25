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
    vector<int>v;
    void f(TreeNode* root){
        if(root==NULL) return;
        f(root->left);
        if(root!=NULL) v.push_back(root->val);
        f(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root);
        return v[k-1];
    }
};