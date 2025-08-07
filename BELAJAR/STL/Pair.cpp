#include <bits/stdc++.h>
using namespace std;

// hanya punya first dan second
// Pair ga ada key, ga kaya MAP yang dia punya (X[] = " ");

int main() {
    pair<int, string> p = {1, "Geeks"};

    // Variabel di pair masuk ke a dan s
    int a;
    string s;

    // ekstrak value ke a dan s dengan nama tie
    tie(a, s) = p;

    cout << "First value: " << a << endl;
    cout << "Second value: " << s;
    return 0;
}