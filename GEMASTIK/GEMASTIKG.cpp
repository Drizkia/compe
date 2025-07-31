#include <stdio.h>
int main () {
    long long N, K;
    scanf("%lld", &N);
    scanf("%lld", &K);
    printf("%lld", (N*K - (N-1)));
}