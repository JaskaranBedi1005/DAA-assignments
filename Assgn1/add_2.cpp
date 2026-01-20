#include <bits/stdc++.h>
using namespace std;
int longestGoodSubsequence(vector<int>& A) {
    sort(A.begin(), A.end());

    int n = A.size();
    int l = 0;
    int ans = 0;

    for (int r = 0; r < n; r++) {
        while (A[r] - A[l] > 10) {
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << longestGoodSubsequence(A) << endl;

    return 0;
}
