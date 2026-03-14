// Problem Link : https://codeforces.com/contest/771/problem/A
// My submission : https://codeforces.com/contest/771/submission/366598401
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

class dsu {
    public:
      vector <int> Parent , Rank , Edge;
      dsu(int n) {
         Parent.resize(n + 1);
	       Rank.resize(n + 1 , 1);
	       Edge.resize(n + 1 , 0);
	       for (int i = 0; i <= n; i++) {
	          Parent[i] = i;
	       }
      }
      int find(int x){ 
           if (Parent[x] == x) {
	      return x;
	   }
	   return Parent[x] = find(Parent[x]);
      }
      void unite(int x , int y) {
           x = find(x);
	         y = find(y);
	         if (x != y) {
	           Parent[x] = y;
	           Rank[y] += Rank[x];
	           Edge[y] += 1 + Edge[x];
	         } else {
	           Edge[x]++;
	      }
    }
};

int find(int x) {
    return (x * (x - 1)) / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n , m;
    cin >> n >> m;
    dsu d(n);
    while (m--) {
       int x , y;
       cin >> x >> y;
       d.unite(x , y);

    }
    unordered_set <int> S;
    for (int i = 1; i <= n; i++) {
        S.insert(d.find(i));
    }
    bool ok = true;
    for (auto x : S) {
        if (d.Edge[x] < find(d.Rank[x])) {
	         ok = false;		
	      } 
    }
    cout << (ok ? "YES" : "NO") << "\n";
    return 0;
}
