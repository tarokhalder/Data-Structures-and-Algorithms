// Problem Link : https://codeforces.com/contest/760/problem/B
// Problem Submission : https://codeforces.com/contest/760/submission/371365477
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int find(int n) {
    return (n * (n + 1)) / 2;
}

int32_t main() {
    int n , m , k;
    cin >> n >> m >> k;
    m -= n;
    int s = 1 , e = m;
    int L = k - 1 , R = n - k;
    int Ans = 1;
    int u = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
	int sum = 2 * find(mid - 1);
	if (L < mid - 1) {
	    sum -= find(mid - L - 1);
	}
	if (R < mid - 1) {
	    sum -= find(mid - 1 - R);
	}
	if (sum <= m - mid) {
	    u = mid;
	    s = mid + 1;
	} else {
	    e = mid - 1;
	}
    }

    cout << Ans + u << "\n";
    return 0;
}
