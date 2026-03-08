#include <bits/stdc++.h>

using namespace std;

int fx(int x) {
   return -(x * x) + 4 * x;
}

int main() {
     double l = -100 , r = 100;
     while (r - l > 0.0001) {
         double mid1 = l + (r - l) / 3;
	       double mid2 = r - (r - l) / 3;
	       if (fx(mid1) < fx(mid2)){
	          l = mid1;
	      } else {
	         r = mid2;
	      } 

    }
    cout << l << " " << r << "\n";
}
