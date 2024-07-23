class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;


        for(int num : nums){
            if((count1 == 0 && num != ele2 )|| num == ele1){ele1 = num; count1++;}
            else if((count2 == 0 && num != ele1)|| num == ele2){ele2 = num; count2++;}

            else{//niether ele1 nor ele2
                count1--;
                count2--;
            }
        }

        //validate
        count1 = 0;
        count2 = 0;
        for(int num : nums){
            if(num == ele1){
                count1++;
            }
            else if(num == ele2){
                count2++;
            }
        }

        if(count1 > n/3){ans.push_back(ele1);}
        if(count2 > n/3){ans.push_back(ele2);}

        return ans;
    }
};