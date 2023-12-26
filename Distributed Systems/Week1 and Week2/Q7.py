t = (1, 3, 5, 7, 9, 2, 4, 6, 8, 10 )
n = len(t)
mid = int(n/2)
for i in range(mid):
    print(t[i],end = " ")
print("\n")
for i in range(mid,n):
    print(t[i],end = " ")