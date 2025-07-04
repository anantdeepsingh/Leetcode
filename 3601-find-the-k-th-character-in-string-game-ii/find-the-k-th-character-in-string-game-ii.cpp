class Solution {
public:
    int rec(vector<int> &operations, long long k){
        if(k==1){
            return 0 ;
        }
       long long pos=0;
       while((1LL<<pos)<k){
        pos++;
       }
        return (operations[pos-1]+rec(operations,k-(1LL<<(pos-1)))) ;
    }
    char kthCharacter(long long k, vector<int>& operations) {
       return (rec(operations,k)%26)+'a';
    }
};