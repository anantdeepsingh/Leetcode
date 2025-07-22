class MyHashSet {
public:
    vector<list<int>>vec;
    int cap;
    MyHashSet() {
        vec.resize(12000);
        cap=12000;
    }
    void add(int key) {
        int rem=key%cap;
        auto it=find(vec[rem].begin(),vec[rem].end(),key);
        if(it==vec[rem].end()){
            vec[rem].push_back(key);
        }
    }
    
    void remove(int key) {
        int rem=key%cap;
        auto it=find(vec[rem].begin(),vec[rem].end(),key);
        if(it!=vec[rem].end()){
            vec[rem].erase(it);
        }
    }
    
    bool contains(int key) {
        int rem=key%cap;
        auto it=find(vec[rem].begin(),vec[rem].end(),key);
        return it!=vec[rem].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

//  this method is called seperate chaining the load factor should be less than equals 0.75