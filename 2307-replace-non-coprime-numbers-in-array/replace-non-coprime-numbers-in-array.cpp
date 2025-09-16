class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // deque<int>dq;
        // for(auto &it:nums){
        //     dq.push_back(it);
        // }
        // vector<int>ans;
        // while(dq.size()>1){
        //     int top1=dq.front();
        //     dq.pop_front();
        //     int top2=dq.front();
        //     dq.pop_front();
        //     int hcf=__gcd(top1,top2);
        //     if(hcf==1){
        //         // cout<<top1<<endl;
        //         ans.push_back(top1);
        //         dq.push_front(top2);
        //     }
        //     else{
        //         // cout<<top1<<" "<<top2<<endl;
        //         long long lcm=(1ll*top1*top2)/hcf;
        //         // cout<<lcm<<endl;
        //         dq.push_front(lcm);
        //     }
        // }
        // ans.push_back(dq.front());


        vector<int>res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int hcf=__gcd(nums[i],res.back());
            cout<<hcf<<endl;
            if(hcf==1){
                int k=10;
                while(k>1 && res.size()>1){
                    int top1=res.back();
                    res.pop_back();
                    int top2=res.back();
                    res.pop_back();
                    k=__gcd(top1,top2);
                    if(k==1){
                        res.push_back(top2);
                        res.push_back(top1);
                        break;
                    }
                    else{
                        long long lcm=(1ll*top1*top2)/k;
                        res.push_back(lcm);
                    }
                }
                res.push_back(nums[i]);
            }
            else{
                long long lcm=(1ll*nums[i]*res.back())/hcf;
                res.pop_back();
                cout<<lcm<<endl;
                res.push_back(lcm);

            }
        }
        int k=10;
        while(k>1 && res.size()>1){
            int top1=res.back();
            res.pop_back();
            int top2=res.back();
            res.pop_back();
            k=__gcd(top1,top2);
            if(k==1){
                res.push_back(top2);
                res.push_back(top1);
                break;
            }
            else{
                long long lcm=(1ll*top1*top2)/k;
                res.push_back(lcm);
            }
        }
        return res;
    }
};