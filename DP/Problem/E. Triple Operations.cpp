// Problem Link : https://codeforces.com/contest/1999/problem/E
// My submission : https://codeforces.com/contest/1999/submission/366764817
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    int tt;
    cin >> tt;
    vector <int> dp(N , 0);
    dp[1] = 1;
    int j = 1;
    while (j * 3 < N) {
       dp[j * 3] = dp[j] + 1;
       j *= 3;
    }
    int L = 0;
    for (int i = 0; i < N; i++) {
       if (dp[i] == 0) {
          dp[i] = L;
       } else {
          L = dp[i];
       }
    }
    for (int i = 1; i < N; i++) {
         dp[i] += dp[i - 1];
    }
    while (tt--) {
       int l  , r;
       cin >> l >> r;
       cout << dp[r] - dp[l - 1] + dp[l] - dp[l - 1] << "\n";
    }
    return 0;


}
