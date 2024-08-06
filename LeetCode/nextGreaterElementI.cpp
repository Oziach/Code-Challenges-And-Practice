class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> nextGreater;
        stack<int> st;
        st.push(-1);

        for(int i = nums2.size() - 1; i >= 0; i--){
            
            while(nums2[i] >= st.top() && st.top() != -1){
                st.pop();
            }
        
            nextGreater[nums2[i]] = st.top();
 
            st.push(nums2[i]);
        }
a
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(nextGreater[nums1[i]]);
        }

        return ans;
    }
};