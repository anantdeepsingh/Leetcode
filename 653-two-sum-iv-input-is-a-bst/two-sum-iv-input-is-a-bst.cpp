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
    bool flag=false;
    unordered_map<int,int>mp;
    void postorder(TreeNode* root,int k){
        if(root==NULL) return;
        postorder(root->left,k);
        postorder(root->right,k);
        int rem=k-root->val;
        if(mp.count(rem)){
            flag=true;
        }
        mp[root->val]++;
    }
    bool findTarget(TreeNode* root, int k) {
        postorder(root,k);
        return flag;
    }
};