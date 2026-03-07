import java.util.Scanner;

fun main(args : Array <String>) {
    var readline = Scanner(System.`in`)
    var n : Long = readline.nextLong()
    var k : Long = readline.nextLong()
    var s : Long = 1
    var e : Long = n
    var A : Long = 0
    while (s <= e) {
         var mid : Long = (s + e) /2
	 var total : Long = (mid * (mid + 1)) / 2
	 if (total - (n - mid) == k) {
             A = n - mid
	     break
	 } else if (total - (n - mid) > k) {
             e = mid - 1
	 } else {
             s = mid + 1
	 }
    }
    print(A)
}
