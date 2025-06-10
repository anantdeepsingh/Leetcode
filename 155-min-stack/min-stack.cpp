class MinStack {
public:
    stack<int>st;
    map<int,int>mp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        int top=st.top();
        st.pop();
        mp[top]--;
        if(mp[top]==0){
            mp.erase(top);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it=mp.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */