// Problem Link : https://codeforces.com/contest/455/problem/A
// Problem Solution : https://codeforces.com/contest/455/submission/367204120
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
         cin >> c;
    }
    map <int , int> M;
    for (int x : a) {
        M[x]++;
    }
    vector <int> A , B;
    A.push_back(0);
    B.push_back(0);
    for (auto [x , y] : M) {
        A.push_back(x);
	      B.push_back(x * y);
    }
    assert(A.size() == B.size());
    n = int(A.size());
    vector <vector <int>> dp(2 , vector<int> (n , INT_MIN));
    dp[0][0] = dp[1][0] = dp[1][1] = 0;  
    dp[0][1] = B[1];
    for (int i = 2; i < n; i++) {
        if (A[i] == A[i - 1] + 1) {
	         dp[0][i] = max(dp[0][i] , max(dp[0][i - 2] , dp[1][i - 2]) + B[i]);
      	} else {
	         dp[0][i] = max(dp[0][i] , max(dp[1][i - 1] , dp[0][i - 1]) + B[i]);
      	}
	      dp[1][i] = max(dp[1][i] , max(dp[1][i - 1] , dp[0][i - 1]));
    }
    cout << max(dp[0][n - 1] , dp[1][n - 1]) << "\n";
    return 0;
}
