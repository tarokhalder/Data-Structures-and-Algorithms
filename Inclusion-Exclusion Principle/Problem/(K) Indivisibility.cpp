// Problem Link : https://codeforces.com/contest/630/problem/K
// My Submission : https://codeforces.com/contest/630/submission/367388468
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int find(int x , int n) {
    return n / x;
}

int32_t main() {
    int n;
    cin >> n;
    vector <int> A = {2 , 3 , 5 , 7};
    int ans = 0;
    for (int i = 1; i < (1 << 4); i++) {
        int N = 1;
	      for (int j = 0; j < 4; j++) {
	         if (i & (1 << j)) {
	            N *= A[j];
	        }
	      }
	     if (__builtin_popcount(i) & 1) {
	        ans += find(N , n);
      	} else {
	       ans -= find(N , n);
     	 } 
    }
    cout << n - ans << "\n";
    return 0;
}
