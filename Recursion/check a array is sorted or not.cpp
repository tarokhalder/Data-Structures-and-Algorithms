#include <bits/stdc++.h>

using namespace std;

bool issorted(vector <int> & a , int i , int n) {
     if (i == n - 1) {
        return true;
     }
     if (a[i] <= a[i + 1] && issorted(a , i + 1 , n)) {
         return true;
     }
     return false;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
         cin >> c;
    }

    cout << issorted(a , 0 , n) << "\n";
    return 0;
}
