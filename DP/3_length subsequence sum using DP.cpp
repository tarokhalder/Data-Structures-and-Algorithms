#include <bits/stdc++.h>

using namespace std;

int find(vector <int> & a , int n , int cnt , vector <vector<int>> & dp) {
    if (dp[cnt][n] != -1) {
        return dp[cnt][n];
    }
    if (cnt > 0 && n >= 0) {
       int P = a[n] + find(a , n - 1 , cnt - 1 , dp);
       int N = find(a , n - 1 , cnt , dp);
       return dp[cnt][n] = max(P , N);
    } else {
       return 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    vector <vector <int>> dp(4 , vector <int> (n , -1));
    cout << find(a , n - 1 , 3 , dp) << "\n";
    return 0;
}
