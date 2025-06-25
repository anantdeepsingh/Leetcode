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
    vector<string>ans;
    void path(TreeNode* root,string s){
        if(root->left==NULL && root->right==NULL){
            string t=to_string(root->val);
            s+=t;
            ans.push_back(s);
            return;
        }
        string t=to_string(root->val);
        cout<<t<<endl;
        string k="->";
        string p=s;
        s+=t;
        s+=k;
        if(root->left)path(root->left,s);
        if(root->right)path(root->right,s);
        s=p;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return ans;
        string s="";
        path(root,s);
        return ans;
    }
};