#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* algorithm: very intrasparent. 
int lengthOfLongestSubstring(char *s)
{
    int count[256] = {0};
    int len = 0;
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++) {
        count[s[i]]++; // increase this first char counter, expanding the string
        while (count[s[i]] > 1) {                     // if last char of window becomes duplicate after the move
            len = (i - j > len) ? (i - j) : len;      // 
            count[s[j++]] -= 1;
        }
    }

    return i - j > len ? i - j : len;
} */
// simplified version
int lengthOfLongestSubstring(char *s) {
    int count[256] = {0};  // Frequency of characters
    int len = 0;           // Longest substring length
    int i = 0, j = 0;      // Sliding window pointers

    for (i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;  // Add s[i] to the window

        // If a duplicate is introduced, shrink the window
        if (count[s[i]] > 1) {
            count[s[j++]]--;  // Remove the character at s[j] and move j forward
        }

        // Update the maximum length of the valid window
        len = (i - j + 1 > len) ? (i - j + 1) : len;
    }

    return len;
}



int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }

    printf("%d\n", lengthOfLongestSubstring(argv[1]));
    return 0;
}
