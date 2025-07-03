class ST{
    public:
    vector<int>seg;
    ST(int n){
        seg.resize(4*n+1,0);
    }
    int query(int ind,int low,int high,int l,int r){
		// no overlapping
		if(high<l || r<low) return 0;

		// complete overlapping
		if(low>=l && high<=r) return seg[ind];

		// partial overlap
		
		int mid=(low+high)/2;
		int left=query(2*ind+1,low,mid,l,r);
		int right=query(2*ind+2,mid+1,high,l,r);
		return max(left,right);
		
	}
	void update(int ind,int low,int high,int val,int i){
		if(low==high){
			seg[ind]=val;
			return;
		}

		int mid=(low+high)/2;
		if(i<=mid) update(2*ind+1,low,mid,val,i);
		else update(2*ind+2,mid+1,high,val,i);
		seg [ind]=max(seg[2*ind+1],seg[2*ind+2]);
	}
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        ST sg(maxi + 1);
        int res = 1;

        for (auto it : nums) {
            int best = 0;
            if (it > 0) {
                best = sg.query(0, 0, maxi, max(0, it - k), it - 1);
            }
            int curr = best + 1;
            int prev = sg.query(0, 0, maxi, it, it);
            sg.update(0, 0, maxi, max(prev, curr), it);
            res = max(res, curr);
        }
        return res;
    }
};