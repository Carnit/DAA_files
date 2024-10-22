#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;

    if (arr[mid] > key)
        return binary_search(arr, low, mid - 1, key);
    return binary_search(arr, mid + 1, high, key);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int index = binary_search(arr, 0, size - 1, key);

    if (index == -1)
        printf("Key not found\n");
    else
        printf("Key found at index %d\n", index);

    return 0;
}
