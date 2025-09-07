#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    vector<Person> v = {{"A", 20}, {"B", 18}, {"C", 20}, {"D", 18}};

    // Sort hanya berdasarkan age
    stable_sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.age < b.age;
    });

    for (auto &p : v) cout << p.name << " " << p.age << "\n";
}
