class Solution {
    Node* PopulateNodeParentMap(Node* root, map<Node*, Node*>& m, int target){
        
        Node* found = NULL;
        
        queue<Node*> q;
        q.push(root);
        

        while(!q.empty()){
            
            Node* current = q.front();
            q.pop();
            
            if(current->data == target) {found = current;}
            if(current->left){m[current->left] = current; q.push(current->left);}
            if(current->right){m[current->right] = current; q.push(current->right);}
        }
        
        return found;
            
    }
    
    
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> m;
        Node* arsonistNode = PopulateNodeParentMap(root, m, target);
        
        map<Node*, bool> visited;
        
        //bfs
        int time = 0;
        queue<Node*> q;
        
        q.push(arsonistNode);
        visited[arsonistNode] = true;
        
        while(!q.empty()){
            int s = q.size();
            bool burnersAdded = false;
            
            for(int i = 0; i < s; i++){
                Node* current = q.front();
                q.pop();
                
                if(current->right && !visited[current->right]){visited[current->right] = true; q.push(current->right); burnersAdded = true;}
                if(current->left && !visited[current->left]){visited[current->left] = true; q.push(current->left); burnersAdded = true;}
                if(m[current] && !visited[m[current]]){visited[m[current]] = true; q.push(m[current]); burnersAdded = true;}
            }
            if(burnersAdded){
                time++;
            }
        }
        
        return time;
    }
};