/*
We need min at all time ,so we keep a mini var but ,when we remove top value,
We need a marker that tell us the value that will be removed is actual min or not.
if we encounter a val such that it is less than mini => val<mini.
Add val both side 2*val<mini+val,
Rearrange it to get 2*val-mini<val, lets call 2*val-mini = encodedVal
so, encodedVal<val
this work as marker, if encodedVal<mini then its indication its encodedVersion of prevMin.
*/
class MinStack {
public:
    vector<long long > st;
    long long mini;
    MinStack() {}

    void push(int val)
    {
       //For first value we simply add in stack and set as mini
       if(st.size()==0)
       {
            st.push_back(val);
            mini = val;
       }
       //Case Where incoming val is minimum
       //so we push encodedVal in stack
       else if(val<mini)
       {
            //encodedVal = 2*val-mini
            st.push_back((long long)2*val-mini);
            mini = val;
       }
       //else we can normally push into stack
       else
       {
            st.push_back(val);
       }
    }

    void pop()
    {
        //if we encounter top val is even than mini ie its encoded val
        //this means value at mini is actual top
        if(st.back()<mini)
        {
            /*
            now we neede to retrieve prevMini
            we know ,
            2*val-mini = encodedVal
            mini = 2*val-encodedVal
            here val = is current mini
            and encodedVal is stored in top of stack
            */
            mini = 2*mini - st.back();
            //we pop to remove encoded val
            st.pop_back();
        }
        //otherwise normally remove from stack
        else
        st.pop_back();
    }

    int top()
    {
        //now we need to check if at top we haev encodedVal or normal val
        if(st.back()<mini)
        {
            //means at top there is enoceded val at real value is at mini
            return mini;
        }
        //otherwise 
        return st.back();
    }

    int getMin()
    {
        return mini;
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