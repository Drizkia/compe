#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int daging, ayam, udang, ikan, day = 0;
        cin >> daging >> ayam >> udang >> ikan;
    
    if (daging == 3) {
        daging -= daging;
        day++;
    } else if (ayam == 3) {
        ayam -= ayam;
        day++;
    } else if (udang == 3) {
        udang -= udang;
        day++;
    } else if (ikan == 3) {
        ikan -= ikan;
        day++;
    }
    
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
}