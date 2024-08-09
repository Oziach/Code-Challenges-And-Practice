class MedianFinder {
private:
priority_queue<int> leftHeap;
priority_queue<int, vector<int>, greater<int>> rightHeap;

    void BalanceHeaps(){
        while(rightHeap.size() > leftHeap.size()){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }

        while(leftHeap.size() > rightHeap.size()){ //right heap always gets the extra element
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
    }

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        rightHeap.push(num);
        BalanceHeaps();
    }
    
    double findMedian() {
        if((leftHeap.size() + rightHeap.size()) & 1){
            return rightHeap.top();
        }
        else{
            return double(rightHeap.top() + leftHeap.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */