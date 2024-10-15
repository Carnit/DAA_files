#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_OF_CHARS 256

// KMP Algorithm functions
void computeLPSArray(const char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int *KMPSearch(const char *pat, const char *txt, int *count)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(M * sizeof(int));
    computeLPSArray(pat, M, lps);

    int *result = (int *)malloc(N * sizeof(int));
    *count = 0;

    int i = 0;
    int j = 0;

    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            result[*count] = i - j + 1;
            (*count)++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    free(lps);
    return result;
}

// Finite Automata Algorithm functions
int getNextState(const char *pat, int M, int state, int x)
{
    if (state < M && x == pat[state])
        return state + 1;
    int ns, i;
    for (ns = state; ns > 0; ns--)
    {
        if (pat[ns - 1] == x)
        {
            for (i = 0; i < ns - 1; i++)
                if (pat[i] != pat[state - ns + 1 + i])
                    break;
            if (i == ns - 1)
                return ns;
        }
    }
    return 0;
}

void computeTF(const char *pat, int M, int TF[][NO_OF_CHARS])
{
    int state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = getNextState(pat, M, state, x);
}

void search(const char *pat, const char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int TF[M + 1][NO_OF_CHARS];
    computeTF(pat, M, TF);
    int i, state = 0;
    for (i = 0; i < N; i++)
    {
        state = TF[state][txt[i]];
        if (state == M)
            printf("\nPattern found at index %d", i - M + 1);
    }
}

int main()
{
    // Text and pattern to search for
    const char txt[] = "AABAACAADAABAAABAA";
    const char pat[] = "AABA";

    // Using the KMP algorithm
    printf("Using KMP Algorithm:\n");
    int count;
    int *result = KMPSearch(pat, txt, &count);
    printf("Pattern found at indices: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);

    // Using Finite Automata algorithm
    printf("\nUsing Finite Automata Algorithm:\n");
    search(pat, txt);
    printf("\n");

    return 0;
}
