import random as r
from LAB_1.timer import Timer 
def selection_sort(arr: list[int]) -> list[int]:
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr  


def bubble_sort(arr: list[int]) -> list[int]:
    counter:int = 0 
    for i in range(len(arr)):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                counter += 1
        
        if counter == 0:
            break
    return arr



def main()-> None:
    test_cases:dict = {}

    test_cases['10'] = [r.randint(0, 100000) for i in range(10)]  
    test_cases['20'] = [r.randint(0, 100000) for i in range(20)] 
    test_cases['30'] = [r.randint(0, 100000) for i in range(30)] 
    test_cases['40'] = [r.randint(0, 100000) for i in range(40)] 
    test_cases['50'] = [r.randint(0, 100000) for i in range(50)] 
    test_cases['100'] = [r.randint(0, 100000) for i in range(100)] 
    test_cases['1000'] = [r.randint(0, 100000) for i in range(1000)]
    test_cases['10000'] = [r.randint(0, 100000) for i in range(10000)]


    print('bubble sort')
    
    for key, value in test_cases.items():

        t1 = Timer()

        t1.start()
        bubble_sort(value)
        t1.stop()

        print(f'{key} : {t1.elapsed()}')

    print('')

    print('selection sort')

    for key, value in test_cases.items():

        t2 = Timer()

        t2.start()
        selection_sort(value)
        t2.stop()

        print(f'{key} : {t2.elapsed()}')


if __name__ == '__main__':
    main()