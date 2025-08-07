#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    int hari = 0;

    while (A > 0 || B > 0 || C > 0 || D > 0) {
        int perhari = 0;

        // Pilih apakah kita mau pakai A atau B hari ini (yang lebih besar prioritas dulu)
        bool pakaiA = (A >= B && A > 0);
        bool pakaiB = (B > A && B > 0);

        // Pilih apakah kita mau pakai C atau D hari ini
        bool pakaiC = (C >= D && C > 0);
        bool pakaiD = (D > C && D > 0);

        // Proses maksimal 3 item sesuai aturan
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

            // Kalau tidak bisa ambil dari sisi lain, tetap break
            if ((!pakaiA && !pakaiB) && (!pakaiC && !pakaiD)) {
                break;
            }
        }

        hari++;
    }

    cout << hari << endl;
    return 0;
}