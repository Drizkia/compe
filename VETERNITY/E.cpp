#include <bits/stdc++.h>
using namespace std;

struct Interval {
    long long l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long W;
    int N;
        cin >> W >> N;

    vector<Interval> virus(N);
    long long minL = LLONG_MAX, maxR = LLONG_MIN;
    vector<long long> aman;
    vector<Interval> merged;

    for (int i = 0; i < N; i++) {
        long long x, r;
            cin >> x >> r;
                virus[i] = {x - r, x + r};
                minL = min(minL, x - r);
                maxR = max(maxR, x + r);
    }

    sort(virus.begin(), virus.end(), [](auto &a, auto &b) {
        return a.l < b.l || (a.l == b.l && a.r < b.r);
    });

    for (auto &X : virus) {
        if (merged.empty() || merged.back().r < X.l) {
            merged.push_back(X);
        } else {
            merged.back().r = max(merged.back().r, X.r);
        }
    }

        aman.push_back(1);

    long long last = 1;

    for (auto &it : merged) {
        if (last < it.l) {
            for (long long p = max(last, 1LL); p < it.l; p++) {
                aman.push_back(p);
            }
        }
        last = max(last, it.r + 1);
    }
    for (long long p = last; p <= W; p++){
        aman.push_back(p);
    }

        long long mid = (minL + maxR) / 2;

        auto it = lower_bound(aman.begin(), aman.end(), mid);

        long long bestC = -1, bestR = LLONG_MAX;

    auto check = [&](long long C) {
        if (C < 1 || C > W) return;
            long long R = max(C - minL, maxR - C);
        if (R < bestR || (R == bestR && C < bestC)) {
            bestR = R;
            bestC = C;
        }
    };

    if (it != aman.end()) check(*it);
    if (it != aman.begin()) check(*prev(it));
        check(1);

    cout << bestC << " " << bestR << "\n";
}
