#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   map<int, int> m;
   vector<vector<int>> ans;

   for(int i = 0; i < arr.size(); i++){
      int second = arr[i];
      int first = s - second;

      //if first exists
      if(m.find(first) != m.end()){
         for(int j = 0; j < m[first];  j++){
            vector<int> temp;
            temp.push_back(min(first, second));
            temp.push_back(max(first, second));

            ans.push_back(temp);
         }
      }
      
      m[second]++;

   }

   sort(ans.begin(), ans.end());
   return ans;
}