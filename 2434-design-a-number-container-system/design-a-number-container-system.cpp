class NumberContainers {
public:

    map<int,set<int>>mp1; // for number
    map<int,int>mp2; // for index
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.find(index)==mp2.end()){
            mp2[index]=number;
            mp1[number].insert(index);
        }
        else{
            int value=mp2[index];
            if(value!=number){
                mp1[value].erase(index);
                mp2[index]=number;
                mp1[number].insert(index);
            }
        }
    }
    
    int find(int number) {
        if(mp1.find(number)!=mp1.end()){
            
            for(auto it:mp1[number]){
                return it;
            }
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */