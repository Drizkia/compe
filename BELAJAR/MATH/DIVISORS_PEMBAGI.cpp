#include <iostream>
#include <vector>
using namespace std;

//Algoritma Tentuin Divisor/Pembagi
//klo pembagi lebih dari 1 dan N maka bukan prima
vector<int> getDivisors(int n) {
    vector<int> div;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i)
                div.push_back(n / i);
        }
    }
    return div;
}

//Tentuin prima apa bukan?
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> d = getDivisors(n);
    cout << "Divisors: ";
    for (int x : d) cout << x << " ";
    cout << "\n";

    if (isPrime(n))
        cout << n << " is a prime number\n";
    else
        cout << n << " is NOT a prime number\n";
}