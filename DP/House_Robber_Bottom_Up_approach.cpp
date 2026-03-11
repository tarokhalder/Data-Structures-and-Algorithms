#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    vector <int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = a[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] , dp[i - 2] + a[i - 1]);
    }
    cout << dp[n] << "\n";
    return 0;
}
