// Problem Link : https://codeforces.com/problemset/problem/1817/A
// My submisiion : https://codeforces.com/contest/1817/submission/367872701

#include <bits/stdc++.h>

using namespace std;

struct T {
    int x , y;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n , qq;
    cin >> n >> qq;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    vector <T> A;
    int L = 0 , i = 0 , d = a[0];
    while (i < n) {
        if (a[i] > d) {
	  A.push_back({L , i - 1});
	  L = i;
	}
	d = a[i];
	i++;
    }
    A.push_back({L , n - 1});
  
    auto find = [&](int x )-> int {
          int s = 0 , e = int(A.size() - 1);
	  while (s <= e) {
	      int mid = (s + e) /2;
	      if (x < A[mid].x) {
	          e = mid - 1;
	      } else if (x > A[mid].y) {
	          s = mid + 1;
	      } else {
	         return mid;
	      }
	  }
	  return -1;
    };

    vector <int> P(int(A.size()));
    P[0] = min(2 , A[0].y - A[0].x + 1);
    for (int i = 1; i < int(A.size()); i++) {
         P[i] += P[i - 1] + min(A[i].y - A[i].x + 1 , 2);
    }

    while (qq--) {
        int x , y;
	cin >> x >> y;
	x-- , y--;
	int L = find(x) , R = find(y);
	if (L == R) {
	    cout << min(y - x + 1 , 2) << "\n";
	} else {
	    int ans = P[R] - P[L] - min(A[R].y - A[R].x + 1 , 2);
	    ans += min(A[L].y - x + 1 , 2);
	    ans += min(y - A[R].x + 1 , 2);
	    cout << ans << "\n";
	}
	
    }
    return 0;

}
