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

    // state 0 any child must not monitored
    // state 1 any of the childfren is monitored 
    // state 2 your child is already monitored but no camera 
    int ans;
    int dfs(TreeNode* root){
        if(root==NULL) return 2;
        int left=dfs(root->left);
        int right=dfs(root->right);
        
        if(left==0 || right==0){
            ans++;
            return 1;
        }
        if(left==1 || right==1){
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        ans=0;
        if(dfs(root)==0){
            ans++;
        }
        return ans;
    }
};