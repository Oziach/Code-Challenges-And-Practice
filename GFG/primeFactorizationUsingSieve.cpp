class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
        
        int* spf = new int[N+1];
        
        vector<int> ans;
        
        //init spf
        for(int i = 0; i <= N; i++){
            spf[i] = i;
        }
        
        for(int i = 2; i*i<= N; i++){
            
            if(spf[i] == i){
                for(int j = i * i; j <= N; j+=i){
                    spf[j] = min(spf[j], i);
                }s
            }
        }
        
        //operate on N
        while(N > 1){
            ans.push_back(spf[N]);
            N /= spf[N];
        }
        
        return ans;
    }
};