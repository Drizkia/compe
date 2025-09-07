#include <bits/stdc++.h>
using namespace std;

/*
  ____ ___  ______   __  ____   _    ____ _____ _____        
 / __/ _ \|  _ \ \ / / |  _ \ / \  / ___|   _| ____|
| |  | | | | |) \ V /  | |) / _ \ \___ \ | | |  _|  
| || || |  __/ | |   |  __/ ___ \ ___) || | | |__ 
 \\/||||   || //   \\/ || ||
 / ___|  _ \| ____\ \      / /                        
| |   | |_) |  _|  \ \ /\ / /                         
| ||  _ <| |__  \ V  V /                          
 \|| \\|  \/\_/                           
  __
<(o )___
 ( ._> /
  `---'
  
*/


bool check(int mid, vector<int> &X, int k) {

    int n = X.size();
    int count = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (X[i] > mid) {
            return false;
        }

        sum += X[i];

        if (sum > mid) {
            count++;
            sum = X[i];
        }
    }
    count++;

    if (count <= k) {
        return true;
    } else {
        return false;
    }
}

int splitArray(vector<int> &X, int k) {

    int n = X.size();
    int max = *max_element(X.begin(), X.end());
    int start = max;
    int end = 0;

    for (int i = 0; i < n; i++) {
        end += X[i];
    }
    int ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (check(mid, X, k)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;   
    vector<int> X(n);
        for (int &i : X) {
            cin >> X[i];
        }

    cout << splitArray(X, k);
}