#Finding the area of rectangle

length = int(input('Enter the length of the Rectangle:'))
breadth  = int(input('Enter the breadth of the Rectangle:'))
if length<=0 or breadth<=0:
                     print('The dimensions were wrong')
                     exit()
print("The Area of the Rectangle is :", length*breadth)
