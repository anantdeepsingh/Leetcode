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
    vector<TreeNode*> solve(int n){
        if(n%2==0){
            return {};
        }
        if(n==1){
            TreeNode* root=new TreeNode(0);
            return {root};
        }

        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>l=solve(i);
            vector<TreeNode*>r=solve(n-i-1);
            for(auto &it1:l){
                for(auto *it2:r){
                    TreeNode* root=new TreeNode(0);
                    root->left=it1;
                    root->right=it2;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};
/*
    n=7
    0 1 2 3 4 5 6
    when i am at 1 i can get all from left and all from right
    merge to my root
    root->left=left;
    root->right=right;

    i cant do it with even 

*/