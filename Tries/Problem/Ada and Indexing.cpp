// Problem Link : https://www.spoj.com/problems/ADAINDEX/
// My submission : https://www.spoj.com/status/ADAINDEX,abcdef_z/
#include <bits/stdc++.h>

using namespace std;

class Node {
     public:
	int cnt;
	Node * children[26];
	Node() {
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
	 cur->children[c - 'a']->cnt += 1;
	 cur = cur->children[c - 'a'];
     }
}
int search (Node * root , string & a) {
    Node * cur = root;
    for (char c : a) {
        if (cur->children[c - 'a'] == nullptr) {
	   return 0;
	}
	cur = cur->children[c - 'a'];
    }
    return cur->cnt;
}

int main() {
    int n , q;
    cin >> n >> q;
    Node * root = new Node();
    while (n--) {
        string a;
	cin >> a;
	insert(root , a);
    }
    while (q--) {
        string a;
	cin >> a;
	cout << search(root , a) << "\n";
    }
    return 0;
}
