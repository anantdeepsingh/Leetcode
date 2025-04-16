class NumArray {
public:
    int n;
    vector<int>arr;
    vector<int>bit;
    void fill(int i,int x){
        for(int ;i<=n;i+=(i&(-i))){
            bit[i]+=x;
        }
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr.assign(n+1,0);
        bit.assign(n+1,0);
        for(int i=1;i<=n;i++){
            arr[i]=nums[i-1];
            fill(i,arr[i]);
        }
    }
    
    void update(int i, int val) {
        i++;
        fill(i,val-arr[i]);
        arr[i]=val;
    }

    int sum(int i){
        int ans=0;
        for(;i>0;i-=(i&(-i))){
            ans+=bit[i];
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */