#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*int lengthOfLongestSubstring(string s) {
        vector<int> count(256);
        int len = 0;
        int i, j;

        for (i = 0, j = 0; i < s.length(); i++) {
            count[s[i]]++;
            while (count[s[i]] > 1) {
                len = i - j > len ? i - j : len;
                count[s[j++]] -= 1;
            }
        }

        return i - j > len ? i - j : len;
    }*/

    int lengthOfLongestSubstring(char *s) {
        vector<int> count(256);  // Frequency of characters
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

};
