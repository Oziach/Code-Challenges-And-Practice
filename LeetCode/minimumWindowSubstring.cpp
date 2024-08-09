class Solution {
private:
bool HaveAllFreqs(int minFreqs[256], int currFreqs[256]){

    //check if we have all the min freqs
            bool haveAllFreqs = true;

            for(int i = 0; i < 26; i++){
                int ch = 'A' + i;
                if(currFreqs[ch] < minFreqs[ch]){
                    return false;
                }

                 ch = 'a' + i;
                if(currFreqs[ch] < minFreqs[ch]){
                    return false;
                }
            }
            return true;;
}
public:
    string minWindow(string s, string t) {

        //precompute freqs
        int currFreqs[256];
        int minFreqs[256];
        int charsInT = 0;

        for(int i = 0; i < 26; i++){
            currFreqs['A' + i] = 0;
            minFreqs['A' + i] = 0;
            currFreqs['a' + i] = 0;
            minFreqs['a' + i] = 0;
        }

        for(char ch : t){
            if(minFreqs[ch] == 0){charsInT++;}
            minFreqs[ch]++;
            
        }

        //two pointer
        int st = 0;
        int e = 0;

        int minSt = 0;
        int minE = INT_MAX;

        int cnt = 0;

        while(e < s.length()){

            //read state
            currFreqs[s[e]]++;
            if(currFreqs[s[e]] == minFreqs[s[e]]){cnt++;}

            //correct state
            //bool haveAllFreqs = cnt == charsInT;

            while(cnt == charsInT){
                if(e - st < minE - minSt){
                    minE = e;
                    minSt = st;
                }
                currFreqs[s[st]]--;
                if(currFreqs[s[st]] < minFreqs[s[st]]){cnt--;}
                st++;
            }
            
            e++;
            
        }

        if(minE == INT_MAX){return "";}
        return s.substr(minSt, minE-minSt+1);
    }
};