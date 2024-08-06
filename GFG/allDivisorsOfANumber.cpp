class Solution {
  public:
    void print_divisors(int n) {    
        vector<int> divisors;
        
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                cout << i << " ";
                
                if(n != i * i){
                    divisors.push_back(n/i);
                }
            }
        }
        
        for(int i = divisors.size()-1; i >= 0; i--){
            cout << divisors[i] << " ";
        }
    
    }
};