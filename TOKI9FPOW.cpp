#include <bits/stdc++.h>
using namespace std;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<long long> bil(T);

    for (int i = 0; i < T; i++) {
        cin >> bil[i];

        long long N = pow(2, bil[i]);

        if(N >= 10) {
        string str = to_string(N);
        long long sum = 0;
            for(char c : str) {
                sum += c - '0';
            }
        N = sum;
        }
        cout << N << "\n";
    }
    return 0;
}