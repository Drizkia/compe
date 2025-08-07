#include <iostream>
#include <vector>
using namespace std;

// {5, 6, 7, 8, 9} itr 7 (size = N/2)

// (++itr) buat geserin iterator ke indexs selanjutnya (ke 8 or 9)
// (--itr) buat geserin iterator ke indexs sebelumnya (ke 6 or 5)

void data_tengah_tanpa_Iterator() {
    vector<int> data {10, 20, 30, 40, 50};
    int N = data.size();

    if (N % 2 == 1) {
        // Ganjil → ambil satu elemen tengah
        cout << "Middle: " << data[N / 2] << endl;
    } else {
        // Genap → ambil dua elemen tengah
        cout << "Middle left: " << data[N / 2 - 1] << ", Middle right: " << data[N / 2] << endl;
        // atau rata-rata tengah:
        double avg = (data[N / 2 - 1] + data[N / 2]) / 2.0;
        cout << "Average of middles: " << avg << endl;
    }
}

void iterator_data_tengah() {
    vector<int> data {10, 20, 30, 40, 50, 60};
    int N = data.size();        // yang diambil sizenya
    vector<int>::iterator itr;

    if (N % 2 == 1) {
        // ganjil
        itr = data.begin() + N / 2;             // data dibagi 2
        cout << "Middle: " << *itr << endl;
    } else {
        // genap
        itr = data.begin() + N / 2 - 1;
        int left = *itr;
        int right = *(itr + 1);
        cout << "Middle elements: " << left << ", " << right << endl;
        cout << "Average of middles: " << (left + right) / 2.0 << endl;
    }
}

int main() {
    vector<int> numbers {1, 2, 3, 4, 5};

    // Deklarasi iterator first elemen
    vector<int>::iterator itr = numbers.begin();
    cout << "First Element: " << *itr << "  "<<endl;

    // Merubah iterator jadi last element
    itr = numbers.end() - 1;        // Kenapa -1? karna end merujuk pada ruang kosong belakang vector
    cout << "Last Element: " << *itr;

    iterator_data_tengah();
    data_tengah_tanpa_Iterator();
    return 0;  
}