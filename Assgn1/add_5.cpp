#include <bits/stdc++.h>
using namespace std;
bool canFit(long long S, long long N, long long W, long long H) {
    return (S / W) * (S / H) >= N;
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;

        long long low = max(H, W);
        long long high = max(H, W) * N;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canFit(mid, N, W, H)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
