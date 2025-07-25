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
 #define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0ll});
        ll ans=1ll;
        while(!q.empty()){
            int sz=q.size();
            ll mn=1e12;
            ll mx=-1e12;
            ll mini=q.front().second;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front().first;
                ll ind=q.front().second-mini;
                q.pop();
                if(node->left){
                    ll nind=1ll*2*ind+1;
                    mn=min(mn,nind);
                    mx=max(mx,nind);
                    q.push({node->left,nind});
                }
                if(node->right){
                    ll nind=1ll*2*ind+2;
                    mn=min(mn,nind);
                    mx=max(mx,nind);
                    q.push({node->right,nind});
                }
            }

            ans=max(ans,mx-mn+1);
        }

        return ans;
    }
};