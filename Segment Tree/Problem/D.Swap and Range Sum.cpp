// Problem Link : https://atcoder.jp/contests/abc442/tasks/abc442_d
// My submission : https://atcoder.jp/contests/abc442/submissions/73875821
#include <bits/stdc++.h>

using namespace std;

class ST {
    public:
      int n;
      vector <int> S;
      ST(int n) {
         this-> n = n;
	       S.resize(this->n * 4 , 0);
      }
      void build(int start , int end , int node , vector <int> & a) {
           if (start == end) {
	       S[node] = a[start];
	       return;
	   }
	   int mid = (start + end) / 2;
	   build(start , mid , 2 * node + 1 , a);
	   build(mid + 1 , end , 2 * node + 2 , a);
	   S[node] = S[2 * node + 1] + S[2 * node + 2];
      }
      int query(int start , int end , int node , int l , int r) {
          if (start > r || end < l) {
	     return 0;
	  }
	  if (start >= l && end <= r) {
	      return S[node];
	  }
	  int mid = (start + end) / 2;
	  int q1 = query(start , mid , 2 * node + 1 , l , r);
	  int q2 = query(mid + 1 , end , 2 * node + 2 , l , r);
	  return q1 + q2;
      }
      void update(int start , int end , int node , int i , int r) {
          if (start == end) {
	     S[node] = r;
	     return;
	  }
	  int mid = (start + end) / 2;
	  if (i <= mid) {
	     update(start , mid , 2 * node + 1 , i , r);
	  } else {
	     update(mid + 1 , end, 2 * node + 2 , i , r);
	  }
	  S[node] = S[2 * node + 1] + S[2 * node + 2];
      }
      int query(int l , int r) {
          return query(0 , n - 1 , 0 , l , r);
      }
      void update(int i , int r) {
           update(0 , n - 1 , 0 , i , r);
      }
      void build(vector <int> & a) {
           build(0 , n - 1 , 0 , a);
      }
};

int main() {
    int n , q;
    cin >> n >> q;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    ST tree(n);
    tree.build(a);
    while (q--) {
        int x;
	      cin >> x;
	      if (x == 1) {
	        int l;
	        cin >> l;
	        l--;
	        swap(a[l] , a[l + 1]);
	        tree.update(l , a[l]);
	        tree.update(l + 1 , a[l + 1]);
	     } else {
	        int l , r;
	        cin >> l >> r;
	        l-- , r--;
	        cout << tree.query(l , r) << "\n";
	    }
    }
    return 0;
}
