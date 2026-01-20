#include<iostream>
#include<vector>
using namespace std;
bool canDivide(vector<int>& A, int M, int maxOR) {
    int segments = 1;
    int currOR = 0;

    for (int x : A) {
        if ((currOR | x) <= maxOR) {
            currOR |= x;
        } else {
            segments++;
            currOR = x;
        }
    }
    return segments <= M;
}
int minimumMaximumOR(vector<int>& A, int M) {
    int low = 0, high = 0;

    for (int x : A) {
        low = max(low, x);
        high |= x;
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canDivide(A, M, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << minimumMaximumOR(A, M) << endl;
    return 0;
}
