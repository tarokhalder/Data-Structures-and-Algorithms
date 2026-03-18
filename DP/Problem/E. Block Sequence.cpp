// Problem Link : https://codeforces.com/contest/1881/problem/E
// My submisiion : https://codeforces.com/contest/1881/submission/367213551
#include <bits/stdc++.h>

using namespace std;

int find(vector <int> & a , int i , int n , vector <int> & dp) {
    if (i == n + 1)  {
       return 0;
    }
    if (i > n){ 
       return INT_MAX;
    }
    if (dp[i] != -1) {
       return dp[i];
    }
    int P = find(a , a[i] + i + 1 , n , dp);
    int N = 1 + find(a , i + 1 , n , dp);
    return dp[i] =  min(P , N);
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
	      cin >> n;
	      vector <int> a(n);
	      for (auto & c: a) {
	        cin >> c;
	     }
	     vector <int> dp(n , -1);
	     cout << find(a , 0 , n - 1 , dp) << "\n";
    }
    return 0;

}
