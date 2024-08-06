class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> nextGreater(nums.size());
        stack<int> st;
        st.push(INT_MIN);

        for(int j = 2*nums.size() - 1; j >= 0; j--){
            
            int i = j % nums.size();

            while(nums[i] >= st.top() && st.top() != INT_MIN){
                st.pop();
            }
        
            nextGreater[i] = st.top() == INT_MIN ? -1 : st.top();
 
            st.push(nums[i]);
        }

        
        return nextGreater;
    }
};