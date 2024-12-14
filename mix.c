#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mix(const char* a, const char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    size_t min_len = (len_a < len_b) ? len_a : len_b;
    size_t result_len = len_a + len_b;
    
    // Allocate memory for the result string
    char* result = (char*)malloc((result_len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    
    // Mix characters from both strings
    size_t j = 0;
    for (size_t i = 0; i < min_len; i++) {
        result[j++] = a[i];
        result[j++] = b[i];
    }
    
    // Append remaining characters from string a
    for (size_t i = min_len; i < len_a; i++) {
        result[j++] = a[i];
    }
    
    // Append remaining characters from string b
    for (size_t i = min_len; i < len_b; i++) {
        result[j++] = b[i];
    }
    
    result[j] = '\0';  // Null terminate the string
    return result;
}

// Example usage:
int main() {
    const char* str1 = "abc";
    const char* str2 = "xyz";
    
    char* mixed = mix(str1, str2);
    if (mixed != NULL) {
        printf("%s\n", mixed);
        free(mixed);  // Don't forget to free the allocated memory
    }
    
    return 0;
}
