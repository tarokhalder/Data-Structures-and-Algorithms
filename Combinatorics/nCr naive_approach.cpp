#include <bits/stdc++.h>

using namespace std;

int nCr(int n , int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; i++) {
        res *= i;
    }
    for (int i = 2; i <= k; i++) {
        res /= i;
    }
    return res;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n , r;
	      cin >> n >> r;
	      cout << nCr(n , r) << "\n";
    }
    return 0;
}
