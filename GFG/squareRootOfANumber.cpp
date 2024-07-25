class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int s = 1;
        long long int e = x;
        long long int ans = 1;
        
        while(s <= e){
            long long mid = s + (e-s)/2;
            
            if(1LL * mid * mid == x){
                return mid;
            }
            else if(1LL * mid * mid > x){
                e = mid - 1;
            }
            else{
                s = mid + 1;
                ans = mid;
            }
        }
        
        return ans;
    }
};