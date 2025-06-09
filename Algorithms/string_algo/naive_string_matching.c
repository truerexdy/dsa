#include <stdio.h>

int len(char s[]){
    int i = 0;
    while (s[i]!='\0')
    {
        i++;
    }
    return i;
}

int nsm(char text[], int text_size, char pat[], int pat_size){
    for(int i=0; i<text_size-pat_size; i++){
        int j = 0 ;
        while(text[i+j] == pat[j] && j<pat_size){
            j++;
        }
        if(j == pat_size){
            return i+1;
        }
    }
    return -1;
}

int main() {
    char text[128];
    char pattern[64];

    printf("Enter the Text: \n");
    scanf(" %[^\n]", text);
    printf("Enter the Pattern: \n");
    scanf(" %[^\n]", pattern);
    
    int text_size = len(text);
    int pat_size = len(pattern);
    int index = nsm(text, text_size, pattern, pat_size);
    
    if (index != -1) {
        printf("Pattern found at index: %d\n", index);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}