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
    int res;
    void dfs(TreeNode* root,string &ans){
        if(root->left==NULL && root->right==NULL){
            ans+=(root->val+'0');
            // cout<<ans<<endl;
            int t=stoi(ans);
            res+=t;
            ans.pop_back();
            return;
        }

        ans+=(root->val+'0');
        if(root->left){
            dfs(root->left,ans);
        }
        if(root->right){
            dfs(root->right,ans);
        }
        ans.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string ans="";
        res=0;
        dfs(root,ans);
        return res;
    }
};