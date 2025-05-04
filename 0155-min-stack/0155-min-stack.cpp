class MinStack {
public:
    vector<pair<int , int> > v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){

            pair<int , int > p;
            p.first = val;
            p.second = val;
            v.push_back(p);
        }
        else{
            pair<int , int > p;
            p.first = val;
            int oldMin = v.back().second;
            p.second = min(oldMin , val);
            v.push_back(p);
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        pair<int , int> p = v.back();
        return p.first;
    }
    
    int getMin() {
        pair<int , int> p = v.back();
        return p.second;
        
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