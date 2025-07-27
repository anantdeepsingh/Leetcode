class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=1;
        int ind=0;
        while(k>0 && ind<arr.size()){
            if(start==arr[ind]){
                ind++;
                start++;
                continue;
            }
            else{
                k--;
            }
            start++;
        }

        while(k>0){
            start++;
            k--;
        }

        return start-1;
    }
};