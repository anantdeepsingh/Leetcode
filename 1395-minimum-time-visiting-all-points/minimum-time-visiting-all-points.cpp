class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cnt=0;
        int n=points.size();
        for(int i=1;i<n;i++){
            int xres=abs(points[i][0]-points[i-1][0]);
            int yres=abs(points[i][1]-points[i-1][1]);
            cnt+=min(xres,yres);
            cnt+=max(xres,yres)-min(xres,yres);
        }
        return cnt;
    }
};