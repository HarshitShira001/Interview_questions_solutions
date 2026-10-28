#include <bits/stdc++.h>
using namespace std;

long long dp[1005][1005];

long long solve(int arr[], int n, int p)
{
    long long ans = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }

    for (int i = n; i > 0; i--)
    {
        for (int z = 1; z <= p; z++)
        {
            if (z == 1)
            {
                dp[i][z] = (n - i + 1) * arr[i];
                continue;
            }

            for (int k = i + 1; k <= n; k++)
            {
                dp[i][z] = min(
                    dp[i][z],
                    dp[k][z - 1] + arr[i] * (k - i)
                );
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][p]);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int k;
        cin >> k;

        int arr[n + 1];

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        sort(arr + 1, arr + n + 1);

        cout << solve(arr, n, k) << endl;
    }

    return 0;
}
