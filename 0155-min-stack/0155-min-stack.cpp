class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        } else {
            auto top = st.top();
            int min = top.second;
            if(val >= min){
                st.push({val,min});
            }else{
                st.push({val,val});
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        auto top = st.top();
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        auto top = st.top();
        return top.first;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        auto top = st.top();
        return top.second;
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