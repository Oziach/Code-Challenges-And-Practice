class MyQueue {
private:
stack<int> mainStack;
stack<int> utilStack;

void TransferToStack(stack<int>& a, stack<int>& b){
    while(!a.empty()){
        b.push(a.top());
        a.pop();
    }
}

public:

    MyQueue() {

    }
    
    void push(int x) {
        TransferToStack(mainStack, utilStack);
        mainStack.push(x);
        TransferToStack(utilStack, mainStack);
    }
    
    int pop() {
        mainStack.pop();
        return popped;
    }
    
    int peek() {
        return mainStack.top();
    }
    
    bool empty() {
        return mainStack.empty();
    }
};      int popped = mainStack.top();
  