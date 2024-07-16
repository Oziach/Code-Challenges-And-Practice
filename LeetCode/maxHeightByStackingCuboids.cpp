class Solution {
public:

    bool check(vector<int> base, vector<int> newBox){

        if( (newBox[0] <= base[0]) && (newBox[1] <= base[1]) && (newBox[2] <= base[2]) )
            return true;
        else
            return false;
    }



    int GetMaxHeight(vector<vector<int>>& cuboids){
        
        const int n = cuboids.size();

        vector<int> current(n+1, 0);
        vector<int> next(n+1,0);

        for(int index = n-1; index >= 0; index--){
            for(int prev = index-1; prev >= -1; prev--){

                //include
                int include = 0;
                if(prev == -1 || check(cuboids[index], cuboids[prev])){
                    include = cuboids[index][2] + next[index+1];
                }

                //exclude
                int exclude = next[prev+1];

                current[prev+1] = max(include, exclude);
            }
            next = current;
        }

        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        
        //sort dimensions
        for(auto &a: cuboids){
            sort(a.begin(), a.end()); 
        }


        //sort based on length
        sort(cuboids.begin(), cuboids.end());


        //use lis logic stuff thingmywut
        return GetMaxHeight(cuboids);
    }
    
};