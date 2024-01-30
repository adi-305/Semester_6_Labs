class solution:
	def power(self,x,n):
		a = 1
		for i  in range(n):
			a = a*x
		print(x,"^",n," = ",a)

y = solution()
y.power(5,3)
