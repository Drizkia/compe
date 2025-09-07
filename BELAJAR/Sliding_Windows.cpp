#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int sum = 0;
    for (int i = 0; i < k; i++) sum += a[i]; // sum awal
    int max_sum = sum;

    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k]; // geser window
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
}