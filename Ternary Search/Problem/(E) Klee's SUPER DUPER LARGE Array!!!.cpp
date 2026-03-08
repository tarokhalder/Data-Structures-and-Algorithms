// Problem Link : https://codeforces.com/contest/2009/problem/E
// My accepted submission: https://codeforces.com/contest/2009/submission/364946544
#include <bits/stdc++.h>

using namespace std;


#define int int64_t

int sum(int l  , int r) {
    int L = (l * (l - 1)) / 2;
    int R = (r * (r + 1)) / 2;
    return R - L;
}

int fx(int s , int m , int e) {
     return abs(sum(s , m) - sum(m + 1 , e));
}

int32_t main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n , k;
	     cin >> n >> k;
	     int s = k , e = n + k - 1;
	     int ans = LLONG_MAX;
	     while (s <= e) {
	        int mid1 = s + (e - s) / 3;
	        int mid2 = e - (e - s) / 3;
	        int L = fx(k , mid1 , n + k - 1);
	        int R = fx(k , mid2 , n + k - 1);
	        if (L < R) {
	          ans = min(ans , L);
	          e = mid2 - 1;
	        } else {
	          ans = min(ans , R);
	          s = mid1 + 1;
	        }
	    }
	    cout << ans << "\n";
    }
    return 0;
}
