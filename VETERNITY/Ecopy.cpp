#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

struct Virus {
    ll l;
    ll r;
};

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll W, N, X, R;
        cin >> W >> N;
    
    vector<Virus> mok;
    vector<ll> titik;
    ll minX = LLONG_MAX, maxX = LLONG_MIN;

    for (int i = 0; i < N; i++) {
        cin >> X >> R;
            minX = min(minX, X);
            maxX = max(maxX, X);

        ll kiri = max(1LL, X - R);
        ll kanan = min(W, X + R);
        mok.push_back({kiri, kanan});

        titik.push_back(X);
    }
    
    sort(mok.begin(), mok.end(), [](auto &a, auto &b) {
        return a.l < b.l || (a.l == b.l && a.r < b.r);
    });

    vector<Virus> wok;
    for(auto Z : mok) {
        if(wok.empty() || wok.back().r < Z.l) {
            wok.push_back(Z);
        } else {
            wok.back().r = max(wok.back().r, Z.r);
        }
    }

    vector<ll> aman;
    aman.push_back(1);
    ll pos = 1;

    for (auto V : wok) {
        if (pos < V.l) {
            for (ll p = max(1LL, pos); p < V.l; p++) {
                aman.push_back(p);
            }
        }
        pos = V.r + 1;
    }
    
    for(ll p = pos; p <= W; p++){
        aman.push_back(p);
    }

    sort(aman.begin(), aman.end());
    aman.erase(unique(aman.begin(), aman.end()), aman.end());

    ld mid = ( (ld)minX + (ld)maxX) / 2.0L;
    ll mid2 = floor(mid);

    auto it = lower_bound(aman.begin(), aman.end(), mid2);

    ll hasilC = -1, hasilR = LLONG_MAX;

    auto cek = [&](ll C) {
        if (C < 1 || C > W)
        {
            return;
        }
        ll need = 0;
        for(ll Q : titik) {
            ll d = abs(C - Q);
            need = max(need, d);
        }
        if (need < hasilR || (need == hasilR && (hasilC == -1 || C < hasilC)))
        {
            hasilC = C;
            hasilR = need;
        }
        
    };

    auto it2 = lower_bound(aman.begin(), aman.end(), mid2 + 1);
    if(it2 != aman.end()) {
        cek(*it2);
    }
    if (it2 != aman.begin()) {
        cek (*prev(it2));
    }

    cek(aman.front());
    cek(aman.back());

    cout << hasilC << " " << hasilR;
}