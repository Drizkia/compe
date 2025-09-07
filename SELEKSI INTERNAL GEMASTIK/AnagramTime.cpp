#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000 + 5;
static char sbuf[MAXN];
static char candA[MAXN];
static char candB[MAXN];
static char resA[MAXN];
static char resB[MAXN];

// strip leading zeros in [ptr, ptr+n), return index offset (0..n-1)
inline int strip_leading(const char *ptr, int n) {
    int i = 0;
    while (i + 1 < n && ptr[i] == '0') ++i;
    return i;
}

// Compute |X - Y| where X and Y are digit strings at ptrX (len nX) and ptrY (len nY).
// Write trimmed result into out, return length.
int bigAbsDiff_generic(const char *ptrX, int nX, const char *ptrY, int nY, char *out) {
    int sx = strip_leading(ptrX, nX);
    int sy = strip_leading(ptrY, nY);
    const char *A = ptrX + sx; int na = nX - sx;
    const char *B = ptrY + sy; int nb = nY - sy;

    bool A_ge_B;
    if (na != nb) A_ge_B = (na > nb);
    else {
        int cmp = memcmp(A, B, na);
        A_ge_B = (cmp >= 0);
    }

    const char *big = A_ge_B ? A : B;
    const char *sml = A_ge_B ? B : A;
    int nbig = A_ge_B ? na : nb;
    int nsml = A_ge_B ? nb : na;

    int carry = 0;
    for (int i = 0; i < nbig; ++i) {
        int db = big[nbig - 1 - i] - '0';
        int ds = (i < nsml) ? (sml[nsml - 1 - i] - '0') : 0;
        int cur = db - ds - carry;
        if (cur < 0) { cur += 10; carry = 1; } else carry = 0;
        out[nbig - 1 - i] = char('0' + cur);
    }
    int st = 0;
    while (st + 1 < nbig && out[st] == '0') ++st;
    if (st > 0) {
        int newlen = nbig - st;
        memmove(out, out + st, newlen);
        return newlen;
    }
    return nbig;
}

// build next perm (smallest > src) into dest, return true if exists
bool build_next_count(const char *src, char *dest, int n) {
    memcpy(dest, src, n);
    int i = n - 2;
    while (i >= 0 && dest[i] >= dest[i+1]) --i;
    if (i < 0) return false;
    int cnt[10] = {0};
    for (int k = i+1; k < n; ++k) cnt[dest[k] - '0']++;
    int pivot = dest[i] - '0';
    int chosen = -1;
    for (int d = pivot + 1; d <= 9; ++d) if (cnt[d]) { chosen = d; break; }
    int j = -1;
    for (int k = n-1; k > i; --k) if (dest[k] - '0' == chosen) { j = k; break; }
    swap(dest[i], dest[j]);
    cnt[chosen]--;
    cnt[pivot]++;
    int pos = i+1;
    for (int d = 0; d <= 9; ++d) while (cnt[d]-- > 0) dest[pos++] = char('0' + d);
    return true;
}

// build prev perm (largest < src) into dest, return true if exists
bool build_prev_count(const char *src, char *dest, int n) {
    memcpy(dest, src, n);
    int i = n - 2;
    while (i >= 0 && dest[i] <= dest[i+1]) --i;
    if (i < 0) return false;
    int cnt[10] = {0};
    for (int k = i+1; k < n; ++k) cnt[dest[k] - '0']++;
    int pivot = dest[i] - '0';
    int chosen = -1;
    for (int d = pivot - 1; d >= 0; --d) if (cnt[d]) { chosen = d; break; }
    int j = -1;
    for (int k = n-1; k > i; --k) if (dest[k] - '0' == chosen) { j = k; break; }
    swap(dest[i], dest[j]);
    cnt[chosen]--;
    cnt[pivot]++;
    int pos = i+1;
    for (int d = 9; d >= 0; --d) while (cnt[d]-- > 0) dest[pos++] = char('0' + d);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    if (!(cin >> S)) return 0;
    int n = S.size();
    memcpy(sbuf, S.data(), n);

    bool hasNext = build_next_count(sbuf, candA, n);
    bool hasPrev = build_prev_count(sbuf, candB, n);

    int lenA = -1, lenB = -1;
    if (hasNext) lenA = bigAbsDiff_generic(candA, n, sbuf, n, resA);
    if (hasPrev) lenB = bigAbsDiff_generic(sbuf, n, candB, n, resB);

    if (hasNext && hasPrev) {
        if (lenA < lenB) {
            cout.write(resA, lenA); cout.put('\n');
        } else if (lenB < lenA) {
            cout.write(resB, lenB); cout.put('\n');
        } else {
            int cmp = memcmp(resA, resB, lenA);
            if (cmp <= 0) cout.write(resA, lenA);
            else cout.write(resB, lenB);
            cout.put('\n');
        }
    } else if (hasNext) {
        cout.write(resA, lenA); cout.put('\n');
    } else if (hasPrev) {
        cout.write(resB, lenB); cout.put('\n');
    } else {
        cout << "0\n";
    }
    return 0;
}
