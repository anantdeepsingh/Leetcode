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
    int calcHeight(TreeNode* root,bool &flag){
        if(root==NULL) return 0;
        int lh=calcHeight(root->left,flag);
        int rh=calcHeight(root->right,flag);
        if(abs(lh-rh)>1){
            flag=false;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        calcHeight(root,flag);
        return flag;
    }
};