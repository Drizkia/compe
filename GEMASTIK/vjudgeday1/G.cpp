#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
        cin >> n;
    vector<int> kubus(n);
    for (int i = 0; i < n; ++i) {
        cin >> kubus[i];
    }

    multiset<int> X;
    for (int Y : kubus) {
        auto it = X.upper_bound(Y);
        if (it != X.end()) {
            X.erase(it);
        }
        X.insert(Y);
    }

    cout << X.size();
}