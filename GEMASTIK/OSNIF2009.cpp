#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    vector<int> X;
    int N;
        cin >> N;
        cin.ignore();
    string Y;
    int temp;

    for (int i = 0; i < N; i++) {
        getline(cin, Y);
            cin.ignore();
        cin >> temp;
        if (Y == "push_back") {
            X.push_back(temp);
            //isi variabel ke paling belakang
        } else if(Y == "push_front"){
            X.insert(X.begin(), temp);
            //isi variabel ke paling depan
        } else if (Y == "pop_back"){
            //hapus variabel paling depan
            X.erase(X.begin());
        } else if (Y == "pop_front"){
            //hapus variabel paling depan
            X.pop_back();
        }
        cout << X[i] << "\n";
    }
}