class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double maxProd = INT_MIN;
        double prefix = 1;
        double suffix = 1;

        for(int i = 0; i < n; i++){
            if(prefix == 0){prefix = 1;}
            if(suffix == 0){suffix = 1;}

            
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];
            maxProd = max(maxProd, max(prefix, suffix));

            if(maxProd == INT_MAX){return INT_MAX;}
        }

        return maxProd;
    }
};