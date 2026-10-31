//using dfs 
class Solution {
  public:
    bool solve(int node,vector<int> &visited,vector<int> &dfsvisited,vector<vector<int>> &adj){
        visited[node] = 1;
        dfsvisited[node] = 1;
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                if(solve(neighbour,visited,dfsvisited,adj)){
                    return true;
                }
            }else{
                if(dfsvisited[neighbour] == 1){
                    return true;
                }
            }
        }
        dfsvisited[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        vector<int> visited(V,0);
        vector<int> dfsvisited(V,0);
        for(int i = 0;i < V;i++){
            if(!visited[i]){
                if(solve(i,visited,dfsvisited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//using bfs
class Solution {
  public:
    bool isCyclic(vector<vector<int>>& adj){
        // code here
        int n = adj.size();
        vector<int> ans;
        vector<int> indegree(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i = 0;i < adj[temp].size();i++){
                indegree[adj[temp][i]]--;
                if(indegree[adj[temp][i]] == 0){
                    q.push(adj[temp][i]);
                    ans.push_back(adj[temp][i]);
                }
            }
        }
        if(ans.size() < n){
            return true;
        }
        return false;
    }
};
