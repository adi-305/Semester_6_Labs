a = int(input("Enter the first number:"))
b = int(input("Enter the second number:"))
c = int(input("Enter the third number:"))

if(a > b):
    if(a > c):
        print("The largest number is", a)
    else:
        print("The largest number is", c)
else:
    if(b > c):
        print("The largest number is", b)
    else:
        print("The largest number is", c)

# Shorter Code
# a = int(input("Enter the first number:"))
# b = int(input("Enter the second number:"))
# c = int(input("Enter the third number:"))

# print("The largest number is", max(a , b , c))    
