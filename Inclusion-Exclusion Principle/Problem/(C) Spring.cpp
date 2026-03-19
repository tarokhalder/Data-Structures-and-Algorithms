// Problem Link : https://codeforces.com/contest/2204/problem/C
// My Submission : https://codeforces.com/contest/2204/submission/366990497
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int Lcm(int a , int b) {
    return (a * b) / __gcd(a , b);
}
int Lcm(int a , int b , int c) {
    vector <int> A{a , b , c};
    int ans = A[0];
    for (int i = 1; i < 3; i++) {
         ans = (ans * A[i]) / (__gcd(A[i] , ans));
    }
    return ans;
}

int32_t main() {
    int tt;
    cin >> tt;
    while (tt--) {
         int a , b , c , m;
	       cin >> a >> b >> c >> m;
	       int A = (m / a) * 6 , B = (m / b) * 6 , C = (m / c) * 6;
	       int L = Lcm(a , b);
	       A -= (m / L) * 3;
	       B -= (m / L) * 3;
	       L = Lcm(b , c);
	       B -= (m / L) * 3;
	       C -= (m / L) * 3;
	       L = Lcm(a , c);
	       A -= (m / L) * 3;
	       C -= (m / L) * 3;
	       L = Lcm(a , b , c);
	       A += (m / L) * 2;
	       B += (m / L) * 2;
	       C += (m / L) * 2;
	       cout << A << " " << B << " "<< C << "\n";
    }
    return 0;
}
