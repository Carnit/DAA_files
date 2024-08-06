import random as r
from timer import Timer 
def selection_sort(arr: list[int]) -> list[int]:
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr  


def bubble_sort(arr: list[int]) -> list[int]:
    for i in range(len(arr)):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


arr1 = [r.randint(0, 100000) for i in range(10)]  
arr2 = [r.randint(0, 100000) for i in range(20)] 
arr3 = [r.randint(0, 100000) for i in range(30)] 
arr4 = [r.randint(0, 100000) for i in range(40)] 
arr5 = [r.randint(0, 100000) for i in range(50)] 
arr6 = [r.randint(0, 100000) for i in range(100)] 
arr7 = [r.randint(0, 100000) for i in range(1000)]
arr8 = [r.randint(0, 100000) for i in range(10000)]

t1= Timer()

t1.start()
bubble_sort(arr8)
t1.stop()

t2 =Timer()

t2.start()
selection_sort(arr8) 
t2.stop()
