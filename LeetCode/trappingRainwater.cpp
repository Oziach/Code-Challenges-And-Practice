class Solution {
public:
    int trap(vector<int>& height) {
        int l = 1;
        int r = height.size() - 2;

        int lMax = height[0];
        int rMax = height[height.size()-1];
        int water = 0;

        while(l <= r){
            
            if(lMax < rMax){
                water += max(0, lMax - height[l]);
                lMax = max(lMax, height[l++]);

            }
            else{
                water += max(0, rMax - height[r]);
                rMax = max(rMax, height[r--]);
            }

        }

        return water;
    }
};