
class solution:
	def subset(self,i , arr,string):
		if( i >= len(arr)):
			print(string)
			return
	
		subset(self,i+1, arr, string +" " + str(arr[i]))
		subset(self,i+1,arr,string)




y = solution()
arr = [4,5,6]
string = ""
subset(0,arr,string)
