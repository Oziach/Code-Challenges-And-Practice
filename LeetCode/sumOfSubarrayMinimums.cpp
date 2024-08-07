#define MOD 1000000007

class Solution {
private:
    void FindPrevSmallerInds(vector<int>& arr, vector<int>& prevSmallerInds){
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < arr.size(); i++){
            
            while(st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();

            prevSmallerInds[i] = st.top();

            st.push(i);
        }
    }

    void FindNextSmallerInds(vector<int>& arr, vector<int>& nextSmallerInds){
        stack<int> st;
        int n = arr.size();

        st.push(n);

        for(int i = n-1; i >= 0; i--){
            
            while(st.top() != n && arr[st.top()] > arr[i])
                st.pop();

            nextSmallerInds[i] = st.top();

            st.push(i);
        }
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> prevSmallerInds(arr.size());
        vector<int> nextSmallerInds(arr.size());

        FindPrevSmallerInds(arr, prevSmallerInds);
        FindNextSmallerInds(arr, nextSmallerInds);

        long long sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            int ahead = nextSmallerInds[i] - i;
            int prev = i - prevSmallerInds[i];
    
            sum += (1LL * (1LL * arr[i] * ahead) % MOD * prev)%MOD;
        }

        return sum%MOD;

    }
};