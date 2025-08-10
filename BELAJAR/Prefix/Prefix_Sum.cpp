#include <bits/stdc++.h>
using namespace std;

// Vector ketika N adalah pasti/static
void vector_pasti() {
    vector<int> A = {5, 2, 7, 3, 4};
    int n = A.size();

    vector<int> prefix(n);
    prefix[0] = A[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + A[i];
    }

    int L = 1, R = 3;
    int sum = prefix[R] - (L > 0 ? prefix[L-1] : 0); // Keluarin total prefix
    cout << "Jumlah dari indeks " << L << " sampai " << R << " = " << sum << endl;
}

// Vector ketika Dynamic Vector
int main() {
    int n, temp = 0;
    cin >> n;
    vector<int> A(n);
    vector<int> prefix;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        temp += A[i];
        prefix.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0){
            cout << "Asli    " << "Prefix\n";
        }
        cout << A[i] << " " << prefix[i] << "\n"; //Keluarin per index
    }
}