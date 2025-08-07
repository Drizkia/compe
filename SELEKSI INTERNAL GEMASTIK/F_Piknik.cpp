#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
        cin >> N >> M;
    
    vector<int>kiri(M),kanan(M);
    for (int i = 0; i < M; i++){
        cin >> kiri[i] >> kanan[i];
    }
    
    set<int>mobil;
    for (int i = 0; i < N; i++){
        if(kiri[i] == i){
            mobil.insert(i);
            mobil.insert(kanan[i]);
        
        } if (kanan[i]==i){
            mobil.insert(i);
            mobil.insert(kiri[i]);  
        }
    }
    
}
