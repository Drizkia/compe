#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::set<int> set;
    int N, X;
    std::cin >> N;
    while (N--) {
        std::cin >> X;
        set.insert(X);
    }
    std::cout << set.size();
}