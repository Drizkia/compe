#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(K), pref(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pref[i] = A[i] + (i > 0 ? pref[i-1] : 0);
    }

    for (int i = 0; i < K; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < K; i++) {
        // gunakan upper_bound untuk cari patok terakhir yang bisa dilewati
        int idx = upper_bound(pref.begin(), pref.end(), B[i]) - pref.begin();
        cout << idx << '\n';
    }

    return 0;
}
