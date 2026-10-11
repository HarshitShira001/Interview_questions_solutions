/*There are N fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman <=N)

Distance between consecutive spots = distance between gate and nearest spot = 1 m

Only 1 gate can be opened(other gates after that gate) at a time and all fishermen of that gate must occupy the spots before the next gate is opened.

Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot. Find the total sum of minimum distances need to walk for all the fishermen.

image

Input Format

Number of fishing spots, N Position of the gates, Gi, 1 < i < 3 Number of fishermen at each gates, G_n_i

Constraints

1 <= N <= 10 1 <= G_i <= N 1 <= G_n_i <= 15

Output Format

Output single integer

Sample Input 0

10
4 6 10
5 2 2
Sample Output 0

18
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <limits.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int gate[3];
int people[3];
vector<int> visited;
int ans = INT_MAX;

vector<vector<int>> gateop = {
    {0,1,2},
    {0,2,1},
    {1,0,2},
    {1,2,0},
    {2,1,0},
    {2,0,1}
};
void solve(int index,int order,int cost);
void place(int index,int order,int cost,int gatepos,int rem){   
    if(cost >= ans){
        return;
    }
    if(rem == 0){
    solve(index+1,order,cost);
    return;
    }
    vector<int> candidates;
    int mindist = INT_MAX;
    for(int i = 0;i < n;i++){
        if(visited[i]){
            continue;
        }
        int dist = abs(i-gatepos)+1;
        if(dist < mindist){
            mindist = dist;
            candidates.clear();
            candidates.push_back(i);
        }
        else if(dist == mindist){
            candidates.push_back(i);
        }
    }
    if(candidates.size() == 2 && rem >= 2){
        int l = candidates[0];
        int r = candidates[1];
        visited[l] = 1;
        visited[r] = 1;
        place(index,order,cost + 2*mindist,gatepos,rem-2);
        visited[l] = 0;
        visited[r] = 0;
    }
    else{
        for(int pos: candidates){
            visited[pos] = 1;
            place(index,order,cost+mindist,gatepos,rem-1);
            visited[pos] = 0;
        }
    }
}
void solve(int index,int order,int cost){
    if(cost >= ans){
        return;
    }
    if(index == 3){
        ans = min(ans,cost);
        return;
    }
    int gateidx = gateop[order][index];
    int gatepos = gate[gateidx]-1;
    int count = people[gateidx];
    place(index,order,cost,gatepos,count);
}

int main() {
    cin >> n;
    for(int i = 0;i < 3;i++){
        cin >> gate[i];
    }
    for(int i = 0;i < 3;i++){
        cin >> people[i];
    }
    for(int i = 0;i < n;i++){
        visited.push_back(0);
    }
    for(int order = 0;order < 6;order++){
        solve(0,order,0);
    }
    
    cout << ans << endl;
}
