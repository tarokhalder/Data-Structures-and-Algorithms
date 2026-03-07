// Problem Link : https://codeforces.com/contest/1263/problem/D
// My submission : https://codeforces.com/contest/1263/submission/365676855
#include <bits/stdc++.h>

using namespace std;

class dsu {
     public:
       vector <int> parent;
       dsu(int n) {
          parent.resize(n + 1);
	        iota(parent.begin() , parent.end() , 0);
       }
       int find(int x) {
           if (x == parent[x]) {
	           return x;
	          }
	          return parent[x] = find(parent[x]);
       }
       void unite(int x , int y) {
            x = find(x);
	          y = find(y);
	          if (x != y) {
	            parent[x] = y;
	          }
       }
};
int main() {
    int n;
    cin >> n;
    dsu d(26);
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
	     for (int j = 1; j < int(a[i].size()); j++) {
	        int L = a[i][j - 1] - 'a';
	        int R = a[i][j] - 'a';
	        d.unite(L , R);
	     }
    }  
    unordered_set <int> S;
    for (int i = 0; i < n; i++) {
        for (char c: a[i]) {
	         int L = c - 'a';
	         S.insert(d.find(L));
	      }
    }
    cout << int(S.size()) << "\n";
    return 0;
}
