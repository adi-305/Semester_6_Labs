class Solution:
    def subset(self, i, arr, string):
        if i >= len(arr):
            print(string)
            return

        self.subset(i + 1, arr, string + " " + str(arr[i]))
        self.subset(i + 1, arr, string)


y = Solution()
arr = [4, 5, 6]
string = ""
y.subset(0, arr, string)

