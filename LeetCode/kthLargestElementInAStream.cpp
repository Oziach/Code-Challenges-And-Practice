class KthLargest {
private:
priority_queue<int, vector<int>, greater<int>> minHeap;
int k;
vector<int> nums;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;

        for(int i = 0; i < nums.size(); i++){
            
            if(minHeap.size() < k || minHeap.top() < nums[i]){
                minHeap.push(nums[i]);
            }

            while(minHeap.size() > k){
                minHeap.pop();
            }
        }

    }
    
    int add(int val) {

            if(minHeap.size() < k || minHeap.top() < val){
                minHeap.push(val);
            }

            while(minHeap.size() > k){
                minHeap.pop();
            }

            return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */