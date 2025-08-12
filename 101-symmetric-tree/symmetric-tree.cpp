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
    bool Check(TreeNode* p,TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        if(p->val!=q->val) return false;

        return Check(p->left,q->right) && Check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     vector<string>v;
        //     int sz=q.size();
        //     for(int i=0;i<sz;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         if(node){
        //             v.push_back(to_string(node->val));
        //             q.push(node->left);
        //             q.push(node->right);
        //         }
        //         else{
        //             v.push_back("*");
        //         }
        //     }

        //     int l=0,r=v.size()-1;
        //     while(l<r){
        //         if(v[l]!=v[r]) return false;
        //         l++;
        //         r--;
        //     }
        // }

        // return true;


        if(root==NULL) return true;

        return Check(root->left,root->right);

    }
};