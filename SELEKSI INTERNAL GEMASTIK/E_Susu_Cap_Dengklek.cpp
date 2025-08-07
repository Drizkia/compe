#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
        cin >> A >> B;
        cin >> C >> D;

    if ((A*D) == (B*C) || (1.0 * (A/B)) == (1.0 * (C/D))) {
        cout << "sama";
    } else if ((A*D) > (B*C) || (1.0 * (A/B)) > (1.0 * (C/D))) {
        cout << "lebih besar";
    } else if ((A*D) < (B*C) || (1.0 * (A/B)) < (1.0 * (C/D))) {
        cout << "lebih kecil";
    }
}