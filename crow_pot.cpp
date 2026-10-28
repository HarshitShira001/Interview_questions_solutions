/*Thirsty Crow
There are N pots. Every pots have some water in it. They may be partially filled. So there is a Overflow
Number 0 associated with every pot which tell how many minimum stone pieces are require for that pot
to overflow. So if for a pot 0-value is 5 it means minimum 5 stone pieces should be put in that pot to
make it overflow. Initially a crow watched those pots and by seeing the water level he anticipated 0-
value correctly for every pot (that is he knew 01 to On).
But when he came back in evening he found that every pot is painted from outside and he is not able to
know which pot has what 0-value. Crow wants some K pots to overflow so that he can serve his child
appropriately. For overflow of pots he need to search for stone in forest (assume that every stone has
same size). He wants to use minimum number of stones required to overflow K pots.
But only he knows the 0-value of pots he doesn't know now which pot has what 0-value. So the task is
that in what minimum number of stones he can make K pots overflow in worst case.
Input Format:
You will be given a function which contains an integer array 0 corresponding to 0-value of N pots {01, 02,
On) and a K - Value representing the number of pots which the crow wants to overflow
Output Format:
You need to return the Minimum number of stones (in the form of integer) required to make K pots
overflow in worst case.
If input is invalid, return -1.
Sample Test Case 1
Sample Input: {5,58}, 1
Sample Output: 10
Explanation:
Let say there are two pots
pot 1 has 0 value of 5, 01= 5
pot 2 has 0 value of 58, 02= 58
Let say crow wants to make one of the pot to overflow. If he knows which pot has what 0-value, he
would simple search for 5 stones and put them in pot 1 to make it overflow. But in real case he doesn't
know which pot has what 0-value so just 5 stones may not always work.
However, he does know that one pot has 0-value 5 and other has 58. So even in worst case he can make
one of the pot overflow just by using 10 stones. He would put 5 stones in one pot if it doesn't overflow
he would try the remaining 5 in the other pot which would definitely overflow because one of the pot
has 0-value of 5.
So the answer for above question is minimum 10 stones even in worst case.
Sample Test Case 2
Sample Input: {65,69}, 1
Sample Output: 69
Explanation:
Let say there are two pots
pot 1 has 0 value of 65, 01= 65
pot 2 has 0 value of 69, 02= 69
In worst case, crow will approach the pot with 69 O value first. After putting in 65 stones, the pot does
not overflow. Now if pot is changed, 65 more stones would be required, whereas if just 4 more stones
are put into same pot, it will overflow.
So the answer in this case is 69.
*/


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
