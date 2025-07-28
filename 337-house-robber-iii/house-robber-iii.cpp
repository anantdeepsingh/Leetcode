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
    map<pair<TreeNode*,int>,int>mp;
    int amount(TreeNode* node,int robbed){
        if(node==NULL) return 0;
        if(mp.count({node,robbed})) return mp[{node,robbed}];
        int ans=0;
        if(robbed){
            int op1=amount(node->left,0);
            op1+=amount(node->right,0);
            ans=max(ans,op1);
        }
        else{
            int op1=node->val;
            op1+=amount(node->left,1);
            op1+=amount(node->right,1);

            int op2=amount(node->left,0)+amount(node->right,0);

            ans=max(ans,max(op1,op2));
        }
        return mp[{node,robbed}]=ans;
    }
    int rob(TreeNode* root) {
        return amount(root,0);
    }
};