#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int mx = *max_element(a.begin(), a.end());
    vector<int> cnt(mx+1);
    for (int x : a) cnt[x]++;
    for (int i = 0; i <= mx; i++)
        while (cnt[i]--) cout << i << " ";
}
