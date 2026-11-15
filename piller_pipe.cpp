/*You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner 
standing on top of TWO PILLERS.
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height
of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2.
In case, there is no combination possible, print 0.

INPUT :
1
5
1 2 3 4 6
Output :
8
*/
#include <iostream>
using namespace std;
#include <bits/stdc++.h> 

int solve(int index,int diff,vector<int> &roads,vector<vector<int>> &dp){
    if(index == roads.size()){
        if(diff == 0){
            return 0;
        }
        else{
            return -1;
        }
    }
    if(dp[index][diff] != -2){
        return dp[index][diff];
    }
    int ans = 0;
    int opt1 = solve(index+1,diff,roads,dp);
    if(opt1 != -1){
        ans = max(ans,opt1);
    }

    int newdiff = diff+roads[index];
    int opt2 = solve(index+1,newdiff,roads,dp);
    if(opt2 != -1){
        ans = max(ans,opt2);
    }

    int newdiff2 = abs(diff-roads[index]);
    int opt3 = solve(index+1,newdiff2,roads,dp);
    if(opt3 != -1){
        opt3 = opt3 + min(roads[index],diff);
        ans = max(ans,opt3);
    }
    return dp[index][diff] = ans;
}
int main() 
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> rods(n,-1);
        int sum = 0;
        for(int i = 0;i < n;i++){
            cin >> rods[i];
            sum += rods[i];
        }

        vector<vector<int>> dp(n+1,vector<int> (sum+1,-2));
        cout << solve(0,0,rods,dp);

    }   
}


//solution 2
class Solution {
public:
    int dp[21][100001];
    int solve(int index,int diff,vector<int> &rods){
        int n = rods.size();
        if(index >= n){ 
            if(diff == 0){
                return 0;
            }
            else{
                return INT_MIN;
            }
        }
        if(dp[index][diff+5000] != -1){
            return dp[index][diff+5000];
        }
        int nottaken = solve(index+1,diff,rods);
        int leftpillar = rods[index]+ solve(index+1,diff+rods[index],rods);
        int rightpillar = rods[index] + solve(index+1,diff-rods[index],rods);
        int ans = max({nottaken,leftpillar,rightpillar});
        return dp[index][diff+5000] = ans;
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int diff = 0;
        int index = 0;
        memset(dp,-1,sizeof(dp));
        return solve(index,diff,rods)/2;
    }
};
