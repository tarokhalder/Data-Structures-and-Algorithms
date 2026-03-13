#Problem Link : https://codeforces.com/contest/1215/problem/B
#Problem Submission : https://codeforces.com/contest/1215/submission/366483761
n = int(input())
a = list(map(int , input().split()))

for i in range (0 , len(a)):
    if a[i] > 0:
        a[i] = 1
    else :
        a[i] = -1

P = 0 
N = 0
for i in range(1 , len(a)):
    a[i] = a[i] * a[i - 1]

M = {
  1 : 1,
  0 : 0
}

for i in range(0 , len(a)):
    if a[i] > 0:
        P = P + M[1]
        N = N + M[0]
    else :
        P = P + M[0]
        N = N + M[1]

    if a[i] > 0:
        M[1] = M[1] + 1;
    else :
        M[0] = M[0] + 1


print(N , end = " ")
print(P)
