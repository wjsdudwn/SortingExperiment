import os
import time
import heapq

def quick(arr):
    if len(arr) <= 1:
        return arr
    p = arr[0]
    left, e, right = [x for x in arr if x < p], [x for x in arr if x == p], [x for x in arr if x > p]
    
    return quick(left) + e + quick(right)

def isok(arr):
    for i in range(len(arr)):
        if arr[i] != i+1:
            return False
    return True

f = open(os.getcwd() + "/LrandomArr.txt", 'r')
data = f.read().split(' ')
arr = []
for i in range(1000000):
    arr.append(int(data[i]))
l = len(arr)

# heap
print("heap")
start = time.time()
hq = arr.copy()
heapq.heapify(hq)
res = []

while len(hq) > 0:
    res.append(heapq.heappop(hq))

print(time.time() - start)

# quick

print("quick")
start = time.time()
res = quick(arr)
print(time.time() - start)

# built-in sort
print("built-in func")
start = time.time()
res = sorted(arr)
print(time.time() - start)
