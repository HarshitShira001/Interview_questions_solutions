/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil 
mines adjacent to each other and not in between of each others.After distributing them compute the 
difference of oil mines from the company getting highest and company getting lowest. This number 
should be minimum.(then only the distribution can be termed as fair).

Input 
2 
2 4 
6 13 10 2 
2 4 
6 10 13 2 

output 
5 
1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void solve(int i, int sum, int minval, int maxval,
           vector<int>& mines, vector<int>& visited,
           int& ans, int companies, int totalcompanies) {

    if (visited[i]) {
        if (companies == totalcompanies - 1) {
            minval = min(minval, sum);
            maxval = max(maxval, sum);
            ans = min(ans, maxval - minval);
        }
        return;
    }

    visited[i] = 1;
    int m = mines.size();
    int j = (i + 1) % m;

    solve(j, sum + mines[i], minval, maxval,
          mines, visited, ans, companies, totalcompanies);

    if (companies < totalcompanies - 1 && sum > 0) {
        int newMin = min(minval, sum);
        int newMax = max(maxval, sum);

        solve(j, mines[i], newMin, newMax,
              mines, visited, ans, companies + 1, totalcompanies);
    }

    visited[i] = 0;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int c, m;
        cin >> c >> m;

        vector<int> mines(m);
        vector<int> visited(m, 0);

        for (int i = 0; i < m; i++) {
            cin >> mines[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < m; i++) {
            fill(visited.begin(), visited.end(), 0);
            solve(i, 0, INT_MAX, INT_MIN, mines, visited,
                  ans, 0, c);
        }

        cout << ans << '\n';
    }

    return 0;
}
