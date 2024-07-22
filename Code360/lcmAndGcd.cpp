class Solution {
  public:
    
    long long gcd(long long A, long long B){
        
        if(A == 0){return B;}
        if(B == 0){return A;}
        
        if(A > B){
            return gcd(A%B, B);
        }
        else{
            return gcd(A, B%A);
        }
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
       
        long long hcf = gcd(A, B);
        
        long long a = A/hcf;
        long long b = B/hcf;
        
        long long lcm = hcf * a * b;
        
        vector<long long> ans;
        ans.push_back(lcm);
        ans.push_back(hcf);
        
        return ans;
    }
};