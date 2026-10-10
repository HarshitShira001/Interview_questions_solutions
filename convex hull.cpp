/*
Given random points in a 2-D plane, construct a convex polygon with minimum area of covering and 
which encompasses all the given points.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll cross(pii a, pii b, pii c) {
    return 1LL * (b.first - a.first) * (c.second - a.second)
         - 1LL * (b.second - a.second) * (c.first - a.first);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pii> points(n);

        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        if (n < 3) {
            cout << 0 << '\n';
            continue;
        }

        sort(points.begin(), points.end());

        vector<pii> lower, upper;

        for (auto p : points) {
            while (lower.size() >= 2 &&
                   cross(lower[lower.size() - 2], lower.back(), p) <= 0) {
                lower.pop_back();
            }
            lower.push_back(p);
        }

        for (int i = n - 1; i >= 0; i--) {
            auto p = points[i];

            while (upper.size() >= 2 &&
                   cross(upper[upper.size() - 2], upper.back(), p) <= 0) {
                upper.pop_back();
            }
            upper.push_back(p);
        }

        lower.pop_back();
        upper.pop_back();

        vector<pii> hull = lower;
        hull.insert(hull.end(), upper.begin(), upper.end());

        if (hull.size() < 3) {
            cout << 0 << '\n';
            continue;
        }

        cout << hull.size() << '\n';

        for (auto p : hull) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return 0;
}
