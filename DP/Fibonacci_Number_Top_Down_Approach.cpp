#include <bits/stdc++.h>

using namespace std;

int fib(int n , vector <int> & dp) {
    if ( n <= 1) {
       return n;   // base case 
    }
    if (dp[n] != -1) {
       return dp[n];
    }
    return dp[n] = fib(n - 1 , dp) + fib(n - 2 , dp); // recursive case
}
int main() {
    int n;
    cin >> n;
    vector <int> dp(n + 1 , -1);
    cout << fib(n , dp) << "\n";
}
