// Problem Link : https://codeforces.com/contest/1462/problem/E1
// My submission : https://codeforces.com/contest/1462/submission/367876191
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int find(int n) {
    return (n * (n - 1)) / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int tt;
    cin >> tt;
    while (tt--) {
         int n;
	 cin >> n;
	 vector <int> a(n);
	 for (auto & c : a) {
	     cin >> c;
	 }
	 sort(a.begin() , a.end());
	 if (n <= 2) {
	    cout << 0 << "\n";
	 } else {
	    int sum = 0;
	    for (int i = 0; i < n - 2; i++) {
	         int x = a[i] + 2;
		       int L = -1;
		       int s = i + 1 , e = n - 1;
		      while (s <= e) {
		         int mid = (s + e) / 2;
		         if (a[mid] <= x) {
		            L = mid;
		    	      s = mid + 1;
		        } else {
		           e = mid - 1;
		         }

		     }
		     if (L != -1) {
		       sum += find(L - i);
		     }
	    }
	    cout << sum << "\n";
	 }
    }
    return 0;
}
