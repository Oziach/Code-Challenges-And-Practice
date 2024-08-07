class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st = 0;
        int e = 0;
        int longest = 0;

        int arr[256];
        for(int i = 0; i < 256; i++){
            arr[i] = 0;
        }

        while(e < s.length()){
            char eCh = s[e];
            arr[eCh]++;

            while(arr[eCh] > 1){
                char sCh = s[st];
                arr[sCh]--;
                st++;
            }

            //current e and s are valid
            longest = max(longest, e-st+1);

            e++;            
        }

        return longest;
    }
};