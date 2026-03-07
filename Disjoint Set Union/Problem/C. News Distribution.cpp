// Problem link : https://codeforces.com/contest/1167/problem/C
// My solution : https://codeforces.com/contest/1167/submission/365580482
#include <bits/stdc++.h>

using namespace std;

class dsu {
    public:
        vector <int> Parent , Rank;
      	dsu(int n) {
	         Parent.resize(n + 1);
	         Rank.resize(n + 1 , 1);
	         iota(Parent.begin() , Parent.end() , 0);
	      }
	     int find(int x) {
	        if (x == Parent[x]) {
	           return x;
	       }
	       return Parent[x] = find(Parent[x]);
	     }
	     void unite(int x , int y) {
	         x = find(x);
	         y = find(y);
	         if (x != y) {
	           if (Rank[x] > Rank[y]) {
		            swap(x , y);
		         }
		         Parent[x] = y;
		         Rank[y] += Rank[x];
	        }
     	}

};

int main() {
    int n , q;
    cin >> n >> q;
    dsu d(n);
    while (q--) {
        int N;
	      cin >> N;
	      vector <int> a(N);
      	for (auto & c : a) {
	        cin >> c;
	      }
      	for (int i = 1; i < N; i++) {
	          d.unite(a[i] , a[i - 1]);
      	}
    }
    vector <int> Ans(n);
    for (int i = 1; i <= n; i++) {
         int x = d.find(i);
	      Ans[i - 1] = d.Rank[x];
    }
    for (int i = 0; i < n; i++) {
         cout << Ans[i] << " \n"[i == n - 1];
    }
    return 0;
}
