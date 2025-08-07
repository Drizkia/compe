#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    int hari = 0;

    while (A > 0 || B > 0 || C > 0 || D > 0) {
        int perhari = 0;
 
        bool pakaiA = (A >= B && A > 0);
        bool pakaiB = (B > A && B > 0);

        bool pakaiC = (C >= D && C > 0);
        bool pakaiD = (D > C && D > 0);

        while (perhari < 3) {
            if (pakaiA && A > 0) {
                A--;
                perhari++;
            } else if (pakaiB && B > 0) {
                B--;
                perhari++;
            }

            if (perhari >= 3) break;

            if (pakaiC && C > 0) {
                C--;
                perhari++;
            } else if (pakaiD && D > 0) {
                D--;
                perhari++;
            }

            if ((!pakaiA && !pakaiB) && (!pakaiC && !pakaiD)) {
                break;
            }
        }

        hari++;
    }

    cout << hari;
}