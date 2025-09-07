#include <bits/stdc++.h>
using namespace std;

// Fungsi untuk menghitung selisih absolut big integer (string)
string bigSub(string a, string b) {
    // Pastikan a >= b
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) swap(a, b);

    string res;
    int carry = 0;
    int n = a.size(), m = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        int x = (a[i] - '0') - carry - (i < m ? (b[i] - '0') : 0);
        if (x < 0) {
            x += 10;
            carry = 1;
        } else carry = 0;
        res.push_back(char(x + '0'));
    }

    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

// Fungsi next_permutation manual untuk string besar
bool next_perm(string &s) {
    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1]) i--;
    if (i < 0) return false;
    int j = s.size() - 1;
    while (s[j] <= s[i]) j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    return true;
}

// Fungsi prev_permutation manual untuk string besar
bool prev_perm(string &s) {
    int i = s.size() - 2;
    while (i >= 0 && s[i] <= s[i + 1]) i--;
    if (i < 0) return false;
    int j = s.size() - 1;
    while (s[j] >= s[i]) j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    string nextN = N, prevN = N;
    bool hasNext = next_perm(nextN);
    bool hasPrev = prev_perm(prevN);

    string ans;
    if (hasNext && hasPrev) {
        string diff1 = bigSub(N, nextN);
        string diff2 = bigSub(N, prevN);
        if (diff1.size() < diff2.size() || (diff1.size() == diff2.size() && diff1 < diff2))
            ans = diff1;
        else
            ans = diff2;
    } else if (hasNext) {
        ans = bigSub(N, nextN);
    } else if (hasPrev) {
        ans = bigSub(N, prevN);
    }

    cout << ans << "\n";
    return 0;
}
