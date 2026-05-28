//Problem Link : https://codeforces.com/contest/577/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n , k;
    cin >> n >> k;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    if (n > k) {
      cout << "Yes" << "\n";
    } else {
       unordered_set <int> S;
       S.insert(a[0] % k);
       for (int i = 1; i < n; i++) {
           unordered_set <int> L;
	         L.insert(a[i] % k);
	         for (int x : S) {
	             L.insert((x + a[i]) % k);
	         }
	         for (int x : L) {
	         S.insert(x);
	      }
       }
       if (S.count(0)) {
          cout << "YES" << "\n";
       } else {
          cout << "NO" << "\n";
       }
    }
    return 0;
}
