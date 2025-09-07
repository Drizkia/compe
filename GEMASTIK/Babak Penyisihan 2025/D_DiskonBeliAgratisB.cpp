#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/
typedef long long ll;

int main () {

    int N, A, B;
    ll temp;
        ll hasil = 0;
        cin >> N >> A >> B;
    int X = A + B;
    vector<ll> harga;
    vector<ll> harga2;
    
    for (int i = 0; i < N; i++) {
        cin >> temp;
        harga.push_back(temp);
    }
    sort(harga.begin(), harga.end());

    for (int i = 0; i < N; i++) {
        harga2.push_back(harga[i]);
    }
    
    if (N > X) {
        for (int i = 0; i < A; i++) {
            hasil += (ll)*max_element(harga.begin(), harga.end());
            harga.pop_back();
        }
        ll Z = abs((A + B) - N);
        sort(harga2.begin(), harga2.end(), greater<ll>());
        for (int j = 0; j < Z; j++) {
            hasil += (ll)*min_element(harga2.begin(), harga2.end());
            harga2.pop_back();
        }
    } else if (X == N || X >= N) {
        for (int i = 0; i < N; i++) {
            hasil += harga[i];
        }
    }
    cout << hasil << "\n";
}