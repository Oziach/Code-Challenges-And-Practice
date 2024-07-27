class Solution
{
    long long int SubstrCountUpTo(string& st, int k){
        vector<int> counts(26, 0);
        int s = 0;
        int count = 0;
        int distinct = 0;
        
        for(int e = 0; e < st.length(); e++){
            
            counts[st[e]-'a']++;
            if(counts[st[e]-'a'] == 1){distinct++;}
            
            while(distinct > k){
                counts[st[s]-'a']--;
                if(counts[st[s]-'a'] == 0){
                    distinct--;
                }
                s++;
            }
            count += e - s + 1;
        }
        
        return count;
    }
    
  public:
    long long int substrCount (string s, int k) {
    	return SubstrCountUpTo(s, k) - SubstrCountUpTo(s, k-1);
    }
};