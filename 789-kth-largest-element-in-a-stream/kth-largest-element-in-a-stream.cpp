class KthLargest {
public:
int k;
vector<int>nums;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->nums=nums;

        sort(this->nums.begin(),this->nums.end());
    }
    int add(int val) {
        int ind=lower_bound(nums.begin(),nums.end(),val)-nums.begin();
        nums.insert(nums.begin()+ind,val);
        int size=nums.size();
        return nums[size-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */