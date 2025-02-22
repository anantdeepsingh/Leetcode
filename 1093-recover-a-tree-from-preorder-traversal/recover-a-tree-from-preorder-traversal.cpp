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
    TreeNode* solve(string &s,int &i, int depth){
        if(i>=s.size()) return NULL;
        int j=i;
        while(j<s.size() && s[j]=='-'){
            j++;
        }
        int dash=j-i;
        while(dash!=depth) return NULL;
        i=j;
        int num=0;
        while(i<s.size() && isdigit(s[i])){
            num=num*10+(s[i]-'0');
            i++;
        }

        TreeNode* root=new TreeNode(num);
        root->left=solve(s,i,depth+1);
        root->right=solve(s,i,depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string t) {
        
        int i=0;
        int depth=0;
        return solve(t,i,depth);
    
    }
};