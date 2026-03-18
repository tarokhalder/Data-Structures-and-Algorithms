#include <bits/stdc++.h>

using namespace std;

int House_Robber(vector <int> & a , int n , vector <int> & dp) {
    if (n < 0) {
      return 0;
    }
    if (n == 0) {
       return a[0];
    }
    if (dp[n] != -1){ 
       return dp[n];
    }
    int pick = a[n] + find(a , n - 2 , dp);
    int notpick = find(a , n - 1 , dp);
    return dp[n] = max(pick , notpick);
}


int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    vector <int> dp(n , -1);
    cout << find(a , n - 1 , dp) << "\n";
    return 0;
}
