


class finder:
	def find_index(self,target,arr,n):
		for i in range(n):
			for j in range(i,n):
				if(arr[i] + arr[j] == target):
					print("The indices are \n" + str(i) + " " + str(j))
					return

		print("Could not find any index")

arr = [10,20,10,40,50,60,70]
n = len(arr)
solution = finder()
solution.find_index(50,arr,n)
