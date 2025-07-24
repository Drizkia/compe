#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> A;

    int Q, T, V, Z;
        cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> T;
        if (T == 0) {
            cin >> V;
            A.push_back(V);
        } else if(T == 1) {
                cin >> Z;
                cout << A[Z] << "\n";
            } else if (T == 2) {
                    A.pop_back();
                }
    }
    return 0;
}