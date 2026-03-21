// Problem Link : https://codeforces.com/contest/702/problem/C
// My Submission : https://codeforces.com/contest/702/submission/367545723
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n , m;
    cin >> n >> m;
    vector <int> a(n) , b(m);
    for (auto & c : a) {
         cin >> c;
    }
    for (auto & c : b) {
         cin >> c;
    }
    sort(b.begin() , b.end());  
    int ans = 0;
    int s = 0 , e = 1e18;
    while (s <= e) {      
        int mid = (s + e) / 2;
	      int cnt = 0;
	      for (int i = 0; i < n; i++) {   
	          int l = 0 , r = m - 1;
	          bool found = false;
	          while (l <= r) {
	             int k = (l + r) / 2;
		           int d = b[k] - a[i];
		           if (abs (d) <= mid) {
		               found = true;
		               break;
		           } else if(d < mid) {
		              l = k + 1;
		           } else {
		              r = k - 1;
		            }  
	           }
	         if (found) {
	           cnt++;
	         }
	      }
	     if (cnt == n) {
	        ans = mid;
	        e = mid - 1;
	     } else {
	        s = mid + 1;
	     }
    }
    cout << ans << "\n";
    return 0;
}
