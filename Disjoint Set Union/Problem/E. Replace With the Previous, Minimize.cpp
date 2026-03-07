//Problem Link : https://codeforces.com/contest/1675/problem/E
//My solution : https://codeforces.com/contest/1675/submission/364293774
#include <bits/stdc++.h>

using namespace std;

class dsu {
    public:
     vector <int> parent;
     dsu(int n) {
        parent.resize(n , 0);
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
	        if (y > x) {
	         swap(x , y);
	        }
	        if (x != y) {
	         parent[x] = y;
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
       int n , k;
       cin >> n >> k;
       string a;
       cin >> a;
       dsu d(26);
       for (int i = 0; i < int(a.size()); i++) {
           int idx = a[i] - 'a';
	         int s = d.find(idx);
	         while (d.find(s) != 0 && k > 0) {
	            k--;
	            d.unite(s , s - 1);
	            s--;
	        }

       }
       for (int i = 0; i < n; i++) {
           int s = a[i] - 'a';
	         a[i] = char(d.find(s) + 'a');
       }
       cout << a << "\n";
    }
    return 0;
}
