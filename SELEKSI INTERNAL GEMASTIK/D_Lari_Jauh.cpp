#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    int A[N];
    int B[K];
    int temp=0;
        cin >> N;
    vector<int>pref;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        temp += A[i];
        pref.push_back(temp);
    }
    for (int i = 0; i < K; i++) {
        cin >> B[i];
    }
    
    vector<int>hasil;
    for(int i = 0; i < N; i++){
        if (B[i] < pref[i]){
            hasil.push_back(i-1);
        }
    }
    
    for (int i = 0; i < N; i++){
        cout << hasil[i];
    }
    
}