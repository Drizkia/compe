#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    deque<int> X;
    int N;
        cin >> N;
        cin.ignore();
    int temp;

    for (int i = 0; i < N; i++) {
        string O, P;
        getline(cin, O);
        temp = 0;
        stringstream ss(O);
        ss >> P;

        if (P == "push_back") {
            ss >> temp;
            X.push_back(temp);
            //isi variabel ke paling belakang
        } else if(P == "push_front"){
            ss >> temp;
            X.push_front(temp);
            //isi variabel ke paling depan
        } else if (P == "pop_back"){
            //hapus variabel paling depan
            X.pop_back();
        } else if (P == "pop_front"){
            //hapus variabel paling depan
            X.pop_front();
        }
    }    
    for (int Z : X) {
        cout << Z << "\n";
    }
    
}