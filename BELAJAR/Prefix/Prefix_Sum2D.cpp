#include <bits/stdc++.h>
using namespace std;

// Contoh Prefix Sum 1D
// Fungsi ini menghitung jumlah kumulatif dari array 1 dimensi.
// prefix[i] = jumlah elemen dari A[0] sampai A[i].
// Keuntungannya: bisa dapat sum(L, R) dalam O(1) waktu.
template <typename T>
void prefix_sum_1d(const vector<T>& A) {
    int n = A.size();
    vector<T> prefix(n);

    prefix[0] = A[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + A[i];
    }

    cout << "Asli\tPrefix" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t" << prefix[i] << "\n";
    }
}

// Contoh Prefix Sum 2D
// vector<vector<int>> adalah "nested vector" atau vektor bersarang.
// Artinya: setiap elemen dari vector utama adalah vector lain.
// Jadi bisa dibayangkan seperti array 2 dimensi (baris x kolom),
// tapi fleksibel karena tiap baris bisa punya panjang berbeda.
// Dalam kasus ini, kita pakai ukuran sama untuk semua baris, jadi bentuknya benar-benar seperti matriks.
// Rumus: prefix[i][j] = A[i][j] + atas + kiri - tumpang_tindih
void prefix_sum_2d(const vector<vector<int>>& A) {
    int n = A.size();          // jumlah baris
    int m = A[0].size();       // jumlah kolom

    // prefix adalah nested vector: vektor berisi vektor int
    vector<vector<int>> prefix(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i][j] = A[i][j]
                          + (i > 0 ? prefix[i-1][j] : 0)   // atas
                          + (j > 0 ? prefix[i][j-1] : 0)   // kiri
                          - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0); // tumpang tindih
        }
    }

    cout << "\nPrefix Sum 2D:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << prefix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    // Prefix Sum 1D
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    prefix_sum_1d(A);

    // Prefix Sum 2D
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> B(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> B[i][j];
        }
    }
    prefix_sum_2d(B);

    return 0;
}
