class Solution {
  public:
    bool solve(int i,int parent,vector<vector<int>> &adj,vector<int> &visited){
        visited[i] = 1;
        for(auto neighbour: adj[i]){
            if(!visited[neighbour]){
                bool ans = solve(neighbour,i,adj,visited);
                if(ans == true){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        vector<vector<int>> adj(V);
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(V,0);
        for(int i = 0;i < V;i++){
            if(!visited[i]){
                bool ans = solve(i,-1,adj,visited);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
};
