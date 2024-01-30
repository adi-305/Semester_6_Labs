def subset(i , arr,string):
	if( i >= len(arr)):
		print(string)
		return

	subset(i+1, arr, string +" " + str(arr[i]))
	subset(i+1,arr,string)




arr = [4,5,6]
string = ""
subset(0,arr,string)