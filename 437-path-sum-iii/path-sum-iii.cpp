class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, long long sum, int targetSum, map<long long, int>&mp) {
        if (!root) return;

        sum += root->val;
        if (sum == targetSum) ans++;
        ans += mp[sum - targetSum];

        mp[sum]++;

        dfs(root->left, sum, targetSum, mp);
        dfs(root->right, sum, targetSum, mp);

        mp[sum]--; 

        if(mp[sum]==0){
            mp.erase(sum);
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int> mp;
        dfs(root, 0, targetSum, mp);
        return ans;
    }
};
