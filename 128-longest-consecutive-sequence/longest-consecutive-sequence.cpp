class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       map<int,int>mp;
       int n=nums.size();
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
       }


       vector<int>a;
       for(auto it:mp){
        a.push_back(it.first);
       }

        if(a.size()==0) return 0;
       int len=1;
       int cnt=1;
       for(auto it:a){
        cout<<it<<" ";
       }
       for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]==1){
                cnt++;
            }
            else{
                len=max(len,cnt);
                cnt=1;
            }
       }
       len=max(len,cnt);
       return len;
    }
};