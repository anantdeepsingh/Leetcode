class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ratio=0.0;
        int c=extraStudents;
        int n=classes.size();
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){
            double a=1.0*(classes[i][0]);
            double b=1.0*(classes[i][1]);
            double r1=a/b;
            double r2=(a+1)/(b+1);
            pq.push({1.0*(r2-r1),i});
        }

        while(extraStudents>0){
            double r=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            classes[ind][0]+=1;
            classes[ind][1]+=1;
            double a=1.0*(classes[ind][0]);
            double b=1.0*(classes[ind][1]);
            double r1=a/b;
            double r2=(a+1)/(b+1);
            pq.push({1.0*(r2-r1),ind});
            extraStudents--;
        }


        // double ratio=0.0;

        for(int i=0;i<n;i++){
            double a=1.0*(classes[i][0]);
            double b=1.0*(classes[i][1]);
            ratio+=a/b;
        }

        return ratio/n;
    }
};

// {0.5,0.33,0.8,0.2}

// {}