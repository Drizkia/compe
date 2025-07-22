#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
        cin >> x;

    bool cek = false;

    while (x > 0) {
        if ((x & 1) == 0) {
            cek = true;
            break;
        }
        x >>= 1;
    }
    
    cout << (cek ? "YES" : "NO") << "\n";
    return 0;
}