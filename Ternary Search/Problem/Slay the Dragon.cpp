//Problem Link : https://codeforces.com/contest/1574/problem/C
// My submission : https://codeforces.com/contest/1574/submission/364811991
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int max(int x , int y) {
    return x > y ? x : y;
}

int fx (vector <int> & a , int mid , int sum , int x , int y) {
    int ans = 0;
    ans += max(0LL , x - a[mid]);
    ans += max(0LL , y - (sum - a[mid]));
    return ans;
}

int32_t main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    sort(a.begin() , a.end());
    int sum = accumulate(a.begin() , a.end() , 0LL);
    int q;
    cin >> q;
    while (q--){ 
        int x , y;
	      cin >> x >> y;
        int s = 0 , e = n - 1;
	      int ans = LLONG_MAX;
	      while (s <= e) {
	          int mid1 = s + (e - s) / 3;
	          int mid2 = e - (e - s) / 3;
	          int M = fx(a , mid1 , sum , x , y);
	          int N = fx(a , mid2 , sum , x , y);
	          if (M < N) {
	            ans = min(ans , M) ;
	            e = mid2 - 1;
	          } else {
	            ans = min(ans , N);
	            s = mid1 + 1;
	         }
	      }
	      cout << ans << "\n";
    }
    return 0;
}
