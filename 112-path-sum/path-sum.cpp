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
    bool dfs(TreeNode* root,int sum,int targetSum){
        if(root!=NULL && root->left==NULL && root->right==NULL){
            sum+=root->val;
            if(sum==targetSum) return 1;
            return 0;
        }

        if(root!=NULL && root->left){
            if(dfs(root->left,sum+root->val,targetSum)) return true;
        }
        if(root!=NULL && root->right){
            if(dfs(root->right,sum+root->val,targetSum)) return true;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,0,targetSum);
    }
};