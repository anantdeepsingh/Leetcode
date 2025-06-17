class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int k=n+m;
        k=k/2+1;

        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x=0;x<n;x++){
            pq.push(nums1[x]);
        }

        for(int x=0;x<m;x++){
            pq.push(nums2[x]);
        }
        int a,b;
        while(!pq.empty()>0 && k>0){
            int val=pq.top();
            pq.pop();

            if(k==1){
                a=val;
            }
            if(k==2){
                b=val;
            }

            k--;
        }
        cout<<a<<" "<<b<<endl;
        if((n+m)%2==0){
            return ((a+b)/(double)2);
        }
        return (double)a;
    }
};