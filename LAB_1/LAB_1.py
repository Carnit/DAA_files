import random as r
from timer import Timer 
import matplotlib.pyplot as plt
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
    test_cases1:dict = {}
    test_cases2:dict = {}

    test_cases1['10'] = [r.randint(0, 100000) for i in range(10)]  
    test_cases1['20'] = [r.randint(0, 100000) for i in range(20)] 
    test_cases1['30'] = [r.randint(0, 100000) for i in range(30)] 
    test_cases1['40'] = [r.randint(0, 100000) for i in range(40)] 
    test_cases1['50'] = [r.randint(0, 100000) for i in range(50)] 
    test_cases1['100'] = [r.randint(0, 100000) for i in range(100)] 
    test_cases1['1000'] = [r.randint(0, 100000) for i in range(1000)]
    test_cases1['10000'] = [r.randint(0, 100000) for i in range(10000)]

    test_cases2['10'] = [r.randint(0, 100000) for i in range(10)]  
    test_cases2['20'] = [r.randint(0, 100000) for i in range(20)] 
    test_cases2['30'] = [r.randint(0, 100000) for i in range(30)] 
    test_cases2['40'] = [r.randint(0, 100000) for i in range(40)] 
    test_cases2['50'] = [r.randint(0, 100000) for i in range(50)] 
    test_cases2['100'] = [r.randint(0, 100000) for i in range(100)] 
    test_cases2['1000'] = [r.randint(0, 100000) for i in range(1000)]
    test_cases2['10000'] = [r.randint(0, 100000) for i in range(10000)]

    x_values = list(test_cases1.keys())
    y_values_bubble = []
    y_values_selection = []

    print('bubble sort')
    
    for key1, value1 in test_cases1.items():

        t1 = Timer()
        t1.start()
        bubble_sort(value1)
        t1.stop()

        print(f'{key1} : {t1.elapsed()}')

        y_values_bubble.append(t1.elapsed())

    print('')

    print('selection sort')

    for key2, value2 in test_cases2.items():

        t2 = Timer()
        t2.start()
        selection_sort(value2)
        t2.stop()

        
        y_values_selection.append(t2.elapsed())

        print(f'{key2} : {t2.elapsed()}')

    plt.plot(x_values, y_values_bubble, label='bubble')
    plt.plot(x_values, y_values_selection, label='selection')
    plt.xlabel('n')
    plt.ylabel('time')
    plt.title('Comparision of time taken by bubble and selection sort algo')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    main()
