#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,Q;
        cin >> N >> Q;

    vector<int> patok (N);
    vector<int> X(N);
        for (int i = 0; i < N; i++){
            cin >> patok[i];
            if(i == 0) {
                X[i] = patok[i];
            } else {
                X[i] = X[i-1] + patok[i];
            }
        }
        
        for (int i = 0; i < Q; i++) {
            int jarak;
                cin >> jarak;
                int idx = upper_bound(X.begin(), X.end(), jarak) - X.begin();
                cout << idx << "\n";
        }
    return 0;
}