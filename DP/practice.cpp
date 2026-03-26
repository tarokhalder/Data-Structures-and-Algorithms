#include <bits/stdc++.h>

using namespace std;

int find(vector <int> & a , vector <int> & b , vector <vector <int>> & dp , int n , int N , int cnt) {
    if (n < 0 && cnt > 0) {
       return 1e5;
    }
    if (cnt == 0) {
       return 0;
    }
    int Take = INT_MAX;
    if (a[n] < N) {
        Take = b[n] + find(a , b , dp , n - 1 , a[n] , cnt - 1);
    }
    int NotTake = find(a , b , dp , n - 1 , N , cnt);
    return dp[n][cnt] = min(Take , NotTake);
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n) , b(n);
    for (auto & c : a) {
         cin >> c;
    }
    for (auto & c : b) {
         cin >> c;
    }
    vector <vector <int>> dp(n , vector <int> (4 , -1));

    cout << find(a , b , dp , n - 1 , INT_MAX , 3) << "\n";
    return 0;

}
