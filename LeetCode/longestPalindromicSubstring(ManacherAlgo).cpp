//Manacher's algo solution
class Solution {
public:
    string longestPalindrome(string s) {
        string st = "";
        st += '@';
        st += '#';
        for(int i = 0; i < s.size(); i++){
            st += s[i];
            st += '#';
        }
        st += '!';
        
        int n = st.length();
        vector<int> v(n, 0);
        int R = 1;
        int C = 1;

        cout << st << endl;
        //Manacher's algo
        for(int i = 2; i < n-2; i++){
            if(i < R)
                v[i] = min(R - i, v[C - (i-C)]);
            
            while(st[i - v[i] - 1] == st[i + v[i] + 1]){
                v[i]++;
                cout << i << " " << v[i] << " ";
            }

            if(i + v[i] > R){
                R = i + v[i];
                C = i;
            }
        }

        cout << endl;
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }

        string ans = "";
        int maxIndex = 2;
        for(int i = 0; i < n; i++){
            if(v[i] > v[maxIndex]){
                maxIndex = i;
            }
        }
        
        //print ans
        int i = maxIndex - v[maxIndex] + 1;
        for(int j = 0; j < v[maxIndex]; j++){
            ans += st[i+ 2*j];
        }

        return ans;
    }
};



/////////////O n square solution
class Solution {
public:
    pair<int,int> GetPalindrome(string& s, int a, int b){

        while(a >= 0 && b < s.length()){
            if(s[a] == s[b]){
                a--;
                b++;
            }
            else{
                break;
            }
        }

        return {a+1, b-1};
    }

    string longestPalindrome(string s) {
        int n = s.length();
        pair<int,int> longest = {0,0};

        for(int i = 0; i < 2*n; i++){
            pair<int,int> substr;
            if(i & 1){
                substr = GetPalindrome(s, (i-1)/2, (i+1)/2);
            }
            else{
                substr = GetPalindrome(s, i/2, i/2);
            }

            if(substr.second - substr.first > longest.second - longest.first){
                longest = substr;
            }
        }

        string ans = s.substr(longest.first, longest.second-longest.first + 1);
        return ans;
    }
};