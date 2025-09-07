#include <bits/stdc++.h>
using namespace std;


set<long long> sesuai;

void prepro() {
    for (long long a = 1; a <= 10000; ++a) {
        for (long long b = a + 1; b <= 10000; ++b) {
            sesuai.insert(a * a + b * b);
        }
    }
}

int main() {
    long long N;
    cin >> N;

    prepro();

    // Ambil elemen ke-N dari set
    auto it = sesuai.begin();
    advance(it, N - 1); // karena indeks mulai dari 0
    cout << *it << "\n";
}