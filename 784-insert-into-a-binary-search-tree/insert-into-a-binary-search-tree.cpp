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
    TreeNode* traverse(TreeNode* root,int val){
        if(root==NULL){
            return new TreeNode(val);
        }
        if(val>root->val){
            root->right=traverse(root->right,val);
        }
        else{
            root->left=traverse(root->left,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return traverse(root,val);
    }
};