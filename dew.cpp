#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,Q, temp = 0;
        cin >> N >> Q;

        vector<int> patok (N);
        vector<int> X(N);
            for (int i = 0; i < N; i++){
                cin >> patok[i];
                temp += patok [i];
                patok[i] =temp;
            }
        
        for (int i = 0; i < Q; i++) {
            int jarak;
                cin >> jarak;
                int idx = upper_bound(patok.begin(), patok.end(), jarak) - patok.begin();
                cout << idx << "\n";
        }
}