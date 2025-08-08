#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    int X, N;
        cin >> N;
        cin >> X;

    // lower_bound
    for (int i = 0; i < N; i++) {
        int lb = lower_bound(v[i + 1], v[i - 1], X)/2;
    }
    cout << "Lower bound index: " << lb << "\n";
}
