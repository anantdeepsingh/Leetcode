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

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<string>v;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node){
                    v.push_back(to_string(node->val));
                    q.push(node->left);
                    q.push(node->right);
                }
                else{
                    v.push_back("*");
                }
            }

            int l=0,r=v.size()-1;
            while(l<r){
                if(v[l]!=v[r]) return false;
                l++;
                r--;
            }
        }

        return true;
    }
};