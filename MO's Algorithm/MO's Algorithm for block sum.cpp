#include <bits/stdc++.h>

using namespace std;

struct Q {
    int l , r , block , id;
};

int main() {
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
	A[i].block = A[i].l / m;
	A[i].id = i;
    }
    sort(A.begin() , A.end() ,[&](Q a , Q b) {
        if (a.block == b.block) {
	   return a.l < b.l;
	}
        return a.block < b.block;	
    });
    int x = 0 , y = 0;
    int sum = 0;
    vector <int> Ans(q);
    for (int i = 0; i < q; i++) {
         while (y <= A[i].r) {
	     sum += a[y];
	     y++;
	 }
	 while (y > A[i].r + 1) {
	     y--;
	     sum -= a[y];
	 }
	 while (x < A[i].l) {
	     sum -= a[x];
	     x++;
	 }
	 while (x > A[i].l) {
	    x--;
	    sum += a[x];   
	 }
	 Ans[A[i].id] = sum;
    }
    for (int i = 0; i < q; i++) {
        cout << Ans[i] << " \n"[i == n - 1]; 
    }
    return 0;
}
