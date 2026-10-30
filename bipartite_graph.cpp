/*
Given a graph print either of the set of the vertices that are colored with the same color. And if the graph
is not bipartite print “-1”. Test cases also included the cases when a graph is not connected.
*/
//solution using bfs
class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V,-1);
        unordered_map<int,vector<int>> adj;
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        color[0] = 0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbour: adj[node]){
                if(color[node] == color[neighbour]){
                    return false;
                }
                else if(color[neighbour] == -1){
                    color[neighbour] = (color[node]+1)%2;
                    q.push(neighbour);
                }
            }
        }
        return true;
    }
};
//solution using dfs
class Solution {
  public:
    bool solve(int node,vector<vector<int>> &adj,vector<int> &color){
        for(int i = 0; i < adj[node].size();i++){
            int neighbour = adj[node][i];
                if(color[node] == color[neighbour]){
                    return false;
                }
                if(color[neighbour] == -1){
                    color[neighbour] = (color[node]+1)%2;
                    bool ans = solve(neighbour,adj,color);
                    if(ans == false){
                        return ans;
                    }
                }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code 
        vector<vector<int>> adj(V);
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(V,-1);
        for(int i = 0;i < V;i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!solve(i,adj,color)){
                    return false;
                }    
            }
        }
        return true;
    }
};
