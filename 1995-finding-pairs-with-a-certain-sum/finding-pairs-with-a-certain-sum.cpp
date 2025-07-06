class FindSumPairs {
public:
    vector<int>nums1,nums2;
    unordered_map<int,int>mp;
    unordered_map<int,int>pos;
    int m,n;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto &it:nums2){
            mp[it]++;
        }
        this->nums2=nums2;
        m=this->nums2.size();
        for(int i=0;i<m;i++){
            pos[i]=nums2[i];
        }
        this->nums1=nums1;
        n=this->nums1.size();
    }
    void add(int index, int val) {
        int t=pos[index];
        mp[t]--;
        mp[t+val]++;
        pos[index]=t+val;
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<n;i++){
            int left=tot-nums1[i];
            if(mp.count(left)){
                cnt+=mp[left];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */