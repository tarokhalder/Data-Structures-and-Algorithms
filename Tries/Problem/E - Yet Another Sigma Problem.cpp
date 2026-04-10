// Problem Link : https://atcoder.jp/contests/abc353/tasks/abc353_e
// My submission : https://atcoder.jp/contests/abc353/submissions/74807491
#include <bits/stdc++.h>

using namespace std;

#define int  int64_t

class Node {
      public:
        int cnt;
        Node * children[26];
        Node () {
	  cnt = 0;
	  for (int i = 0; i < 26; i++) {
	       children[i] = nullptr;
	  }
	}	 
};

void insert(Node * root , string & a) {
     Node * cur = root;
     for (char c : a) {
         if (cur->children[c - 'a'] == nullptr) {
	     Node * temp = new Node();
	     cur->children[c - 'a'] = temp;
	 }
	 cur = cur->children[c - 'a'];
	 cur->cnt += 1;
     }
}

int find(Node * root , string & a) {
    Node * cur = root;
    int sum = 0;
    for (char c : a) {
        cur = cur->children[c - 'a'];
	cur->cnt -= 1;
	sum += cur->cnt;
    }
    return sum;
}
int32_t main() {
    int n;
    cin >> n;
    vector <string> a(n);
    for (auto & c : a) {
         cin >> c;
    }
    Node * root = new Node();
    for (string c : a) {
         insert(root , c);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += find(root , a[i]);
    }
    cout << sum << "\n";
    return 0;
}
