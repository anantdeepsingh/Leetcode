class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }  
    void push(int x) {
        if(q2.size()==0){
            q2.push(x);
        }
        else{
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }

            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    int pop() {
        if(q2.size()==0) return -1;
        int top=q2.front();
        q2.pop();
        return top;
    }
    
    int top() {
        if(q2.size()==0) return -1;
        int top=q2.front();
        return top;
    }
    
    bool empty() {
        return q2.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */