n=int(input("How many numbers do you want to enter:"))
l=[]
for i in range(n):
    l.append(int(input()))
pos = 0
neg = 0
for i in l:
    if(i >= 0):
        pos+=1
    else:
        neg+=1
print("Number of positive elements =", pos)
print("Number of negetive elements =", neg)