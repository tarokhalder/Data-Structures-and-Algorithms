//Problem Link : https://codeforces.com/contest/877/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    string a;
    cin >> a;
    int n = int(a.size());
    int dp[3][n];
    memset(dp , 0 , sizeof(dp));
    map <char , int> M;
    for (int i = 0; i < n; i++) {
         int L = M.count('a') ? M['a'] : -1;
	 int R = M.count('b') ? M['b'] : -1;
	 dp[0][i] = 1;
	 if (a[i] == 'a') {
	    if (L != -1) {
	       dp[0][i] = dp[0][L] + 1;
	    }
	    if (L != -1 && dp[1][L] != 0) {
	       dp[1][i] = dp[1][L] + 1;
	    }
	    if (R != -1 && dp[0][R] != -1) {
	       dp[1][i] = max(dp[1][i] , dp[0][R] + 1);
	    }
	    if (L != -1 && dp[2][L] != 0) {
	       dp[2][i] = dp[2][L] + 1;
	    }
	    if (R != -1 && dp[1][R] != 0) {
	       dp[2][i] = max(dp[2][i] , dp[1][R] + 1);
	    }

	 } else {
	   if (R != -1) {
	      dp[0][i] = dp[0][R] + 1;
	   }
	   if (R != -1 && dp[1][R] != 0) {
	      dp[1][i] = dp[1][R] + 1;
	   }
	   if (L != -1 && dp[0][L] != 0) {
	      dp[1][i] = max(dp[1][i] , dp[0][L] + 1);
	   }
	 }
	 M[a[i]] = i;

    }
    int ans = INT_MIN;
    if (M.count('a')) {
        ans = max({dp[0][M['a']] , dp[1][M['a']] , dp[2][M['a']]});
    }
    if (M.count('b')) {
        ans = max({ans , dp[0][M['b']] , dp[1][M['b']] , dp[2][M['b']]});
    }
    cout << ans << "\n";
    return 0;
}
