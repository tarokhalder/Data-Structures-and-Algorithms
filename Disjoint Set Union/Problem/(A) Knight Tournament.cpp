// Problem Link :https://codeforces.com/problemset/problem/356/A
// My Submission : https://codeforces.com/contest/356/submission/368448365
#include <bits/stdc++.h>

using namespace std;

class dsu {
     public:
       vector <int> Parent;
       dsu(int n) {
          Parent.resize(n + 1);
	        iota(Parent.begin() , Parent.end() , 0);
       }

       int find(int x) {
           if (Parent[x] == x) {
	             return x;
	         }
	         return Parent[x] = find(Parent[x]);
       }
       void unite(int x , int y) {
            x = find(x);
	          y = find(y);
	          if (x != y) {
	            if (x < y) {
	              swap(x , y);
	            }
	            Parent[y] = x;
	    
	         }
       }
};

int main() {
    int n , q;
    cin >> n >> q;
    vector <int> Ans(n + 1 , 0);
    dsu d(n);
    while (q--) {
        int l , r , w;
	      cin >> l >> r >> w;
	      for (int i = l; i < w;) {
	        int x = d.find(i);
	        if (Ans[x] == 0 && x < w) {
	           Ans[x] = w;
	        }
	        i = x + 1;
	        d.unite(x , w);
	     }
	    for (int i = w + 1; i <= r;) {
	       int x = d.find(i);
	        if (Ans[x] == 0) {
	           Ans[x] = w;
	        }
	        i = x + 1;
	        d.unite(x , r);
	    }
	
    }
    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " \n"[i == n];
    }
    return 0;
}
