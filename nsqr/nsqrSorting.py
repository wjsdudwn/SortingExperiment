import time
import os

def isok(arr):
    for i in range(len(arr)):
        if arr[i] != i+1:
            return False
    return True


print(os.getcwd())
f = open(os.getcwd() + "/COMS experiment/nsqr/randomArr.txt", 'r')
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
print(isok(arr))

# # selection

# start = time.time()



# print(result = time.time() - start)

# # insertion

# start = time.time()



# print(result = time.time() - start)