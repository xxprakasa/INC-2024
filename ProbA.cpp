#include <stdio.h>
#include <string.h>
#include <ctype.h>

void simplify_spelling(char* word) 
{
    int length = strlen(word);
    char result[101];
    int j = 0;

    for (int i = 0; i < length; i++) 
    {
        if (word[i] == 'c') {
            // Handle "ch" case
            if (i < length - 1 && word[i + 1] == 'h') 
            {
                result[j++] = 'c';
                i++;  // Skip the 'h'
            }
            // Handle 'c' followed by e, i, or y
            else if (i < length - 1 && (word[i + 1] == 'e' || word[i + 1] == 'i' || word[i + 1] == 'y')) 
            {
                result[j++] = 's';
            }
            // Handle 'c' followed by a, o, u or consonants
            else 
            {
                result[j++] = 'k';
            }
        } 
        else 
        {
            result[j++] = word[i];
        }
    }
    result[j] = '\0';  // Null-terminate the result
    printf("%s\n", result);
}

int main() 
{
    int N;
    scanf("%d", &N);
    char word[101];

    for (int i = 0; i < N; i++) 
    {
        scanf("%s", word);
        simplify_spelling(word);
    }

    return 0;
}
