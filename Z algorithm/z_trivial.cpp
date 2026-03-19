#include <bits/stdc++.h>

using namespace std;

vector <int> z_trivial(string a) {
    int n = int(a.size());
    vector <int> z(n , 0);
    for (int i = 1; i < n; i++) {
        while (i + z[i] < n && a[z[i]] == a[z[i] + i]) {
	         z[i]++;
	       }  
    }
    return z;
}

int main() {
    string a;
    cin >> a;
    vector <int> S = z_trivial(a);
    for (int i = 0; i < int(S.size()); i++) {
        cout << S[i] << " \n"[i == S.size() - 1];
    }
    return 0;
}
