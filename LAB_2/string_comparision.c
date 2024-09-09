#include <stdio.h>
#include <string.h>
#include <time.h>

#define d 256 // Number of characters in the input alphabet

// Naive Search algorithm
void naive_search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // A loop to slide pat[] one by one
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        // For current index i, check for pattern match
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
            {
                break;
            }
        }
        // If pattern matches at index i
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
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text and pattern
        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            // If p == t and all characters match
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }

        // Calculate hash value for next window of text:
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get a negative value of t, converting it to positive
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
    int q = 101; // A prime number for Rabin-Karp hashing

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
