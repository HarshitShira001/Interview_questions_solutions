/* 
The question was sort of, given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump).A vertical jump from a given point of the matrix to other point 
on the matrix can be taken (on 1’s only) with cost as the number of jumps taken. 
Given a source and destination, the frog has to reach the destination minimizing the cost (jump)*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() 
{
    int ans = -1;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int> (m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> mat[i][j];
        }
    }
    int sr,sc,dr,dc;
    cin >> sr >> sc >> dr >> dc;
    vector<vector<int>> dist(n+1,vector<int> (m+1,1e9));
    if(mat[sr][sc] == 0 || mat[dr][dc] == 0){
        return -1;
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    dist[sr][sc] = 0;
    pq.push({0,{sr,sc}});
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int cost = temp.first;
        int r = temp.second.first;
        int c = temp.second.second;
        if(cost != dist[r][c]){
            continue;
        }
        if(r == dr && c == dc){
            ans = cost;
            break;
        }
        int lc = c-1;
        int rc = c+1;
        if(lc >= 0 && mat[r][lc] == 1 && cost < dist[r][lc]){
            dist[r][lc] = cost;
            pq.push({cost,{r,lc}});
        }
        if(rc < m && mat[r][rc] == 1 && cost < dist[r][rc]){
            dist[r][rc] = cost;
            pq.push({cost,{r,rc}});
        }
        for(int i = 0;i < n;i++){
            if(i == r || mat[i][c] == 0){
                continue;
            }
            int newcost = cost + abs(i-r);
            if(newcost < dist[i][c]){
                dist[i][c] = newcost;
                pq.push({newcost,{i,c}});
            }

        }
    }
    cout << ans << "\n";
    return 0;
}
