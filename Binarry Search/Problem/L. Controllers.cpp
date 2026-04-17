// Problem Link : https://codeforces.com/contest/1776/problem/L
// My Submission : https://codeforces.com/contest/1776/submission/371453913
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n;
    cin >> n;
    string a;
    cin >> a;
    int P = count(a.begin() , a.end() , '+');
    int N = int(a.size()) - P;
    int q;
    cin >> q;
    while (q--) {
        int x , y;
	cin >> x >> y;
	if (x < y) {
	    swap(x , y);
	}
	if (P == 0 || N == 0) {
	    cout << "NO" << "\n";
	} else {
	    int s = 0 , e = P;
	    bool ok = false;
	    while (s <= e) {
	       int m = (s + e) / 2;
	       int sum = (x * m) + (y * (P - m));
	       int u = 0 , v = N;
	       int V = 0;
	       while (u <= v) {
	          int mid = (u + v) / 2;
		  V = (x * mid)  +((N  - mid) * y);
		  if (sum == V) {
		     break;
		  }
		  if (sum < V) {
		     v = mid - 1;
		  } else {
		     u = mid + 1;
		  }
	       }
	       if (sum == V) {
	          ok = true;
		  break;
	       }
	       if (sum < V) {
	          s = m + 1;
	       } else {
		  e = m - 1;     
	       }

	    }
	    cout << (ok ? "YES" : "NO") << "\n";
	}
    }
    return 0;

}
