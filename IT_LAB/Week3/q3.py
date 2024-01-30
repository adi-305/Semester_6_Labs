def binary_search(first,last,arr,target):
	if(first > last):
		print("Could not find the element")
		return
	mid = int((first + last) / 2)
	if(arr[mid] == target):
		print("Found the number at index = ",mid)
		return
	else:
		if(arr[mid] < target):
			binary_search(mid+1,last,arr,target)
		else:
			binary_search(first,mid-1,arr,target)


arr = [1,2,3,4,9,6,7,8]
binary_search(0,len(arr)-1,arr,5)
