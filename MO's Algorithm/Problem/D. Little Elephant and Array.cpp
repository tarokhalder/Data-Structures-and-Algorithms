//Problem Link :https://codeforces.com/contest/221/problem/D
//My submission : https://codeforces.com/contest/221/submission/366064406

#include <bits/stdc++.h>

using namespace std;

struct Q {
    int l , r , block , id;
};

unordered_map <int , int> M;

int L = 0;

void add(int x) {
     if(M.count(x) && M[x] == x) {
         L--;
     }
     M[x]++;
     if (M[x] == x){ 
       L++;
     }
}

void remove(int x) {
     if (M.count(x) && M[x] == x + 1) {
         L++;
     }
     if (M.count(x) && M[x] == x) {
        L--;
     }
     M[x]--;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n , q;
    cin >> n >> q;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    vector <Q> A(q);
    int m = sqrt(n) + 1;
    for (int i = 0; i < q; i++) {
        cin >> A[i].l >> A[i].r;
	      A[i].l-- , A[i].r--;
	      A[i].block = A[i].l / m;
	      A[i].id = i;
    }
    sort(A.begin() , A.end() ,[&](Q a , Q b) {
        if (a.block == b.block) {
	          return a.r < b.r;
	      }
        return a.block < b.block;	
    });
    int x = 0 , y = 0;
    int sum = 0;
    vector <int> Ans(q);
    for (int i = 0; i < q; i++) {
         while (y <= A[i].r) {
	         add(a[y]);
	         y++;
	       }
	       while (y > A[i].r + 1) {
	           y--;
	           remove(a[y]);
	        }
	       while (x < A[i].l) {
	          remove(a[x]);
	          x++;
	       }
	       while (x > A[i].l) {
	         x--;
	         add(a[x]);   
	       }
	       Ans[A[i].id] = L;
    }
    for (int i = 0; i < q; i++) {
        cout << Ans[i] << "\n"; 
    }
    return 0;
}
