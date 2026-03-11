// Problem Link : https://codeforces.com/contest/180/problem/C
// My submission : https://codeforces.com/contest/180/submission/366216839

#include <bits/stdc++.h>

using namespace std;

struct T {
   int lower , upper;
   T operator -(T a) {
      return {lower - a.lower , upper - a.upper};
   }
};

int main() {
    string a;
    cin >> a;
    int n = int(a.size());
    int L = 0 , R = 0;
    vector <T> P(n + 1);
    P[0] = {0 , 0};
    for (int i = 0; i < int(a.size()); i++) {
        if (isupper(a[i])) {
	   R++;
	} else {
	   L++;
	}
	P[i + 1] = {L , R};
    }
    vector <int> dp(n , INT_MAX);
    dp[0] = min(P[n].lower , P[n].upper);
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i] , dp[i - 1]);
	T U = P[n] - P[i];
	dp[i] = min(dp[i] , P[i].upper + U.upper);
	dp[i] = min(dp[i] , P[i].lower + U.lower);
	dp[i] = min(dp[i] , P[i].lower + U.upper);
    }
    cout << dp[n - 1] << "\n";
    return 0;

}
