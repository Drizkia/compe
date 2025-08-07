#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInt {
public:
    vector<int> digits; // Simpan digit dari belakang (LSB dulu)
    bool negative = false;

    // Konstruktor dari string
    BigInt(string s) {
        if (s[0] == '-') {
            negative = true;
            s = s.substr(1);
        }
        reverse(s.begin(), s.end());
        for (char c : s) digits.push_back(c - '0');
        trim();
    }

    // Konstruktor dari int
    BigInt(int n = 0) {
        if (n < 0) {
            negative = true;
            n = -n;
        }
        if (n == 0) digits.push_back(0);
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    // Hapus nol di depan
    void trim() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            negative = false;
    }

    // Output
    friend ostream& operator<<(ostream& os, const BigInt& b) {
        if (b.negative) os << "-";
        for (int i = b.digits.size() - 1; i >= 0; i--)
            os << b.digits[i];
        return os;
    }

    // Perbandingan
    bool operator<(const BigInt& b) const {
        if (negative != b.negative) return negative;
        if (digits.size() != b.digits.size())
            return negative ? digits.size() > b.digits.size() : digits.size() < b.digits.size();
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != b.digits[i])
                return negative ? digits[i] > b.digits[i] : digits[i] < b.digits[i];
        }
        return false;
    }

    bool operator==(const BigInt& b) const {
        return digits == b.digits && negative == b.negative;
    }

    // Penjumlahan
    BigInt operator+(const BigInt& b) const {
        if (negative == b.negative) {
            BigInt result;
            result.negative = negative;
            int carry = 0;
            int n = max(digits.size(), b.digits.size());
            for (int i = 0; i < n || carry; i++) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < b.digits.size()) sum += b.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            result.trim();
            return result;
        }
        // a + (-b) = a - b
        if (negative) return b - (-*this);
        return *this - (-b);
    }

    // Unary minus
    BigInt operator-() const {
        BigInt result = *this;
        result.negative = !negative;
        result.trim();
        return result;
    }

    // Pengurangan
    BigInt operator-(const BigInt& b) const {
        if (negative != b.negative) return *this + (-b);
        if (*this < b) return -(b - *this);

        BigInt result;
        result.negative = negative;
        int borrow = 0;
        for (int i = 0; i < digits.size(); i++) {
            int sub = digits[i] - borrow;
            if (i < b.digits.size()) sub -= b.digits[i];
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(sub);
        }
        result.trim();
        return result;
    }

    // Perkalian
    BigInt operator*(const BigInt& b) const {
        BigInt result;
        result.digits.resize(digits.size() + b.digits.size());
        for (int i = 0; i < digits.size(); i++) {
            int carry = 0;
            for (int j = 0; j < b.digits.size() || carry; j++) {
                long long mul = result.digits[i + j] + digits[i] * (j < b.digits.size() ? b.digits[j] : 0) + carry;
                result.digits[i + j] = mul % 10;
                carry = mul / 10;
            }
        }
        result.negative = negative != b.negative;
        result.trim();
        return result;
    }

    // Pembagian (versi sederhana)
BigInt operator/(const BigInt& b) const {
    BigInt result, cur;
    result.digits.resize(digits.size());

    for (int i = digits.size() - 1; i >= 0; i--) {
        // Geser digit ke kiri (prepend)
        cur.digits.insert(cur.digits.begin(), digits[i]);
        cur.trim();

        // Cari digit hasil bagi di posisi ini
        int x = 0;
        while (b * BigInt(x + 1) <= cur) x++;
        result.digits[i] = x;

        // Kurangi bagian yang sudah dibagi
        cur = cur - b * BigInt(x);
    }

    result.negative = negative != b.negative;
    result.trim();
    return result;
}

    // Modulo
    BigInt operator%(const BigInt& b) const {
        return *this - (*this / b) * b;
    }
};

int main() {
    BigInt a("12345678901234567890");
    BigInt b("98765432109876543210");

    cout << "a + b = " << a + b << endl;
    cout << "b - a = " << b - a << endl;
    cout << "a * b = " << a * b << endl;
    cout << "b / a = " << b / a << endl;
    cout << "b % a = " << b % a << endl;
}