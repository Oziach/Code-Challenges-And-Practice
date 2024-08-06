//can also be easily done using a single queue

class MyStack {
private:
queue<int>* mainQueue;
queue<int>* utilQueue;

public:
    MyStack() {
        mainQueue = new queue<int>;
        utilQueue = new queue<int>;
    }
    
    void push(int x) {
        swap(mainQueue, utilQueue);
        mainQueue->push(x);

        while(!utilQueue->empty()){
            mainQueue->push(utilQueue->front());
            utilQueue->pop();
        }
    }
    
    int pop() {
        if(mainQueue->empty()){return -1;}
        
        int popped = mainQueue->front();
        mainQueue->pop();

        return popped;
    }
    
    int top() {
        return mainQueue->front();
    }
    
    bool empty() {
        return mainQueue->empty();
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