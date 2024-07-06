#include <bits/stdc++.h> 

struct Unit{
    int data;
    int dataIndex;
    int arrayIndex;
};

class Comp{
public:
    bool operator()(Unit& a,Unit& b){
        return a.data > b.data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Unit, vector<Unit>, Comp> pq;
    vector<int> ans;

    //init pq
    for (int i = 0; i < k; i++) {
        pq.push({kArrays[i][0], 0, i});
    }

    while(pq.size() > 0){
        Unit unit = pq.top();
        pq.pop();

        ans.push_back(unit.data);

        int arrayIndex = unit.arrayIndex;
        int dataIndex = unit.dataIndex+1;

        if(dataIndex < kArrays[arrayIndex].size())
          pq.push({kArrays[arrayIndex][dataIndex], dataIndex, arrayIndex});
    }


    return ans;
}