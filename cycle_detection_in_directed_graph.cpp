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
