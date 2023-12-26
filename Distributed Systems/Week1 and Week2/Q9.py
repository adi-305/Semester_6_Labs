n=int(input("How many numbers do you want to enter:"))
l=[]
for i in range(n):
    l.append(int(input()))
index = 0
while index < len(l):
    if(l[index] < 0):
        print(l[index], end=" ")
    index = index+1