#include <bits/stdc++.h>

using namespace std; 

double radian_to_degree(double angle) {
     double A = (angle * 180) / M_PI;
     return A;
}

int main() {
    int x , y;
    cin >> x >> y;
    int X = abs(x);
    int Y = abs(y);
    double r = sqrt(x * x + y * y);
    double angle = atan(double(Y / X)); // in radian
    double L = radian_to_degree(angle);
    if (x < 0 && y < 0) {
       L = 180 + L;
    } else if (x < 0 && y > 0) {   
        L = 180 - L;
    } else if (x > 0 && y < 0) {
        L = 360 - L;
    }
    cout << r << " " << L << "\n";
    return 0;
}
