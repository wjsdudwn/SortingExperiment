import time
import os

def isok(arr):
    for i in range(len(arr)):
        if arr[i] != i+1:
            return False
    return True


print(os.getcwd())
f = open(os.getcwd() + "/randomArr.txt", 'r')
data = f.read().split(' ')
arr = []
for i in range(10000):
    arr.append(int(data[i]))
l = len(arr)

# bubble

print("bubble")
start = time.time()

temp = -1

for i in range(l):
    for j in range(l - 1 - i):
        if arr[j] > arr[j+1]:
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp

print(time.time() - start)

# reset array
for i in range(10000):
    arr[i] = int(data[i])

# selection

print("selection")
start = time.time()
m = arr[0]
c = 0
for i in range(l):
    m = arr[i]
    c = i
    for j in range(i+1, l):
        if m > arr[j]:
            m = arr[j]
            c = j
    temp = arr[i]
    arr[i] = arr[c]
    arr[c] = temp

print(time.time() - start)


# reset array]
for i in range(10000):
    arr[i] = int(data[i])

# insertion

print("insertion")
start = time.time()

for i in range(1, l):
        key = arr[i]  
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
            
print(time.time() - start)