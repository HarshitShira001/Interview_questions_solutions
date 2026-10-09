/*
There is a mobile piece and a stationary piece on the N×M chessboard. 
The available moves of the mobile piece are the same as set out in the image below. 
You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.

Write a program to find out the minimum number moves to catch a piece. 

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the
inputs. After that, the test cases as many as T (T ≤ 20) are given in a row. 
N, the numbers of the rows and M, the number of columns of the chessboard are given in the first row of
each test case. 
R & C is the location information of the attacking piece and S & K is the location of the defending pieces 
and are given in the row at the second line. However, the location of the uppermost end of the left end 
is (1, 1)

[Output]
For each test case, you should print "Case #T" in the first line where T means the case number.

For each test case, you should output the minimum number of movements to catch a defending piece at the 
first line of each test case. If not moveable, output equals ‘-1’. 

[I/O Example]

Input 
2
9 9
3 5 2 8
20 20
2 3 7 9

Output
Case #1
2
Case #2
5 
*/



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int solve(int n, int m, int x1, int y1, int x2, int y2) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    q.push({{x1, y1}, 0});
    visited[x1][y1] = 1;

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        int row = temp.first.first;
        int col = temp.first.second;
        int dist = temp.second;

        if (row == x2 && col == y2)
            return dist;

        for (int i = 0; i < 8; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !visited[nr][nc]) {

                visited[nr][nc] = 1;
                q.push({{nr, nc}, dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        x2--; y2--;

        cout << "Case #" << t << "\n";
        cout << solve(n, m, x1, y1, x2, y2) << "\n";
    }

    return 0;
}
