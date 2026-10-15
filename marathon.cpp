/*
A person is running a marathon of distance D with limited energy H.
He can change his pace every 1 km. Every pace consumes some amount of energy.
Given 5 paces in increasing order of time, i.e. time taken to run 1 km and energy consumed in 1km.
You need to find the least amount of time required to complete the marathon within the given amount of energy.
Paces are given such that the combination always completes the marathon.

Input format:
The first line contains the number of test cases T.
Each test case is given as follows:
- The first line of each test case contains the 2 integers D and H (D is the distance and H is the energy)
- The next 5 lines are as follows:
    - There are 3 integers (M, S and E) where: M is the minutes and S is the seconds required to run 1 km
      and E is the energy consumed in 1 km.

Output Format:
Print the following:
# followed by test case number followed by minimum time in mutes followed by seconds
Eg: #1 153 20

Eg: D = 30, H = 130
5 Paces: (M min S sec E energy)
4 50 7
5 0 5
5 10 4
5 20 3
5 30 2

Output: #1 153 20
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int d,h;
int pacetime[5];
int energy[5];
int solve(int remd,int reme,int index,vector<vector<vector<int>>> &dp){
    if(remd == 0){
        return 0;
    }
    if(index >= 5 || reme < 0){
        return INT_MAX;
    }
    if(dp[remd][reme][index] != -1){
        return dp[remd][reme][index];
    }
    int result = INT_MAX;
    for(int d = 0;d <= remd;d++){
        int usedenergy = d*energy[index];
        if(usedenergy > reme){
            break;
        }
        int ans = solve(remd-d,reme-usedenergy,index+1,dp);
        if(ans != INT_MAX){
            result = min(result,d*pacetime[index] + ans);
        }
    }
    return dp[remd][reme][index] = result;
}
int main() 
{
    int T;
    cin >> T;
    for(int t = 1;t <= T;t++){
        cin >> d;
        cin >> h;
        for(int i = 0;i < 5;i++){
            int m,s,e;
            cin >> m >> s >> e;
            pacetime[i] = 60*m+s;
            energy[i] = e;
        }
        vector<vector<vector<int>>> dp(d+1,vector<vector<int>> (h+1,vector<int> (6,-1)));
        int ans = solve(d,h,0,dp);
        cout << "#" <<  t << " " << ans/60 << " " << ans%60 << "\n";
    }
    return 0;
}
