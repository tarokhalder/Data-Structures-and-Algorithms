// Problem Link : https://codeforces.com/contest/1208/problem/B
#include <bits/stdc++.h>

using namespace std;

bool find(vector <int> & a , int N , unordered_map <int ,int> M) {
     int n = int(a.size());
     int i = 0;
     while (i < N) {
         M[a[i]]--;
	 if (M[a[i]] == 0) {
	     M.erase(a[i]);
	 }
	 i++;
     }
     i = N;
     while (i < n) {
         if (M.size() == n - N) {
	    return true;
	 }
	 M[a[i]]--;
	 M[a[i - N]]++;
	 if (M[a[i]] == 0) {
	    M.erase(a[i]);
	 }
	 if (M.size() == n - N) {	 
	    return true;
	 }
	 i++;
     }
     return false;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto &  c : a) {
         cin >> c;
    }
    int s = 0 , e = n - 1;
    unordered_map <int , int> M;
    for (int x : a) {
        M[x]++;
    }
    int ans = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
	if (find(a , mid , M)) {
	    ans = mid;
	    e = mid - 1;
	} else {
	    s = mid + 1;
	}
    }

    cout << ans << "\n";
    return 0;
}
