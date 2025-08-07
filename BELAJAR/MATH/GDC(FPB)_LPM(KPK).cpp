#include <iostream>
using namespace std;

// GDC(FPB)
// Dia nentuin pembagi terbesar dari suatu bilangan
int fpb(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// LCM(KPK)
// Total angka dari pembagi bilangan tsb
int kpk(int a, int b) {
    return (a / fpb(a, b)) * b;
}

int main() {
    int a, b;
        cin >> a >> b;

    cout << "FPB : " << fpb(a,b) << endl;
    cout << "KPK : " << kpk(a,b) << endl;
}
