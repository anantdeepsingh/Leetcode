class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit){
	int n=nums.size();
	map<int,int>mp;
	int l=0,r=0;
	int maxLen=1;
	while(r<n){
		mp[nums[r]]++;
		auto it=mp.begin();
		int mini=it->first;
		auto it1=mp.rbegin();
		int maxi=(*it1).first;
		while(!mp.empty() && maxi-mini>limit){
			mp[nums[l]]--;
			if(mp[nums[l]]==0){
				mp.erase(nums[l]);
			}
			l++;
			it=mp.begin();
			mini=it->first;
			it1=mp.rbegin();
			maxi=(*it1).first;
		}
		if(maxi-mini<=limit){
			maxLen=max(maxLen,r-l+1);
		}
		r++;
	}
	return maxLen;
}
};