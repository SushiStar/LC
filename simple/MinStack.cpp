class MinStack {
public:
    std::vector<int> sorted;
    std::stack<int> sk;
    int min;
    
    /** initialize your data structure here. */
    MinStack() {
            
    }
    
    int breakpoint(int x) {
        int a = 0; // left
        int b = sorted.size()-1;
        int mid = -1;
        
        mid = (a+b)/2;
        while (mid!=a && mid !=b) {
            if (x == sorted[mid]) return mid;
            if (x < sorted[mid]) b = mid;
            else a = mid;
            mid = (a+b)/2;
        }
        return b;
    }
    
    void push(int x) {
        sk.push(x);
        if(sorted.empty() || sorted.back() < x) sorted.push_back(x);
        else if(sorted.front() > x) sorted.insert(sorted.begin(),x);
        else {
            int pos = breakpoint(x);
            sorted.insert(sorted.begin()+pos, x);
        }
    }
    
    void pop() {
        if(sk.empty()) return;
        auto temp = sk.top();
        sk.pop();
        auto pos = breakpoint(temp);
        if (sorted[pos] != temp) --pos;
        sorted.erase(begin()+pos, begin()+pos+1);

    }
    
    int top() {
        if (sk.empty()) return -1;
        return sk.top();
    }
    
    int getMin() {
        if (sorted.empty()) return -1;
        return sorted[0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
