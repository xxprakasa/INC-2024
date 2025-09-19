#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300005

// Function untuk menghitung jumlah swap minimum
long long countMinSwaps(int arr[], int n) 
{
    long long minSwaps = 1e18;
    
    // Coba setiap kemungkinan titik k
    for(int k = 1; k <= n; k++) 
    {
        int temp[MAX_N];
        for(int i = 0; i < n; i++) 
        {
            temp[i] = arr[i];
        }
        
        long long swaps = 0;
        
        // Sort descending untuk bagian pertama (1 to k-1)
        for(int i = 0; i < k-1; i++) 
        {
            for(int j = 0; j < k-1-i; j++) 
            {
                if(temp[j] < temp[j+1]) 
                {
                    int t = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = t;
                    swaps++;
                }
            }
        }
        
        // Sort ascending untuk bagian kedua (k to n-1)
        for(int i = k; i < n; i++) 
        {
            for(int j = k; j < n-1-(i-k); j++) 
            {
                if(temp[j] > temp[j+1]) 
                {
                    int t = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = t;
                    swaps++;
                }
            }
        }
        
        // Cek apakah susunan sudah memenuhi aturan Feng Shui
        int valid = 1;
        for(int i = 1; i < k; i++) 
        {
            if(temp[i-1] <= temp[i]) 
            {
                valid = 0;
                break;
            }
        }
        for(int i = k; i < n; i++) 
        {
            if(temp[i-1] >= temp[i]) 
            {
                valid = 0;
                break;
            }
        }
        
        if(valid && swaps < minSwaps) 
        {
            minSwaps = swaps;
        }
    }
    
    return minSwaps;
}


int main() 
{
    int n;
    scanf("%d", &n);
    
    int arr[MAX_N];
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    printf("%lld\n", countMinSwaps(arr, n));
    
    return 0;
}