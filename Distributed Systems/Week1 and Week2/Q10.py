n=int(input("How many numbers do you want to enter:"))
l=[]
for i in range(n):
    l.append(int(input()))
odd = 0
even = 0
for i in l:
    if(i % 2 == 0):
        even+=1
    else:
        odd+=1
print("Number of odd elements =", odd)
print("Number of even elements =", even)