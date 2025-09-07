#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid(ll mid, const vector<ll> &A, int K) {
    ll count = 1, sum = 0;
    for (int a : A) {
        if (a > mid) return false;
        if (sum + a > mid) {
            count++;
            sum = a;
        } else {
            sum += a;
        }
    }
    return count <= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
        cin >> N >> K;
    vector<ll> A(N);
        for (auto &x : A) cin >> x;

    ll left = *max_element(A.begin(), A.end());
    ll right = accumulate(A.begin(), A.end(), 0LL);
    ll answer = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (isValid(mid, A, K)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer;
}