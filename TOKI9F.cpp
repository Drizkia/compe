#include <bits/stdc++.h>
using namespace std;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<int> bil(T);

    for (int i = 0; i < T; i++) {
        cin >> bil[i];
        int temp1 = 0; int temp2 = 0; int temp = 0;
        if((1 << bil[i]) >= 10) {
            temp1 = bil[i] % 10;
            temp2 = bil[i] / 10;
            temp1 + temp2;
            cout << temp << "\n";
            continue;
        }
        cout << (1 << bil[i]) << "\n";
    }
    return 0;
}