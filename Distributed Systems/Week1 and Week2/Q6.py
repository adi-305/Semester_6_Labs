l = [1, 2, 3, 4]

l.append(5)
print("After appending 5:", l)

del l[4]
print("After deleting element at index 4:", l)

if 3 in l:
    print("3 is present in the list")

print("Length of the list:", len(l))

count_of_1 = l.count(1)
print("Count of 1 in the list:", count_of_1)

popped_element = l.pop()
print("Popped element:", popped_element)
print("List after popping the last element:", l)

l.insert(0, 9)
print("List after inserting 9 at index 0:", l)

l.remove(3)
print("List after removing the first occurrence of 3:", l)

l.reverse()
print("List after reversing:", l)

