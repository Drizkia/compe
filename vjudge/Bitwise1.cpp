#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    cout << (n & k) << "\n";
    cout << (n | k) << "\n";
    cout << (n ^ k) << "\n";
    return 0;
}