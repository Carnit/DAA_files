#include <stdio.h>
#include <string.h>
#include <time.h>
#define d 256 

//Naive search algorithm
void naive_search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == M)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}

// Rabin-Karp Search algorithm
void rabin_karp_search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;    
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

// Main function to test the algorithms
int main()
{
    char txt[] = "erxchjvkberdtfyguhiertyuiosrtvybuimojawxetcrvytb";
    char pat[] = "awxe";
    int q = 101; 
    
    // Timing Naive Search
    clock_t start_time = clock();
    printf("Naive Search:\n");
    naive_search(pat, txt);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Naive Search took %f seconds\n", time_taken);

    // Timing Rabin-Karp Search
    start_time = clock();
    printf("\nRabin-Karp Search:\n");
    rabin_karp_search(pat, txt, q);
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Rabin-Karp Search took %f seconds\n", time_taken);

    return 0;
}
