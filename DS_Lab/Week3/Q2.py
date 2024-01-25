import numpy as np
a = np.array([[ 0, 1, 2, 3, 4],
[ 5, 6, 7, 8, 9],
[10, 11, 12, 13, 14]])
print("The matrix is \n",a)
print("The sum of the each column is:")
print(np.sum(a,axis=0))
print("The sum of the each row is:")
print(np.sum(a,axis=1))