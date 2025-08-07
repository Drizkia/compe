#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
        cin >> A >> B >> C >> D;

    long long pecahan1 = (long long) A*D, pecahan2 = (long long) B*C;

    if (pecahan1 == pecahan2) {
        cout << "sama";
    } else if (pecahan1 > pecahan2) {
        cout << "lebih besar";
    } else if (pecahan1 < pecahan2) {
        cout << "lebih kecil";
    }
}