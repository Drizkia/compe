#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long count = 0;

    // Coba semua kemungkinan A dan B
    for (int A = 0; A <= N; A++) {
        for (int B = 0; B <= N; B++) {
            int C = N - A - B; // hitung C langsung
            if (C >= 0) {      // pastikan C tidak negatif
                count++;
            }
        }
    }

    cout << count << endl;
}