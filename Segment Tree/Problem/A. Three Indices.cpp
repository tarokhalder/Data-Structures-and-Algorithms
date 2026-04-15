// Problem Link : https://codeforces.com/problemset/problem/1380/A
// My submission : https://codeforces.com/contest/1380/submission/371273274
#include <bits/stdc++.h>

using namespace std;

class ST {
    public:
      vector <int> S;
      int n;
      ST() {
      
      }
      ST(int n) {
	 this-> n = n;     
         S.resize(4 * n , INT_MAX);
      }
      void build(int start , int end , int node , vector <int> & a) {
           if (start == end) {
	      S[node] = start;
	      return;
	   }
	   int mid = (start + end) / 2;
	   build(start , mid , 2 * node + 1 , a);
	   build(mid + 1 , end , 2 * node + 2 , a);
	   if (a[S[2 * node + 1]] > a[S[2 * node + 2]]) {
	       S[node] = S[2 * node + 2];
	   } else {
	       S[node] = S[2 * node + 1];
	   }
      }
      int query(int start , int end , int node , int l , int r , vector <int> & a) {
          if (end < l || start > r) {
	     return INT_MAX;
	  }
	  if (start >= l && end <= r) {
	     return S[node];
	  }
	  int mid = (start + end) / 2;
	  int q1 = query(start , mid , 2 * node + 1 , l , r , a);
	  int q2 = query(mid + 1 , end , 2 * node + 2 , l , r , a);
	  if (q1 != INT_MAX && q2 != INT_MAX) {
	     if (a[q1] < a[q2]) {
	        return q1;
	     }
	     return q2;
	  }
	  if (q1 != INT_MAX) {
	     return q1;
	  }
	  return q2;
      }
      void build(vector <int> & a) {
           build(0 , n - 1 , 0 , a);
      }
      int query(int l , int r , vector <int> & a) {
          return query(0 , n - 1 , 0 , l , r , a);
      }
};

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
       int n;
       cin >> n;
       vector <int> a(n);
       for (auto & c : a) {
            cin >> c;
       }
       ST tree(n);
       tree.build(a);
       int x = -1 , y = -1 , z = -1;
       for (int i = 1; i < n - 1; i++) {
           int u = tree.query(0 , i - 1 , a);
	   int v = tree.query(i + 1 , n - 1 , a);
	   if (a[u] < a[i] && a[i] > a[v]) {
	       x = u , y = i , z = v;
	   }
       }
       if (x == -1) {
          cout << "NO" << "\n";
       } else {
           cout << "YES" << "\n";
	   cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
       }
    }
    return 0;
}
