#include <bits/stdc++.h>
using namespace std;


int main(int argc,char const *argv[]) {
    int A, B, C, D;
    int hari = 0;
        cin >> A >> B >> C >> D;
    
        // A = Daging
        // B = Ayam
        // C = Udang
        // D = Ikan

    if (A >= 3) {
        hari += A/3;
        A = A%3;
    }

    if (A < 3 && A > 0) {
        int sisa = 3 - A;
        A = 0;
        if (C > 0 && B <= 0) {
            C -= sisa;
        } else if(D > 0 && C <= 0 && B <= 0) {
            D -= sisa;
        }
        hari++;
    }

    if (B >= 3) {
        hari += B/3;
        B = B%3;
    }

    if (B < 3 && B > 0) {
        int sisa = 3 - B;
        B = 0;
        if (C > 0 && B <= 0) {
            C -= sisa;
        } else {
            D -= sisa;
        }
        hari++;
    }
    
    if (C >= 3) {
        hari += C/3;
        C=C%3;
    }

    if (C > 0 && C < 3) {
        C = 0;
        hari++;
    }
    
    if (D >= 3) {
        hari += D/3;
        D=D%3;
    }
    if (D > 0 && D < 3) {
        D = 0;
        hari++;
    }
    
    cout << hari;
    return 0;
}