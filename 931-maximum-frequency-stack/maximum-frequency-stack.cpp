/*
    the stack is really just a heap that stores a value
    however the heap uses a capture by reference lambda that checks a hashmap for freqs
    push means incrementing the hashmap value and pushing onto the heap
    popping means decrementing the value and popping from heap
    is the heap property restored after popping though?? yes
    but then how to we naturally break ties by freshness??
    store a counter in each hashmap value as well and update it on push / reference it in the lambda
*/

class FreqStack {
public:
    FreqStack() = default;
    
    void push(int val) {
        heap_.push({val, ++freqs_[val], time++});
    }
    
    int pop() {
        int res{heap_.top()[0]};
        heap_.pop();
        freqs_[res]--;
        return res;
    }

private: 
    std::priority_queue<
        vector<int>, 
        vector<vector<int>>, 
        decltype ([](vector<int> a, vector<int> b) {
            if (a[1] == b[1]) return a[2] < b[2];
            return a[1] < b[1];
        })
    > heap_;
    unordered_map<int, int> freqs_;
    int time{};
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */