
from os import read
from re import L


def reverse(s):
    str = ""
    for i in s:
        str = i + str
    return str

f1 = open('hello.txt','r')
read_content = f1.read()
f2 = open('output.txt','w')
read_content = reverse(read_content)
f2.write(read_content)
