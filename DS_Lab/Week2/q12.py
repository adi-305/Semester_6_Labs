n = int(input("Enter the number of elements"))
l = []
for i in range(n):
    l.append(int(input('Enter number')))
i = 0
while(i < len(l)):
    if(l[i] < 0):
        print(l[i])
    i+=1
