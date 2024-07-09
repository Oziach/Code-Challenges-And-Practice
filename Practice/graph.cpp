#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
 public:
    unordered_map<int, list<int>> adj;
    
    void AddEdge(int u, int v, bool directed){
        
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }
        cout << endl;
    }
    
    void PrintGraph(){
        for(auto p : adj){
            cout << p.first << " -> ";
            for(auto node : p.second){
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph;
    graph.AddEdge(1,2, false);
    
    graph.PrintGraph();
    return 0;
}
