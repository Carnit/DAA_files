import sys
# Append the utils directory to sys.path
sys.path.append(r"D:\program_file\DAA_lab\DAA_files\utils")


import random as r
from utils.timer import Timer  # Assuming you have a Timer class (not included here)
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
    
    swapped = True 
    while swapped:
        swapped = False
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
    return arr


def insertion_sort(arr: list[int]) -> list[int]:

    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


def main():
    test_cases = {}
    for size in [10, 20, 30, 40, 50, 100, 1000, 10000]:
        test_cases[str(size)] = [r.randint(0, 100000) for _ in range(size)]

    x_values = list(test_cases.keys())
    y_values_bubble = []
    y_values_selection = []
    y_values_insertion = []

    print("Bubble Sort:")
    for size, data in test_cases.items():
        timer = Timer()
        timer.start()
        bubble_sort(data.copy())  
        timer.stop()
        print(f"{size}: {timer.elapsed()}")
        y_values_bubble.append(timer.elapsed())

    print("\nSelection Sort:")
    for size, data in test_cases.items():
        timer = Timer()
        timer.start()
        selection_sort(data.copy())  
        timer.stop()
        print(f"{size}: {timer.elapsed()}")
        y_values_selection.append(timer.elapsed())

    print("\nInsertion Sort:")
    for size, data in test_cases.items():
        timer = Timer()
        timer.start()
        insertion_sort(data.copy()) 
        timer.stop()
        print(f"{size}: {timer.elapsed()}")
        y_values_insertion.append(timer.elapsed())

    plt.plot(x_values, y_values_bubble, label="Bubble Sort")
    plt.plot(x_values, y_values_selection, label="Selection Sort")
    plt.plot(x_values, y_values_insertion, label="Insertion Sort")
    plt.xlabel("List Size (n)")
    plt.ylabel("Execution Time (seconds)")
    plt.title("Comparison of Sorting Algorithms")
    plt.legend()
    plt.show()


if __name__ == "__main__":
    main()