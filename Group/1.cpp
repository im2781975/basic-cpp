def linearSearch(arr, val):
    i = 0
    while i < len(arr):
        if arr[i] == val:
            return i
        i += 1
    return -1
arr = [1, 2, 7, 5, 9]
val = 5
if linearSearch(arr, val):
    print("Yes")
else:
    print("No")
###
def BinarySearch(arr, l, r, val):
    if l > r:
        return -1
    else:
        mid = (l + r)//2
        if arr[mid] == val:
            return mid
        elif val < arr[mid]:
            return BinarySearch(arr, l, mid -1, val)
        else:
            return BinarySearch(arr, mid + 1, r, val)
arr = [2, 3, 4, 7, 6]
print(BinarySearch(arr, 0, len(arr) - 1, 7))
###
def recursiveMin(arr, l, r):
    if l == r:
        return arr[l]
    else:
        mid = (l + r) //2
        return min(recursiveMin(arr, l, mid), recursiveMin(arr, mid + 1, r))
arr = [2, 3, 1, 5, 4]
print(recursiveMin(arr, 0, len(arr) - 1))
