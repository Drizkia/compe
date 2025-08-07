// pq.push(x)	Menambahkan elemen x ke antrian
// pq.top()	Melihat elemen dengan prioritas tertinggi
// pq.pop()	Menghapus elemen dengan prioritas tertinggi
// pq.empty()	Cek apakah kosong
// pq.size()	Jumlah elemen dalam antrian

// Seperti Queue (Masuk Pertama Keluar Duluan (FiFo)) tapi dengan prioritas
// Default nilai maksimal

#include <iostream>
#include <queue>
using namespace std;

int maksimal() { // Set prioritas ke nilai tertinggi
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);

    while (!pq.empty()) {
        cout << pq.top() << " "; // Output: 20 10 5
        pq.pop();
    }
}

int minimal() { // Set prioritas ke nilai terendah
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);

    while (!pq.empty()) {
        cout << pq.top() << " "; // Output: 5 10 20
        pq.pop();
    }
}

int main() {
    maksimal();
    minimal();
}