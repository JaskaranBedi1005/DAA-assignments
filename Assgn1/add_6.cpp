#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

double bruteForce(vector<Point>& p, int left, int right) {
    double ans = 1e18;
    for (int i = left; i <= right; i++) {
        for (int j = i + 1; j <= right; j++) {
            ans = min(ans, distance(p[i], p[j]));
        }
    }
    return ans;
}

double solve(vector<Point>& p, int left, int right) {
    if (right - left <= 3)
        return bruteForce(p, left, right);

    int mid = (left + right) / 2;
    double d1 = solve(p, left, mid);
    double d2 = solve(p, mid + 1, right);

    double d = min(d1, d2);

    vector<Point> strip;
    int midX = p[mid].x;

    for (int i = left; i <= right; i++) {
        if (abs(p[i].x - midX) < d)
            strip.push_back(p[i]);
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size(); j++) {
            if (strip[j].y < strip[i].y)
                swap(strip[i], strip[j]);
        }
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1;
             j < strip.size() && (strip[j].y - strip[i].y) < d;
             j++) {
            d = min(d, distance(strip[i], strip[j]));
        }
    }

    return d;
}

int main() {
    vector<Point> p = {
        {9,3}, {2,6}, {15,3}, {5,1},
        {1,2}, {12,4}, {7,2}, {4,7},
        {16,5}, {3,3}, {10,5}, {6,4},
        {14,6}, {8,6}, {11,1}, {13,2}
    };

    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            if (p[j].x < p[i].x)
                swap(p[i], p[j]);
        }
    }

    double ans = solve(p, 0, p.size() - 1);

    cout << fixed << setprecision(3);
    cout << "Minimum distance = " << ans << endl;

    return 0;
}
