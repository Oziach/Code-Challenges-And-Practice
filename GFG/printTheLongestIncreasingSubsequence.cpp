    int n = nums.size();

       vector<int> lisForIndex(n, 1);
       vector<int> prevIndexes(n, -1);

       for(int index = 0; index < n; index++){
            for(int prevIndex = 0; prevIndex <  index; prevIndex++){

                if(nums[prevIndex] < nums[index]){
                    lisForIndex[index] = max(lisForIndex[index], 1 + lisForIndex[prevIndex]);
                    if(lisForIndex[prevIndex] + 1 > lisForIndex[index]){
                        prevIndexes[index] = prevIndex;
                    }
                }
            }
       }

       int maxIndex = 0;


        //find index of last element of lis
       for(int i = 0; i < lisForIndex.size(); i++){
            if(lisForIndex[i] > lisForIndex[maxIndex]){
                maxIndex = i;
            }
       }

       //trace the subsequence itself from there on
        vector<int> ans;
        
        int prevIndex = maxIndex;
        while(prevIndex >= 0){
            ans.push_back(prevIndex);
            prevIndex = prevIndexes[prevIndex];
        }


       return ans;