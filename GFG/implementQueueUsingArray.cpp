/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    if(front == 0){front = rear = 1; arr[rear] = x;}
    else{arr[++rear] = x;}
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{   
    if(front == 0){return -1;}
    
    int popped = arr[front];
    
    if(front == rear){front = rear = 0;}
    else{front++;}
    
    return popped;
}