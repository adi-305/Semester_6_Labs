a = int(input("Enter the number whoes factors you want to find:"))
for i in range(1,a+1):
    if(a%i == 0):
        print(i,end=' ')

