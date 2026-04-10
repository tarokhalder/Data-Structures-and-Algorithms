// Problem Link : https://codeforces.com/problemset/problem/415/B
// My submission : https://codeforces.com/contest/415/submission/370511761
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    int n , x , y;
    cin >> n >> x >> y;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    vector <int> Ans(n);
    for (int i = 0; i < n; i++) {
        int L = (a[i] * x) / y;
	int A = -1 , s = 0 , e = a[i];
	while (s <= e) {
	    int mid = (s + e) / 2;
	    int d = (mid * x) / y;
	    if (d < L) {
	       s = mid + 1;
	    } else {
	        A = mid;
		e = mid - 1;
	    }
	}
	Ans[i] = a[i] - A;
    }
    for (int i = 0; i < n; i++) {
         cout << Ans[i] << " \n"[i == n - 1];
    }
    return 0;
}
