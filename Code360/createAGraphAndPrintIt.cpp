vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    
    vector<vector<int>> ans;
   
    for(int i = 0; i < n; i++){
        vector<int> temp;
        temp.push_back(i);
        ans.push_back(temp);
    }

    for(int i = 0; i < m; i++){
        vector<int> edge = edges[i];
        int first = edge[0];
        int second = edge[1];

        ans[first].push_back(second);
        ans[second].push_back(first);
    }

    return ans;
}
