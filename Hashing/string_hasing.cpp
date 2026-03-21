#include <bits/stdc++.h>

using namespace std;

int gethash(string a) {
    int ans = 0;
    int prime = 3;
    int power = 1;
    for (int i = 0; i < int(a.size()); i++) {
         ans = ans + (a[i] * power);
	       power *= prime;
    }
    return ans;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string a;
	      cin >> a;
	      cout << gethash(a) << "\n";
    }
    return 0;
}
