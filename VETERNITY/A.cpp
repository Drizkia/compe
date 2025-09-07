#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

    vector<long long> angka = {2, 3, 4, 5, 7, 8, 9};
    long long a, b;
    long long jumlah = 0;

void dfs(long long X) {
    if (X > b) {
        return;
    }

    if (X >= a && (X % 3 == 0 || X % 5 == 0)) {
        jumlah++;
    }

    for (long long d : angka) {
        if (X == 0 && d == 0) {
            continue;
        } else if (X > (b - d) / 10){
            continue;
        }
        dfs(X * 10 + d);
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

        cin >> a >> b;
    
    dfs(0);
    

    cout << jumlah << endl;
}