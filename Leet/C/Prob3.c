#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char * s);

int main() {
    char source[] = "dvdf";
    printf("%d\n", lengthOfLongestSubstring(source));
}

int lengthOfLongestSubstring(char * s){
    int i = 0, j;
    int size = strlen(s);
    int retLength = 0;
    bool checker[256];

    while(i < size){
        memset(&checker[0],0,sizeof (checker));
        j = i;
        while (j < size && !checker[s[j]]){
            retLength = (retLength > (j - i + 1)) ? retLength : (j - i + 1); //Checks the max
            checker[s[j]] = 1;
            j++;
        }
        checker[s[i]] = 0;
        i++;
    }

    return retLength;
}