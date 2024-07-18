class Solution {
public:

    // int GetLongest(vector<int>& arr, int diff, int index, int prev){
    //     if(index >= arr.size()){return 0;}

    //     int maxi = 0;

    //     //include
    //     if(prev == -1 || arr[index] - arr[prev] == diff){
    //         maxi = max(maxi, 1 + GetLongest(arr, diff, index+1, index));
    //     }

    //     //exclude
    //     maxi = max(maxi, GetLongest(arr, diff, index+1, prev));

    //     return maxi;
    // }

    // int GetLongestMem(vector<int>& arr, int diff, int index, int prev, vector<vector<int>>& longestAt){
    //     if(index >= arr.size()){return 0;}
    //     if(longestAt[index][prev+1] != -1){
    //         return longestAt[index][prev+1];
    //     }

    //     int maxi = 0;

    //     //include
    //     if(prev == -1 || arr[index] - arr[prev] == diff){
    //         maxi = max(maxi, 1 + GetLongestMem(arr, diff, index+1, index, longestAt));
    //     }

    //     //exclude
    //     maxi = max(maxi, GetLongestMem(arr, diff, index+1, prev, longestAt));

    //     return longestAt[index][prev+1] = maxi;
    // }

    // int GetLongestTab(vector<int>& arr, int diff){
    //     int n = arr.size();

    //     vector<vector<int>> longestAt(n+1, vector<int>(n+1, 0));

    //     for(int index = n-1; index >= 0; index--){
    //         for(int prev = index-1; prev >= -1; prev--){

    //             int maxi = 0;

    //             //include
    //             if(prev == -1 || arr[index] - arr[prev] == diff){
    //                 maxi = max(maxi, 1 + longestAt[index+1][index+1]);
    //             }

    //             //exclude
    //             maxi = max(maxi, longestAt[index+1][prev+1]);

    //             longestAt[index][prev+1] = maxi;
    //         }
    //     }

    //     return longestAt[0][0];
    // }

    int GetLongestSO(vector<int>& arr, int diff){
        int n = arr.size();

        //vector<vector<int>> longestAt(n+1, vector<int>(n+1, 0));
        vector<int> nextRow(n+1, 0);
        vector<int> currentRow(n+1, 0);


        for(int index = n-1; index >= 0; index--){
            for(int prev = index-1; prev >= -1; prev--){

                int maxi = 0;

                //include
                if(prev == -1 || arr[index] - arr[prev] == diff){
                    maxi = max(maxi, 1 + nextRow[index+1]);
                }

                //exclude
                maxi = max(maxi, nextRow[prev+1]);

                currentRow[prev+1] = maxi;
            }
            nextRow = currentRow;
        }

        return nextRow[0];
    }

    int TheObviousSolution(vector<int>& arr, int diff){ //dp using map
        int maxi = 1;
        unordered_map<int,int> m;

        for(int num : arr){
            if(!m.count(num-diff)){
                m[num] = 1;
            }
            else{
                m[num] = m[num-diff] + 1;
                maxi = max(maxi, m[num]);

            }
        }

        return maxi;
    }

    int longestSubsequence(vector<int>& arr, int difference) {

        int n = arr.size();
        
        //vector<vector<int>> longestAt(n, vector<int>(n+1, -1));
        return TheObviousSolution(arr, difference);
    }
};