#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

typedef long long ll;
ll T;
vector<ll>hasil(T);

void cek(int N, ll K){
    if ((K%2) != 0){
        hasil.push_back(1);    
    }else if (N>1 && (K/2)%2 != 0 )
    {
        /* code */
    }
    
}


int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        cin >> T;
    for (int i = 0; i < T; i++){
        int N; ll K;
        cin >> N >> K;
        cek(N,K);
    }
    
}