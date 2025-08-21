class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>sum(m,0);
            for(int j=0;j<m;j++){
                if(i!=0){
                    if(mat[i][j]==0) continue;
                    mat[i][j]=mat[i-1][j]+1;
                }
            }

            stack<int>st;
            vector<int>left(m);
            for(int j=0;j<m;j++){
                if(st.empty()){
                    left[j]=-1;
                }
                while(!st.empty() && mat[i][j]<=mat[i][st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    left[j]=-1;
                }
                else{
                    left[j]=st.top();
                }
                st.push(j);
            }


            for(int j=0;j<m;j++){
                int ind=left[j];
                if(ind==-1){
                    sum[j]=(j+1)*mat[i][j];
                }
                else{
                    sum[j]=sum[ind]+(j-ind)*mat[i][j];
                }
            }

            for(int j=0;j<m;j++){
                ans+=sum[j];
            }
        }
        return ans;
    }
};



