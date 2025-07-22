#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int RP[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	
	int K, X = 1;
	cin >> K;
	
	for(int i = 0; i < 10; i++) {
		if (RP[i] <= K) {
			K -= RP[i];
			
            if (K >= RP[i])
            {
                i--;
                X++;
            } else
            {
                cout << RP[i] << " " << X << "\n";
                X = 1;
            }
			};
	}
}