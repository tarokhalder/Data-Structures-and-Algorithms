// Problem Link : https://codeforces.com/contest/977/problem/F
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
         cin >> c;
    }
    vector <int> dp(n , -1);
    unordered_map <int , pair <int , int>> M;
    int size = 0 , index = 0;
    for (int i = 0; i < n; i++) {
        if (M.count(a[i] - 1)) {
	  int sz = M[a[i] - 1].second + 1;
	  dp[i] = M[a[i] - 1].first;
	  if (sz > size) {
	     size = sz;
	     index = i;
	  }
	  M[a[i]] = {i , sz};
	} else {
	   if (size == 0) {
	       size = 1;
	       index = i;
	   }
	   M[a[i]] = {i , 1};
	}
    }
    vector <int> Ans;
    while (dp[index] != -1) {
        Ans.push_back(index + 1);
	index = dp[index];
    }
    Ans.push_back(index + 1);
    reverse(Ans.begin() , Ans.end());
    assert(Ans.size() == size);
    cout << size << "\n";
    for (int i = 0; i < size; i++) {
        cout << Ans[i] << " \n"[i == size - 1];
    }
    return 0;
}
