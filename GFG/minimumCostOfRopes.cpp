class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        if(n <= 1){return 0;}
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;
        
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        while(pq.size() > 1){
            long long top1 = pq.top();
            pq.pop();
            
            long long top2 = pq.top();
            pq.pop();
            
            long long newLength = top1 + top2;
            
            sum += newLength;
            pq.push(newLength);
        }
        
        return sum;
    }
};