// Problem Link : https://codeforces.com/contest/1575/problem/J
// My submission : https://codeforces.com/contest/1575/submission/366905127
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
	       if (x == Parent[x]) {
	        return x;
	       }
	       return Parent[x] = find(Parent[x]);
	   }
	   void unite(int x , int y) {
	     x = find(x);
	     y = find(y);
	     if (x != y) {
	       if (y < x) {
	          swap(x , y);
	       }
	       Parent[x] = y;
	     }
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n , m , q;
    cin >> n >> m >> q;
    vector <int> a(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
	     int x;
	     cin >> x;
	     a[(i * m) + j] = x;
	}
    }
    int N = (n * m) + m + 1;
    dsu d(N);
    while (q--) {
        int x;
	      cin >> x;
	      x--;
	      x = d.find(x);
      	N = n * m;
	      while (x >= 0 && x < N) {
	         d.unite(x , x + m);
	         int s = a[x];
	         a[x] = 2;
	         if (s == 1) {
	           x++;
	         } else if(s == 2) {
	            x += m;
	         } else {
	           x--;
	         }
	         x = d.find(x);
	    
	      }
	      cout << (x % m) + 1 << " ";
    }
    return 0;
}
