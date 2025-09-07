#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

int T, N, K;

// struct DSU {
//     vector<int> parent, sz;

//         DSU(int n) {
//             parent.resize(n + 1);
//             sz.resize(n+1, 1);
//             for (int i = 0; i <= n; i++) {
//                 parent[i] = i;
//             }
//         }
//         int find (int x) {
//             if (x == parent[x]) return x;
//             return parent[x] = find(parent[x]);
//         }
//         void unite (int a, int b) {
//             a = find(a);
//             b = find(b);
//             if (a != b) {
//                 if (sz[a] < sz[b]) {
//                     swap (a, b);
//                     cout << sz[a] << sz[b];
//                 }
//                 parent[b] = a;
//                 sz[a] += sz[b];
//             }
//         }
// };

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int X[T];
    vector<int>::iterator it;

    cin >> T;
        // DSU dsu(pow(N, 2));
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
    }

    for (int j = 0; j < T; j++) {
        int it = X[j+1];
        for (int i = 1; i <= pow(N, 2); i++) {
            X[i] = i;
            cout << X[i];
            
        }
    }    
}