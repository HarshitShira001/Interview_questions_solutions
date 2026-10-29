/*
You are given an old touch smartphone numbers having dial pad and calculator app.
Aim: The goal is to type a number on dialpad.

But as phone is old, some of the numbers and some operations can't be touched.
For eg. 2,3,5,9 keys are not responding , i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number

Calculator have 1-9 and +,-,*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.

You have to find minimum number to touches required to obtain a number.

#Input:#
There will be multiple Test cases .Each test case will consist of 4 lines
1) First line will consist of N,M,O
	N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
	M:types of operations supported (+,-,*,/)
	O: Max no of touches allowed
2) second line of input contains the digits that are working e.g 0,2,3,4,6.
3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)
4) fourth line contains the number that we want to make .

#Output:#
Output contains 1 line printing the number of touches required to make the number


#Sample Test Case:#
5 
5 3 5
1 2 4 6 0
1 2 3
5
6 4 5 
1 2 4 6 9 8
1 2 3 4
91
6 2 4
0 1 3 5 7 9
1 2 4
28
5 2 10
1 2 6 7 8
2 3
981
6 3 5
1 4 6 7 8 9
1 2 3
18

#Output:#
4
2 
5
9
2
If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
*/
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int wdigits[10];
int opt[4];
int target;
int n, m, o;

struct state {
    int prev;
    int curr;
    int op;
    int touches;
};

int calculate(int prev, int curr, int op) {
    if (prev == -1) {
        return curr;
    }

    if (op == 1) {
        return prev + curr;
    }

    if (op == 2) {
        return prev - curr;
    }

    if (op == 3) {
        return prev * curr;
    }

    if (op == 4) {
        if (curr == 0) {
            return -1;
        }
        return prev / curr;
    }

    return curr;
}

int solve() {
    queue<state> q;

    for (int i = 0; i < n; i++) {
        int digit = wdigits[i];

        if (digit == target) {
            return 1;
        }

        q.push({-1, digit, -1, 1});
    }

    while (!q.empty()) {
        state t = q.front();
        q.pop();

        if (t.touches >= o) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            int nextdigit = wdigits[i];

            long long nextcurr;

            if (t.curr == -1) {
                nextcurr = nextdigit;
            } else {
                nextcurr = (long long)t.curr * 10 + nextdigit;
            }

            if (nextcurr <= INT_MAX) {
                if (nextcurr == target && t.prev == -1 && t.op == -1) {
                    return t.touches + 1;
                }

                q.push({
                    t.prev,
                    (int)nextcurr,
                    t.op,
                    t.touches + 1
                });
            }
        }

        if (t.curr != -1) {
            for (int i = 0; i < m; i++) {
                int nextop = opt[i];

                int result = calculate(t.prev, t.curr, t.op);

                if (result >= 0) {
                    q.push({
                        result,
                        -1,
                        nextop,
                        t.touches + 1
                    });
                }
            }
        }

        if (t.prev != -1 && t.curr != -1 && t.op != -1) {
            int result = calculate(t.prev, t.curr, t.op);

            if (result == target && t.touches < o) {
                return t.touches + 1;
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> n >> m >> o;

        for (int i = 0; i < n; i++) {
            cin >> wdigits[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> opt[i];
        }

        cin >> target;

        cout << t << " " << solve() << endl;
    }

    return 0;
}
