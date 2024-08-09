struct Info{
  int arrNo;
  int index;
  int data;
};

class Comp{
public:
    bool operator()(Info a, Info b){
        return a.data > b.data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Info, vector<Info>, Comp> minHeap;
        vector<int> ans;

        for(int i = 0; i < K; i++){
            minHeap.push({i, 0, arr[i][0]});
        }
 
        while(!minHeap.empty()){
            Info top = minHeap.top();
            minHeap.pop();
            
            ans.push_back(top.data);
            
            if(top.index < K-1){ //could've made this cleaner ofc but I'm lazy
                minHeap.push({top.arrNo, top.index + 1, arr[top.arrNo][top.index+1]});
            }
            
        }
        
        return ans;
    }
};