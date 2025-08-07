// push_back(val)	Tambah elemen di belakang
// push_front(val)	Tambah elemen di depan
// pop_back()	Hapus elemen dari belakang
// pop_front()	Hapus elemen dari depan
// front()	Ambil elemen pertama
// back()	Ambil elemen terakhir
// size()	Jumlah elemen
// empty()	Cek apakah deque kosong
// clear()	Hapus semua elemen
// dq[i]	Akses elemen ke-i (seperti array)

// Dipake ketika butuh akses elemen depan dan belakang

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);   // [10]
    dq.push_front(5);   // [5, 10]
    dq.push_back(15);   // [5, 10, 15]

    cout << "Front: " << dq.front() << endl; // 5
    cout << "Back: " << dq.back() << endl;   // 15

    dq.pop_front(); // [10, 15]
    dq.pop_back();  // [10]

    cout << "Size: " << dq.size() << endl;   // 1
}
