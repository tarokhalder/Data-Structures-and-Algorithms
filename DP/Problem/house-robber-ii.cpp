// Problem Link : https://leetcode.com/problems/house-robber-ii/description/
// My submission : https://leetcode.com/problems/house-robber/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int rob(vector<int>& a) {
         if (a.size() == 1) {
            return a[0];
         }
         if (a.size() == 2) {
            return max(a[0] , a[1]);
         }
         int n = int(a.size());
         int ans = INT_MIN;
         for (int i = 0; i < n; i++) {
            int L = 0;
            int R = a[i];
            for (int j = i + 1; j < i + n - 1; j++) {
                int M = max(R , L + a[j % n]);
                L = R;
                R = M;
            }
            ans = max(ans , R);
         }

         return ans;
    }
};
