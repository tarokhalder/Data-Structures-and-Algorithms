//Problem Link :https://codeforces.com/problemset/problem/1301/B
// My submission :https://codeforces.com/contest/1301/submission/364950632
#include <bits/stdc++.h>

using namespace std;

int fx(vector <int> a , int x) {
    if (a[0] == -1) {
       a[0] = x;
    }
    int ans = INT_MIN;    
    for (int i = 1; i < int(a.size()); i++) {
        if (a[i] == -1) {
	   a[i] = x;
	}
	ans = max(ans , abs(a[i] - a[i - 1]));

    }
    return ans;
}

int main() {
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
	      int s = 0 , e = 1e9;
	      int L = 0 , R = 0;
	      while (s <= e) {
	          int mid1 = s + (e - s) / 3;
	          int mid2 = e - (e - s) / 3;
	          int l = fx(a , mid1) , r = fx(a ,mid2);
	          if (l < r) {
	             L = l;
	             R = mid1;
	             e = mid2 - 1;
	          } else {
	            L = r;
	            R = mid2;
	            s = mid1 + 1;
	          }
     	}
	     cout << L << " " << R << "\n";
    }
    return 0;
}
