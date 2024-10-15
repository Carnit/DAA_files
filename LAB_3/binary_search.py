import sys
# Append the utils directory to sys.path
sys.path.append(r"D:\program_file\DAA_lab\DAA_files\utils")

from LAB_1.timer import Timer

def binary_serach(arr, low, high, key) -> int:
    if low > high:
        return -1

    mid = (low + high) // 2

    if arr[mid] == key:
        return mid
    elif arr[mid] > key:
        return binary_serach(arr, low, mid - 1, key)
    else:
        return binary_serach(arr, mid + 1, high, key)

def main() -> None:
    arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    size = len(arr)
    key = 50

    t = Timer()
    t.start()
    index = binary_serach(arr, 0, size - 1, key)

    if index == -1:
        print("Key not found")
    else:
        print("Key found at index", index)

    t.stop()
    print(t.elapsed())