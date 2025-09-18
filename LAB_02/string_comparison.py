import sys
import os
# Append the utils directory to sys.path
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from timer import Timer
import matplotlib.pyplot as plt

def naive_search(pattern:str, text:str) -> None:
    m = len(pattern)
    n = len(text)

    for i in range(n - m + 1):
        j = 0
        while j < m and text[i + j] == pattern[j]:
            j += 1
        
        if j == m:
            print(f"Pattern found at index {i}")

def computeLPSArray(pat:str) -> list[str]:
    M = len(pat)
    lps = [0] * M
    
    length = 0  
    i = 1

    while i < M:
        if pat[i] == pat[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps


def KMPSearch(pat:str, txt:str):
    M:int = len(pat)
    N:int  = len(txt)

    lps:list[str] = computeLPSArray(pat)
    result:list[int] = []

    i = 0 
    j = 0  
    while (N - i) >= (M - j):
        if pat[j] == txt[i]:
            j += 1
            i += 1

        if j == M:
            result.append(i - j + 1)
            j = lps[j - 1]
        elif i < N and pat[j] != txt[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return result



def main() -> None:
    naive_time:list[int] = []
    kmp_time:list[int] = []
    pattern = "AABA"
    for i in range(1, 1000):
        text = "ACAADAABAABAAABA" * i
        t1 = Timer()
        t1.start()
        naive_search(pattern, text)
        t1.stop()
        naive_time.append(t1.elapsed())

        t2 = Timer()
        t2.start()
        KMPSearch(pattern, text)
        t2.stop()
        kmp_time.append(t2.elapsed())

    plt.plot(naive_time, label='Naive Search')
    plt.plot(kmp_time, label='KMP Search')
    plt.xlabel('Number of Iterations')
    plt.ylabel('Time (seconds)')
    plt.title('Time Complexity')
    plt.legend()
    plt.show()
if __name__ == "__main__":
    main()