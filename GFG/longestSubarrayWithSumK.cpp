class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int,int> sumToInd;
        int sum = 0;
        int longest = 0;
        sumToInd[0] = -1;
        
        for(int i = 0; i < N; i++){
            sum += A[i];
            
            if(!sumToInd.count(sum))
                sumToInd[sum] = i;
            
            if(sumToInd.count(sum-K))
                longest = max(longest, i - sumToInd[sum - K]);
                

            
        }
        
        return longest;
    } 
};