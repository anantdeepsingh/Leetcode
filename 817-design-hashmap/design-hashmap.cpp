class MyHashMap {
public:
    vector<list<pair<int,int>>>v;
    int size;
    MyHashMap() {
        v.resize(10000);
        size=10000;
    }
    
    void put(int key, int value) {
        int rem=key%size;
        auto &chain=v[rem];
        for(auto &it:chain){
            if(it.first==key){
                it.second=value;
                return;
            }
        }

        chain.push_back({key,value});
    }
    
    int get(int key) {
        int rem=key%size;
        auto &chain=v[rem];
        for(auto &it:chain){
            if(it.first==key){
                
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int rem=key%size;
        auto &chain=v[rem];
        for(auto it=chain.begin();it!=chain.end();it++){
            if(it->first==key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */