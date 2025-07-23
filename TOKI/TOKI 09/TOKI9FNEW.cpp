#include <iostream>
#include <vector>

const int max_N = 5000;
std::vector<int> simpan_tebak(max_N + 1);

void pangkat() {
    std::vector<int> hasil = {1};
    simpan_tebak[0] = 1;

    for (int i = 1; i <= max_N; i++) {
       int X = 0;
       int sz = hasil.size();
        for(int j = 0; j < sz; j++) {
            int Y = hasil[j] * 2 + X;
            hasil[j] = Y % 10;
            X = Y / 10;
        }
        while (X) {
            hasil.push_back(X % 10);
            X /= 10;
        }
        int Z = 0;
        for(int d : hasil) {
            Z += d;
        }
        simpan_tebak[i] = Z;
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    pangkat();
    int T, N;
        std::scanf("%d", &T);

    while (T--) {
        std::scanf("%d", &N);
            std::cout << simpan_tebak[N] << "\n";
    }
    return 0;
}