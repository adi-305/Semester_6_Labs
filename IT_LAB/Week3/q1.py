def calculate(a,b,c):
	if a=='+':
		return b+c
	elif a=='-':
		return b-c
	elif a=='*':
		return b*c
	else:
		return b/c


a = input("Enter the operation you want to do:")
b = int(input("Enter the first number"))
c = int(input("Enter the second number"))

d = calculate(a,b,c)
print("The answer is ",d)
