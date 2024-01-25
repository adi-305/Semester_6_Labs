import numpy as np

# a) Create array from list with type float
list1 = [1, 2, 3, 4, 5]
array1 = np.array(list1, dtype=float)
print("Array from list with type float: ", array1)

# b) Create array from tuple
tuple1 = (6, 7, 8, 9, 10)
array2 = np.array(tuple1)
print("Array from tuple: ", array2)

# c) Creating a 3X4 array with all zeros
array3 = np.zeros((3, 4))
print("3X4 array with all zeros: \n", array3)

# d) Create a sequence of integers from 0 to 20 with steps of 5
array4 = np.arange(0, 21, 5)
print("Sequence of integers from 0 to 20 with steps of 5: ", array4)

# e) Reshape 3X4 array to 2X2X3 array
array5 = np.zeros((3, 4))
array6 = array5.reshape(2, 2, 3)
print("3X4 array reshaped to 2X2X3 array: \n", array6)

# f) Find maximum and minimum element of array, Row wise max and min, column wise max and min and sum of elements. (Use functions max(), min(), sum())
array7 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print("Array: \n", array7)
print("Maximum element of array: ", np.max(array7))
print("Minimum element of array: ", np.min(array7))
print("Row wise max of array: ", np.max(array7, axis=1))
print("Row wise min of array: ", np.min(array7, axis=1))
print("Column wise max of array: ", np.max(array7, axis=0))
print("Column wise min of array: ", np.min(array7, axis=0))
print("Sum of elements of array: ", np.sum(array7))
