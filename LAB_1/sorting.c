#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n)
{
    int i, j, min_index;
    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void bubble_sort(int arr[], int n)
{
    int i, j, swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to generate random numbers and fill the array
void generate_random_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; 
    }
}
int main()
{
    srand(time(0));
    int sizes[] = {10, 20, 30, 40};

    for (int k = 0; k < 4; k++)
    {
        int n = sizes[k];

        int arr1[n], arr2[n], arr3[n];
        generate_random_array(arr1, n);
        generate_random_array(arr2, n);
        generate_random_array(arr3, n);
        
        /*clock_t start_time = clock(); 
        selection_sort(arr1, n);
        clock_t end_time = clock(); 
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Selection Sort on array of size %d took %f seconds\n", n, time_taken);*/

        clock_t start_time = clock(); 
        bubble_sort(arr2, n);
        clock_t end_time = clock(); 
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Bubble Sort on array of size %d took %f seconds\n", n, time_taken);

        /* start_time = clock(); 
        insertion_sort(arr3, n);
        end_time = clock(); 
        time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Insertion Sort on array of size %d took %f seconds\n", n, time_taken);*/
    }

    return 0;
}
