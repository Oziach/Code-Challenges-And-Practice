void MyQueue:: push(int x)
{
    QueueNode* newNode = new QueueNode(x);
    if(rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = rear->next;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front == NULL){return -1;}
    int popped = front->data;
    

    QueueNode* oldFront = front;
    if(front == rear){front = rear = NULL;}
    else{front = front->next;}
    
    delete oldFront;
    
    return popped;
}
