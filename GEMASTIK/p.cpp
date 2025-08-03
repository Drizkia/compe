#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int hasil = 0;

    int N; 
        cin >> N;

    for (int i = 1; i <= N; i++){
        if (N%i == 0) {
                hasil++;
        }else {
            continue;
        }
    }

    
    if (hasil == 5) {
        cout << "YES";
    } else {cout << "NO";}
}