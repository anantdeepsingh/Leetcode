class MyHashSet {
public:
    vector<int>con;
    MyHashSet() {
        con.resize(1e6+1,0);
    }
    
    void add(int key) {
        con[key]=1;
    }
    
    void remove(int key) {
        con[key]=0;
    }
    
    bool contains(int key) {
        return con[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */