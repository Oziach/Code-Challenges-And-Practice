class Solution {

private:
    void FindSmallerLefts(vector<int>& nums, vector<int>& smallerLefts){
        int n = nums.size();
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n; i++){
            while(st.top() != -1 && nums[st.top()] > nums[i]){
                st.pop();
            }

            smallerLefts[i] = st.top();

            st.push(i);
        }
    }

    void FindGreaterLefts(vector<int>& nums, vector<int>& greaterLefts){
        int n = nums.size();
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n; i++){
            while(st.top() != -1 && nums[st.top()] < nums[i]){
                st.pop();
            }

            greaterLefts[i] = st.top();

            st.push(i);
        }
    }

     void FindSmallerRights(vector<int>& nums, vector<int>& smallerRights){
        int n = nums.size();
        stack<int> st;
        st.push(n);

        for(int i = n-1; i >= 0; i--){
            while(st.top() != n && nums[st.top()] >= nums[i]){
                st.pop();
            }

            smallerRights[i] = st.top();

            st.push(i);
        }
    }

    void FindGreaterRights(vector<int>& nums, vector<int>& greaterRights){
        int n = nums.size();
        stack<int> st;
        st.push(n);

        for(int i = n-1; i >= 0; i--){
            while(st.top() != n && nums[st.top()] <= nums[i]){
                st.pop();
            }

            greaterRights[i] = st.top();

            st.push(i);
        }
    }


public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> smallerLefts(n);
        vector<int> greaterLefts(n);
        vector<int> smallerRights(n);
        vector<int> greaterRights(n);

        FindSmallerLefts(nums, smallerLefts);
        FindGreaterLefts(nums, greaterLefts);
        FindSmallerRights(nums, smallerRights);
        FindGreaterRights(nums, greaterRights);

        long long sum = 0;

        for(int i = 0; i < n; i++){

            int smallerAhead = smallerRights[i] - i;
            int smallerPrev = i - smallerLefts[i];
            int greaterAhead = greaterRights[i] - i;
            int greaterPrev = i - greaterLefts[i];

            long long noOfSubsSmallest = smallerAhead * smallerPrev;
            long long noOfSubsGreatest = greaterAhead * greaterPrev;

            sum += noOfSubsGreatest * nums[i];
            sum -= noOfSubsSmallest * nums[i];
        }

        return sum;
    }
};