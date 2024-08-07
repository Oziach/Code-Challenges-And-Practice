class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> q;

        //init window
        for(int i = 0; i < k; i++){
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }

            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        
        int windowEnd = k;
        for(windowEnd = k; windowEnd < nums.size(); windowEnd++){
            int windowStart = windowEnd - k + 1;

            while(!q.empty() && q.front() < windowStart){q.pop_front();}
            while(!q.empty() && nums[q.back()] < nums[windowEnd]){q.pop_back();}
            q.push_back(windowEnd);

            ans.push_back(nums[q.front()]);
        }

        return ans;

    }
};