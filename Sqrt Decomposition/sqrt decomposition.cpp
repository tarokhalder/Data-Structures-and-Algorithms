#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    int n , q;
    cin >> n >> q;
    vector <int> a(n);
    for (auto & c : a) {
         cin >> c; 
    }
    int m = sqrt(n) + 1;
    vector <int> b(m);
    for (int i = 0; i < n; i++) {
        b[i / m] += a[i];
    }
    while (q--) {
        int x , l , r;
	      cin >> x >> l >> r;
     	  if (x == 1) {
	         b[l / m] += (r - a[l]);
	         a[l] = r;
	      } else {
	        int ans = 0;
	         for (int i = l; i < r;) {
	           if (i % m == 0 && i + m - 1 <= r - 1) {
		            ans += b[i / m];
		            i += m;
		        } else {
		           ans += a[i];
		           i++;
		        }
	         }
	     cout << ans << "\n";
	  }
  }
    return 0;
}
