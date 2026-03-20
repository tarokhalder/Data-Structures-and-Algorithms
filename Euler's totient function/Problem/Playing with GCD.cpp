// Problem Link : https://www.spoj.com/problems/NAJPWG/
// My Submission : https://www.spoj.com/status/NAJPWG,abcdef_z/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 6;

int main() {
    int tt;
    cin >> tt;
    vector <int> phi(N);
    for (int i = 1; i <= N; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
	         for (int j = i; j <= N; j += i) {
	           phi[j] -= phi[j] / i;
	         }
	      }
    }
    vector <int> Ans(N , 0);
    Ans[2] = 2 - phi[2];
    for (int i = 3; i <= N; i++) {
        Ans[i] += Ans[i - 1] + (i - phi[i]);
    }
    for (int j = 1; j <= tt; j++) {
        int n;
	      cin >> n;
	      cout <<"Case "<< j << ": "<< Ans[n] << "\n";
    }
    return 0;
} 
