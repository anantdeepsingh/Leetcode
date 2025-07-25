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
    void traverse(TreeNode* root,stack<TreeNode*>&st){
        if(root==NULL) return;
        st.push(root);
        traverse(root->right,st);
        traverse(root->left,st);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*>st;
        vector<int>v;
        st.push(root);
        while(!st.empty()){
            TreeNode* top=st.top();
            st.pop();
            v.push_back(top->val);
            if(top->left){
                st.push(top->left);
            }
            if(top->right){
                st.push(top->right);
            }
        }

        reverse(v.begin(),v.end());
        return v;
    }
};