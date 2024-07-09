vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    vector<bool> visited(n, false);
    visited[0] = true;

    vector<int> ans;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        
        for(int i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }

    }

    return ans;
}