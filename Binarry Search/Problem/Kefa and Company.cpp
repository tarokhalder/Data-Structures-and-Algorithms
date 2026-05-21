//Problem Link : https://codeforces.com/problemset/problem/580/B

#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct T {
    int x , y;
    bool operator < (T a) {
        return x < a.x;
    }
};

int32_t main() {
    int n , d;
    cin >> n >> d;
    vector <T> a(n);
    for (auto & [x , y] : a) {
         cin >> x >> y;
    }
    sort(a.begin() , a.end());
    vector <int> P(n);
    P[0] = a[0].y;
    for (int i = 1; i < n; i++) {
         P[i] = P[i - 1] + a[i].y;
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int L = 0;
	int s = i , e = n - 1;
	while (s <= e) {
	   int mid = (s + e) / 2;
	   if (a[mid].x - a[i].x < d) {
	       L = mid;
	       s = mid + 1;
	   } else {
	       e = mid - 1;
	   }
	}
	if (i == 0) {
	    ans = max(ans , P[L]);
	} else {
	    ans = max(ans , P[L] - P[i - 1]);
	}
    }
    cout << ans << "\n";
    return 0;
}
