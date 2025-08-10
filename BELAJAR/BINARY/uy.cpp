#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 3, 3, 5, 7};
    int X = 3;

    // LOWER_BOUND
    auto it_low = lower_bound(v.begin(), v.end(), X);
    int idx_low = it_low - v.begin();

    // UPPER_BOUND
    auto it_up = upper_bound(v.begin(), v.end(), X);
    int idx_up = it_up - v.begin();

    cout << "Lower bound index : " << idx_low << " (nilai = " << *it_low << ")\n";
    cout << "Upper bound index : " << idx_up << " (nilai = " << *it_up << ")\n";
}