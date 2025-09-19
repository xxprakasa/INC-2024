#include <stdio.h>
#include <stdlib.h>

// Fungsi compare untuk qsort
int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}

// Fungsi untuk mengecek apakah mungkin membuat N tim dengan kekuatan minimal x
int isPossible(int* arr, int N, int x, int total) 
{
    int teams = 0;
    int i = 0;
    
    // Mencoba membentuk tim dari array yang sudah disorting
    while (i <= total - 3) 
    {
        // Jika median >= x, maka tim valid
        if (arr[i + 1] >= x) 
        {
            teams++;
            i += 2;
        } 
        else 
        {
            i++;
        }
    }
    
    return teams >= N;
}

int main() 
{
    int N;
    scanf("%d", &N);
    
    int total = 3 * N;
    int arr[300000];
    
    // Input array
    for (int i = 0; i < total; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    // Sort array
    qsort(arr, total, sizeof(int), compare);
    
    // Binary search
    int left = 0;
    int right = 4000;
    int ans = 0;
    
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        
        if (isPossible(arr, N, mid, total)) 
        {
            ans = mid;
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}