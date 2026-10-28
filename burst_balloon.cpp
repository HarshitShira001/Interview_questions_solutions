/*You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely
*/

class Solution {
public:
    int solve(int start,int end,vector<int> &arr,vector<vector<int>> &dp){
        if(start == (end-1)){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MIN;
        for(int i = start+1;i <= end-1;i++){
            ans = max(ans,arr[i]*arr[start]*arr[end] + solve(start,i,arr,dp) + solve(i,end,arr,dp));
        }
        return dp[start][end] = ans;
    }
    int solvetab(vector<int> &nums){
        int n = nums.size();
        vector<int> arr;
        arr.push_back(1);
        for(int i = 0;i < n;i++){
            arr.push_back(nums[i]);
        }
        arr.push_back(1);
        n = arr.size();
        vector<vector<int>> dp(n+3,vector<int> (n+3,0));
        for(int start = n-3;start >= 0;start--){
            for(int end = start+2;end <= n-1;end++){
                int ans = INT_MIN;
                for(int i = start+1;i <= end-1;i++){
                    ans = max(ans,arr[start]*arr[i]*arr[end] + dp[start][i] + dp[i][end]);
                }
                dp[start][end] = ans;
            }
        }
        return dp[0][n-1];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+3,-1));
        vector<int> arr;
        arr.push_back(1);
        for(int i = 0;i < n;i++){
            arr.push_back(nums[i]);
        }
        arr.push_back(1);
        //solve(0,n+1,arr,dp);
        return solvetab(nums);
    }
};
