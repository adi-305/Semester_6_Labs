n=int(input("How many numbers do you want to enter:"))
l=[]
for i in range(n):
    l.append(int(input()))
for i in l:
    if(i < 0):
        print(i, end=" ")