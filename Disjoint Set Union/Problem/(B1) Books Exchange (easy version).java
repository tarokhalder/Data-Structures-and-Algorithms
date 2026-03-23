// Problem Link : https://codeforces.com/contest/1249/problem/B1
import java.util.Scanner;
import java.util.Vector;

public class Main{
    public static int Find(int num , int a[] , int ans) {
           DSU d = new DSU(200);
	   while (d.find(num) != d.find(a[num - 1])){
		d.unite(num , a[num - 1]); 
	        ans += 1;
		num = a[num - 1];
	   }
	   return ans;
    }	
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
	int tt = in.nextInt();
	while (tt-->0) {
	    int n = in.nextInt();
	    int [] a = new int[n];
	    int [] b= new int[n];
	    for (int i = 0; i < n; i++) {
	        a[i] = in.nextInt();
	    }
	    for (int i = 0; i < n; i++) {
	        b[i] = Find(a[i] , a , 1);
	    }
	    for (int i = 0; i < n; i++) {
	        System.out.print(b[i] + " ");
	    }
	    System.out.println();
	}
    }
}

class DSU{
       Vector <Integer> Parent = new Vector<>();
       DSU(int n) {
          for (int i = 0; i < n + 1; i++) {
	      Parent.add(i);
	  }
       }
       int find(int n) {
           if (n == Parent.get(n)) {
	       return n;
	   }
	   return Parent.set(n , find(Parent.get(n)));
       }
       void unite(int x ,int y) {
            x = find(x);
	    y = find(y);
	    if (x != y) {
	       Parent.set(y , x);
	    }
       }
}
