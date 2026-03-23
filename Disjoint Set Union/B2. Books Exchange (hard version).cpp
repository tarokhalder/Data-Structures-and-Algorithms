// Problem Link : https://codeforces.com/contest/1249/problem/B2
// My submission : https://codeforces.com/contest/1249/submission/361846727
#include <bits/stdc++.h>

using namespace std;

class dsu{
    public:
      vector <int> Parent , Rank;
      dsu(int n) {
         Parent.resize(n + 1);
	 Rank.resize(n + 1 , 1);
	 for (int i = 0; i <= n; i++) {
	      Parent[i] = i;
	 }
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
	      Parent[y] = x;
	      Rank[x] += Rank[y];
	   }
      }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	    a[i]--;
	}
	dsu d(n);
	int vis[n];
	memset(vis , 0 , sizeof(vis));
	for (int i = 0; i < n; i++) {
	     int node = a[i];
	     int par = a[i];
	     while (vis[node] == 0) {
	        d.unite(node , par);
		      vis[node] = 1;
	   	    par = node;
		      node = a[node];
	     }
	}
	vector <int> Ans(n);
	for (int i = 0; i < n; i++) {
	    Ans[i] = d.Rank[d.find(i)];
	}
	for (int i = 0; i < n; i++) {
	    cout << Ans[i] << " \n"[i == n - 1];
	}
  }
    return 0;
}
