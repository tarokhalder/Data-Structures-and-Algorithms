#include <bits/stdc++.h>

using namespace std;

int power(int a , int p) {
    if (p == 0) {
        return 1;
    }
    return a * power(a , p - 1);
}
int main() {
    int a , p;
    cin >> a >> p;
    cout << power(a , p) << "\n";
    return 0;
}
