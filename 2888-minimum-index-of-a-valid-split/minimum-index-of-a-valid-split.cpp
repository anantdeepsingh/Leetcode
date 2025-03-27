class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        int dominant_number=0;
        int tcnt=0;
        for(auto it:mp){
            if(it.second>n/2){
                dominant_number=it.first;
                tcnt=it.second;
            }
        }


        for(int i=0;i<n-1;i++){
            if(nums[i]==dominant_number){
                cnt++;
            }

            int len1=i+1;
            int len2=n-i-1;
            if(cnt>len1/2 && (tcnt-cnt)>len2/2){
                return i;
            }
        }

        return -1;
    }
};