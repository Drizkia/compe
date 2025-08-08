#include <bits/stdc++.h>
using namespace std;

bool bisa(int X) {
    // fungsi cek kondisi (greedy/dp) sesuai X
}

void anggep_aja_main() {
    int low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (bisa(mid)) {
            ans = mid;
            high = mid - 1; // cari yg lebih kecil
        } else {
            low = mid + 1; // cari yg lebih besar
        }
    }
    cout << ans << "\n";
}

///////////////////////////////////////////////////////////////////////////

int binarySearch(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // aman dari overflow

        if (arr[mid] == target) return mid; // ketemu
        else if (arr[mid] < target) low = mid + 1; // geser ke kanan
        else high = mid - 1; // geser ke kiri
    }
    return -1; // tidak ditemukan
}

int main() {
    vector<int> arr = {2, 5, 7, 10, 13, 17, 20};
    int target = 13;

    int idx = binarySearch(arr, target);
    if (idx != -1) cout << "Ketemu di indeks: " << idx << "\n";
    else cout << "Tidak ditemukan\n";
}