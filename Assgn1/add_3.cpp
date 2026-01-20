#include <iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int mini = A[0];
    int maxi = A[0];

    for (int i = 1; i < N; i++) {
        if (A[i] < mini)
            mini = A[i];
        if (A[i] > maxi)
            maxi = A[i];
    }

    cout << mini + maxi << endl;

    return 0;
}
