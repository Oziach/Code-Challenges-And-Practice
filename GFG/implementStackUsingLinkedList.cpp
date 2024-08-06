class MyStack {
  private:
    StackNode* top;

  public:
    void push(int x) {
        StackNode* newTop = new StackNode(x);
        newTop->next = top;
        top = newTop;
        
    }

    int pop() {
        if(top == NULL){return -1;}
        
        StackNode* oldTop = top;
        top = top->next;
        
        oldTop->next = NULL;
        int popped = oldTop->data;
        delete oldTop;
        
        return popped;
        
    }

    MyStack() { top = NULL; }
};