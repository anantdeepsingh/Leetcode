class Spreadsheet {
public:
    vector<vector<int>>grid;
    Spreadsheet(int rows) {
        grid.assign(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-65;
        int num=0;
        for(int i=1;i<cell.size();i++){
            num=num*10+(cell[i]-'0');
        }
        grid[num][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-65;
        int num=0;
        for(int i=1;i<cell.size();i++){
            num=num*10+(cell[i]-'0');
        }
        grid[num][col]=0;
    }
    
    int getValue(string formula) {
        int ind=-1;
        for(int i=0;i<formula.size();i++){
            if(formula[i]=='+'){
                ind=i;
                break;
            }
        }
        char ch1=formula[1],ch2=formula[ind+1];
        if((ch1>=65 && ch1<=90) && (ch2>=65 && ch2<=90)){
            int col=formula[1]-65;
            int num=0;
            for(int i=2;i<ind;i++){
                num=num*10+(formula[i]-'0');
            }
            int val1=grid[num][col];
            num=0;
            col=formula[ind+1]-65;
            for(int i=ind+2;i<formula.size();i++){
                num=num*10+(formula[i]-'0');
            }
            int val2=grid[num][col];
            return val1+val2;
        }
        else if(ch1>=65 && ch1<=90){
            int val2=0;
            for(int i=ind+1;i<formula.size();i++){
                val2=val2*10+(formula[i]-'0');
            }
            int col=formula[1]-65;
            int num=0;
            for(int i=2;i<ind;i++){
                num=num*10+(formula[i]-'0');
            }
            int val1=grid[num][col];
            return val1+val2;
        }
        else if(ch2>=65 && ch2<=90){
            int val1=0;
            for(int i=1;i<ind;i++){
                val1=val1*10+(formula[i]-'0');
            }
            int num=0;
            int col=formula[ind+1]-65;
            for(int i=ind+2;i<formula.size();i++){
                num=num*10+(formula[i]-'0');
            }
            int val2=grid[num][col];
            return val1+val2;
        }
        else{
            int val1=0,val2=0;
            for(int i=1;i<ind;i++){
                val1=val1*10+(formula[i]-'0');
            }
            for(int i=ind+1;i<formula.size();i++){
                val2=val2*10+(formula[i]-'0');
            }
            return val1+val2;
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */