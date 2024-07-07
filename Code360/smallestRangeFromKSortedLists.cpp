#include<bits/stdc++.h>

struct Node{
    int data;
    int arraysIndex;
    int dataIndex;
};

class Comp{
public:
    bool operator()(const Node& a, const Node& b){
        return a.data > b.data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {

    priority_queue<Node, vector<Node>, Comp> minHeap;
    Node maxi = {INT_MIN, -1, -1};
    pair<int,int> range;
    int minRangeSize = INT_MAX;

    for(int i = 0; i < k; i++){
        minHeap.push({a[i][0], i, 0});
        if(a[i][0] > maxi.data){
            maxi = {a[i][0], i, 0};
        }
    }


    while(!minHeap.empty()){
        Node top = minHeap.top();
        
        range.first = top.data;
        range.second = maxi.data;
        minRangeSize = min(minRangeSize, range.second - range.first +1);
    
        minHeap.pop();

        int newDataInd = top.dataIndex + 1;
        int arraysInd = top.arraysIndex;
        if(newDataInd >= n){break; }

        Node newNode = {a[arraysInd][newDataInd], arraysInd, newDataInd};
        minHeap.push(newNode);
        if(newNode.data > maxi.data){
            maxi = newNode;
        }

    }

    return minRangeSize;
}